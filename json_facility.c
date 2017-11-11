#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <json_facility.h>

#define true 1
#define false 0

int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

patient_t* get_patients_data(const char* raw_data,jsmntok_t* tokens, int num_tokens){

	patient_t* head = (patient_t*)malloc(sizeof(patient_t));
	patient_t* current;
	int is_first_element = true;

	for(int token=0; token<num_tokens;token++)
	{
		if((tokens+token)->type == JSMN_OBJECT)	//if the next parsed element is an object type, then fill the patient info from the JSON parsed values
			{
					token++;
					int complete = false;

					if(is_first_element)
					{
						current = head;
						is_first_element = false;
					}
					else
					{
						current->next_patient = (patient_t*)malloc(sizeof(patient_t));
						current = current->next_patient;
					}

					current->next_patient = NULL;
					current->patient_info = (patient_info_t*)malloc(sizeof(patient_info_t));
					while(complete != true)
					{
						if (jsoneq(raw_data, &tokens[token], "Device") == 0)
						{

								current->patient_info->device_ID = (char*)malloc(sizeof(tokens[token+1].end-tokens[token+1].start+1));
								memcpy(current->patient_info->device_ID, &raw_data[tokens[token+1].start],tokens[token+1].end-tokens[token+1].start);
								current->patient_info->device_ID[tokens[token+1].end-tokens[token+1].start] = '\0';

						}

						if (jsoneq(raw_data, &tokens[token], "Patient") == 0)
						{
							current->patient_info->patient_ID = (char*)malloc(sizeof(tokens[token+1].end-tokens[token+1].start+1));
							memcpy(current->patient_info->patient_ID, &raw_data[tokens[token+1].start],tokens[token+1].end-tokens[token+1].start);
							current->patient_info->patient_ID[tokens[token+1].end-tokens[token+1].start] = '\0';

								 complete = true;
						}
						token++;
				}


			}
	}

	return head;
}
