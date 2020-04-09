#include <cstdio>
#include <cstdlib>

typedef unsigned int u32;
static u32 *Cookie;

int
main(int argc, char *argv[])
{
	unsigned long *p;
	int n;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <cookie_addr> <n>\n", argv[0]);
		exit(0);
	}

	malloc(10);
	Cookie = (u32 *)strtoul(argv[1], NULL, 16);
	n = strtoul(argv[2], NULL, 10);
	srand(0);
	for (int i = 0; i < n; i++) {
		p = (unsigned long *)malloc((rand() % 10000) + 1);
		printf("%p\n", p);		// leak pointer
		printf("0x%lx\n", p[-2]);	// leak header
	}
	exit(0);
}
