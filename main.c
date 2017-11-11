#include <curl/curl.h>
#include <stdio.h>

#include <restful_facility.h>

int main(void){

  CURL *connection_handle;
  char url[] = "https://simpleexerciseforreadingjsondata-yvgbbyqpmq.npw.sh";  //URL from which retrieve data
  int return_code = 0;

  curl_global_init(CURL_GLOBAL_ALL);  //global curl initialization

  return_code = open_connection(connection_handle,url); //opening connection fo the specific URL

  return 0;
}
