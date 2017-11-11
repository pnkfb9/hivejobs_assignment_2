#include <curl/curl.h>

typedef struct raw_data_block_t{

  char* mem_blk;
   size_t size;

}raw_data_block_t;

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

CURLcode open_connection(CURL *connection, char* url, raw_data_block_t *data_block);

CURLcode fetch_data(CURL *connection);

void close_connection(CURL *connection, raw_data_block_t blk);

static size_t read_patient_data(void *contents,size_t actual_size,size_t mem_blocks, void* patient_data);

patient_info_t get_patient_information();
