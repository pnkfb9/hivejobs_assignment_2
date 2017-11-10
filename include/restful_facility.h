#include <curl/curl.h>

/*  structure definition to hold single patient information  */
typedef struct patient_info_t{

  int patient_ID;
  char* device_ID;

}patient_info_t;

/*  structure definition to hold patients */
typedef struct patients_list{

  patient_info_t patient_info;
  struct patients_list *next_patient;

}patients_list;

int open_connection(CURL *connection, char* url);
int close_connection(CURL *connection);

static size_t read_patient_data(void *contents,size_t actual_size,size_t mem_blocks, void* patient_data);

patient_info_t get_patient_information();
