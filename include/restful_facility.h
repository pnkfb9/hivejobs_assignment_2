#include <curl/curl.h>


typedef struct raw_data_block_t{

  char* mem_blk;
   size_t size;

}raw_data_block_t;

CURLcode open_connection(CURL *connection, char* url, raw_data_block_t *data_block);

CURLcode fetch_data(CURL *connection);

void close_connection(CURL *connection, raw_data_block_t blk);

static size_t write_raw_data_callback(void *content,size_t actual_size,size_t mem_blocks, void* raw_data);
