#include <stdio.h>
struct stu
{
	int x;
	int *y;
} *p;
int dt[4] = {10, 20, 30, 40};
struct stu a[4] = {50, &dt[0], 60, &dt[1], 70, &dt[2], 80, &dt[3]};

int main()
{
	p = a;
	printf("%d,", ++p->x);
	printf("%d,", (++p)->x);
	printf("%d\n", ++(*p->y));
	return 0;
}


