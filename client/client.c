#include <stdio.h>
#include "../lib/dummy.h"

int
main(int argc, char **argv)
{
	printf("client main: HELLO\n");
	dummy_hello();
	printf("client main: GOODBYE\n");
	return 0;
}

