# valloc
Virtual Alloc function for a strange MCU

These days one of my friends is developing a small program on a strange MCU, on which malloc() could only allocate 256 bytes. However, creating an static array of size 4096 or more is possible.

So I wrote this "library" for him. This library hold a static array of size 4096, and get a "block" from the array when client calls VirtualAlloc

# functions

void InitAlloc(void) : initializes the allocating system

void\* VirtualAlloc(size\_t) : "allocate" memory according to demanded size. If client demanded more than 127 bytes, an assertion failed will be reported. If there's no enough memory left, returns NULL.

void VirtualFree(void\*) : "recycle" memory. If the pointer does not come from our array, an assertion failed will be reported.
