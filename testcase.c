#include <stdio.h>
#include "valloc.h"

int main()
{
  InitAlloc();

  void *a, *b, *c, *d, *e, *f;

  a = VirtualAlloc(12);
  b = VirtualAlloc(17);
  c = VirtualAlloc(18);
  d = VirtualAlloc(4);
  VirtualFree(b);
  VirtualFree(c);
  e = VirtualAlloc(17);
  f = VirtualAlloc(18);

  printf("%p %p %p %p %p %p\n", a, b, c, d, e, f);
  system("pause");
  return 0;
}
