#ifndef __VALLOC_H
#define __VALLOC_H

#include <stdlib.h>
#define PAGE_SIZE 4096

void InitAlloc(void);
void *VirtualAlloc(size_t size);
void VirtualFree(void *_ptr);

#endif
