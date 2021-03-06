
#include <unistd.h>

void mem_init(void);
void *heap_sbrk(int incr);

void mem_deinit(void);
void mem_reset_brk(void);
void *mem_heap_lo(void);
void *mem_heap_hi(void);
void *getmem_brk(void);
size_t mem_heapsize(void);
size_t mem_pagesize(void);
size_t getSizeOfHeap(void);