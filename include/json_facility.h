#include <jsmn.h>


/*  structure definition to hold single patient information  */
typedef struct patient_info_t{

   char* patient_ID;
   char* device_ID;

}patient_info_t;

/*  structure definition to hold patients */
typedef struct patient_t{

  patient_info_t* patient_info;
  struct patient_t *next_patient;

}patient_t;

int jsoneq(const char *json, jsmntok_t *tok, const char *s);

patient_t* get_patients_data(const char* raw_data,jsmntok_t tokens[32], int num_tokens);
