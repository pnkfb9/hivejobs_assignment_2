#include <restful_facility.h>


void open_connection(CURL *connection, char* url){

	connection = curl_easy_init();	//initialization
	curl_easy_setopt(connection, CURLOPT_URL, url);

}

int close_connection(CURL *connection){

}

static size_t read_patient_data(void *contents,size_t actual_size,size_t mem_blocks, void* patient_data){
}

patient_info_t get_patient_information(){

}
