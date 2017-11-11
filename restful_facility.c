#include <string.h>
#include <stdlib.h>

#include <restful_facility.h>

static size_t write_raw_data_callback(void *content,size_t actual_size,size_t mem_blocks, void* raw_data){

		printf("callback in.\n");
	 	size_t real_size = actual_size * mem_blocks;
	  raw_data_block_t *blk = (raw_data_block_t *)raw_data;
printf("after rawdata.\n");
	  blk->mem_blk = realloc(blk->mem_blk, blk->size + real_size + 1);
printf("after realloc.\n");
		if(blk->mem_blk == NULL) {
	    /* out of memory! */
	    printf("Not enough memory left for data storage!\n");
	    return 0;
	  }

	  memcpy(&(blk->mem_blk[blk->size]), content, real_size);
	  blk->size += real_size;
	  blk->mem_blk[blk->size] = 0;

	  return real_size;

}

	CURLcode open_connection(CURL *connection, char *url,raw_data_block_t *data_block){

	CURLcode result_code = CURLE_OK;

	/*	attempt to open a connection to the specified URL*/
	curl_easy_setopt(connection, CURLOPT_URL,"https://simpleexerciseforreadingjsondata-yvgbbyqpmq.now.sh/");

	/* binding the data retrieval to the callback  */
  curl_easy_setopt(connection, CURLOPT_WRITEFUNCTION, write_raw_data_callback);

  /* we pass raw_data structure to the callback function to hold the retrieved data */
  curl_easy_setopt(connection, CURLOPT_WRITEDATA, (void *)data_block);

	/* in order to support most types of servers */
	//result_code = curl_easy_setopt(connection, CURLOPT_USERAGENT, "libcurl-agent/1.0");

	return result_code;
}

CURLcode fetch_data(CURL *connection)
{
	  printf("fetch.\n");
	/* get it! */
	if(connection == NULL)
	{
		printf("null\n");
	}
	  CURLcode result = curl_easy_perform(connection);
  printf("after fetch.\n");
	  /* check for errors */
	  if(result != CURLE_OK) {
	    fprintf(stderr, "curl_easy_perform() failed: %s\n",
	            curl_easy_strerror(result));
	  }

	return result;
}

void close_connection(CURL *connection,raw_data_block_t blk){

		curl_easy_cleanup(connection);

   	free(blk.mem_blk);

   /* close libcurl */
   	curl_global_cleanup();
		printf("Connection successfully closed.\n");

}

patient_info_t get_patient_information(){

}
