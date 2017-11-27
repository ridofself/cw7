/* test.c */

#include <stdio.h> /* printf */
#include <string.h> /* strcmp */
#include <assert.h> /* assert */
#include <malloc.h> /* malloc */

static unsigned int test_count;

void test_test()
{
	assert(1);
	test_count++;
}

#include "user.h"

void test_user_create()
{
 	user_create("Testington");
	test_count++;
}

void test_all()
{
	test_test();
	test_user_create();
}

int main()
{
	printf("testing...\n\n");
	test_all();
	printf("\n\tall of %d tests passed\n", test_count);
	return 0;
}
