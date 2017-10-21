/* test.c */

#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <assert.h> /* assert */
#include <string.h> /* strcmp */

static unsigned int test_count;

void test_test()
{
	assert(1);
	test_count++;
}

#include "name.h"

void test_name_new()
{
	char* name = "Newname";
	assert(strcmp(name, name_new(name)) == 0); /* same name */
	test_count++;

	name_delete(name);
}

void test_name_delete()
{
	char* name = "Deletename";
	name_new(name);
	assert(name_delete(name) == 0); /* delete successful */
	test_count++;

	assert(name_delete(name) == -1); /* no such name */
	test_count++;
}

void test_all()
{
	test_test();
	test_name_new();
	test_name_delete();
}

int main()
{
	printf("testing...\n\n");
	test_all();
	printf("\n\tall of %d tests passed\n", test_count);
	return 0;
}
