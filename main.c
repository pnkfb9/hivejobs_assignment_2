#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jsmn.h>
#include <json_facility.h>
#include <restful_facility.h>

int main(void){

  CURL *connection_handle;
  CURLcode ret_code;
  jsmn_parser parser;
  raw_data_block_t data_block;
  char* url = "https://simpleexerciseforreadingjsondata-yvgbbyqpmq.now.sh/";  //URL from which retrieve data

  /* initialization phase for data storage memory and connection handler */
  data_block.mem_blk = (char *)malloc(1);
  data_block.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  connection_handle = curl_easy_init();
  jsmn_init(&parser);
  jsmntok_t tokens[256];
  const char *js;
  int r;



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
    r = jsmn_parse(&parser, js, strlen(js), tokens, 256);

    if(r != JSMN_ERROR_INVAL || r != JSMN_ERROR_NOMEM || r != JSMN_ERROR_PART )
    {
        for (int i = 1; i < r; i++)
        {
		        if (jsoneq((const char*)data_block.mem_blk, &tokens[i], "Device") == 0)
            {
			           printf("Device result: %.*s\n", tokens[i+1].end-tokens[i+1].start, (const char*)data_block.mem_blk + tokens[i+1].start);
                 i++;
            }

            if (jsoneq((const char*)data_block.mem_blk, &tokens[i], "Patient") == 0)
            {
			           printf("Patient result: %.*s\n", tokens[i+1].end-tokens[i+1].start, (const char*)data_block.mem_blk + tokens[i+1].start);
                 i++;
            }
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
