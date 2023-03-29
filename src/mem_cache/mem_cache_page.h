#include <stdint.h>
#include <stdbool.h>

#define MAX_PAGE_COUNT 1024

typedef uint32_t error_num_t;

typedef uint32_t page_id_t;

typedef struct mem_cache_page_mngr {
    void *page_list[MAX_PAGE_COUNT];
    uint32_t free_page_id;
} mem_cache_page_mngr;

typedef struct page_head {
    uint32_t page_id;
    uint32_t page_size : 31;
    uint32_t is_free : 1;
    uint32_t next_free_page_id; // free pages is a list using head insert
} page_head_t;

typedef struct row_id {
    uint32_t page_id;
    uint32_t slot_id;
} row_id_t;

typedef struct mem_cache_buff {
    uint8_t *row_buffer;
    uint32_t row_length;
} mem_cache_buff_t;

page_id_t mem_cache_get_free_page(void);

uint16_t *mem_cache_alloc_page(void);

void mem_cache_free_page(uint32_t page_id);

error_num_t mem_cache_page_insert_row(uint32_t page_id, mem_cache_buff_t mem_cache_buff, row_id_t *row_id);

error_num_t mem_cache_read_row(row_id_t row_id, mem_cache_buff_t mem_cache_buff, bool will_copy);

error_num_t mem_cache_delete_row(row_id_t row_id);

error_num_t mem_cache_update_row(row_id_t row_id, mem_cache_buff_t mem_cache_buff);

