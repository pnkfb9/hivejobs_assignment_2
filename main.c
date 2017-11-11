#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jsmn.h>

#include <restful_facility.h>
#include <json_facility.h>

#define MAX_JSON_TOKENS 32

int main(void){

  CURL *connection_handle;
  CURLcode ret_code;
  jsmn_parser parser;
  raw_data_block_t data_block;
  char* url = "https://simpleexerciseforreadingjsondata-yvgbbyqpmq.now.sh/";  //URL from which retrieve data

  /* variables used for json parsing */
  const char *js;
  int num_tokens;
  jsmntok_t tokens[MAX_JSON_TOKENS];

  /* initialization phase for data storage memory and connection handler */
  data_block.mem_blk = (char *)malloc(1);
  data_block.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  connection_handle = curl_easy_init();
  jsmn_init(&parser);

  ret_code = open_connection(connection_handle,url, &data_block);

  if(ret_code != CURLE_OK)
  {
    printf("Unable to create a connection to the specified URL!\n");
    return 0;
  }

  ret_code = fetch_data(connection_handle);

  if(ret_code == CURLE_OK)
  {
    js = (const char*)data_block.mem_blk;
    num_tokens = jsmn_parse(&parser, js, strlen(js), tokens, MAX_JSON_TOKENS);

    if(num_tokens != JSMN_ERROR_INVAL || num_tokens!= JSMN_ERROR_NOMEM || num_tokens != JSMN_ERROR_PART )
    {

      patient_t* patient =get_patients_data((const char*)data_block.mem_blk,tokens,num_tokens);

      while(patient != NULL)
      {
        printf("Device result: %s\nPatient result: %s\n",patient->patient_info->device_ID,patient->patient_info->patient_ID);
        patient = patient->next_patient;

      }
    }
  }
  else
  {
        printf("Error in retrieving JSON object, leaving. \n");
        return 0;
  }


  close_connection(connection_handle,data_block);

  return 0;
}
