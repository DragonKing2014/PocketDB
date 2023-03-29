#include "mem_cache_page.h"

page_id_t mem_cache_get_free_page(void)
{
    return 0;
}

uint16_t *mem_cache_alloc_page(void)
{
    return 0;
}

void mem_cache_free_page(uint32_t page_id)
{
    return;
}

error_num_t mem_cache_page_insert_row(uint32_t page_id, mem_cache_buff_t mem_cache_buff, row_id_t *row_id)
{
    return 0;
}

error_num_t mem_cache_delete_row(row_id_t row_id)
{
    return 0;
}

error_num_t mem_cache_update_row(row_id_t row_id, mem_cache_buff_t mem_cache_buff)
{
    return 0;
}
