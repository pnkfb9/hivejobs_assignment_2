#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jsmn.h>
#include <restful_facility.h>

int main(void){

  CURL *connection_handle;
  CURLcode ret_code;
  raw_data_block_t data_block;
  char* url = "https://simpleexerciseforreadingjsondata-yvgbbyqpmq.now.sh/";  //URL from which retrieve data

  /* initialization phase for data storage memory and connection handler */
  data_block.mem_blk = (char *)malloc(1);
  data_block.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  connection_handle = curl_easy_init();

  ret_code = open_connection(connection_handle,url, &data_block);

  if(ret_code != CURLE_OK)
  {
    printf("Unable to create a connection to the specified URL!\n");
  }
  else
  {
    printf("Connection established.\n");
  }

  ret_code = fetch_data(connection_handle);

  if(ret_code == CURLE_OK)
  {

    printf("block content:%s\n",data_block.mem_blk);
  }


  close_connection(connection_handle,data_block);

  return 0;
}
