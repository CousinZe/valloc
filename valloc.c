#include "valloc.h"
#include <stdlib.h>
#include <assert.h>
#define MAX_ALLOC 127

static unsigned char __alloc_buf[PAGE_SIZE];

static unsigned char *AllocBuf(size_t _index)
{
  return __alloc_buf + _index;
}

void InitAlloc(void)
{
  for (unsigned char *it = AllocBuf(0);
       it != AllocBuf(PAGE_SIZE);
       ++it)
    {
      *it = 0;
    }
}

void *VirtualAlloc(size_t _size)
{
  assert(_size < MAX_ALLOC);

  for (unsigned char *it = AllocBuf(0);
       it != AllocBuf(PAGE_SIZE);)
    {
      unsigned char alloc_info =  *it;

      if (alloc_info >= 128)
        {
          alloc_info -= 128;
          assert(alloc_info != 0);

          it += alloc_info + 1;
        }
      else if (alloc_info == 0)
        {
          *it += 128;
          *it += _size;
          return it+1;
        }
      else
        {
          if (alloc_info >= _size)
            {
              *it += 128;
              return it+1;
            }
          else
            {
              it += alloc_info + 1;
            }
        }
    }

  return NULL;
}

void VirtualFree(void *_ptr)
{
  assert((unsigned char*)_ptr >= AllocBuf(1) 
	     && (unsigned char*)_ptr < AllocBuf(PAGE_SIZE));

  unsigned char *ptr = (unsigned char*)_ptr;
  *(ptr-1) -= 128;
}
