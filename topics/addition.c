/* Fig 2.5: addition.c
 * Addition program */

#include <stdio.h>

int main(void)
{
	int integer1;
	int integer2;
	int sum;

	printf("Enter First Integer\n ");
	scanf("%d", &integer1);

	printf("Enter Second Integer\n ");
	scanf("%d", &integer2);

	sum = integer1 + integer2;

	printf("Sum is %d\n", sum);

	return 0;
};
