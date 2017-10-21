/* name.c */

#include <stdio.h> /* fprintf */
#include <string.h> /* strcmp */
#include <malloc.h> /* malloc, realloc */
#include <assert.h> /* assert */
#include <ctype.h> /* isalpha */

#define NAME_SIZE_MAX 20

static char** name_list;
static unsigned int name_count;

static char* name_create(const char* name)
{
	char* newName = malloc(sizeof (char) * NAME_SIZE_MAX +1);
	assert(newName);

	memset(newName, '\0', NAME_SIZE_MAX +1);
	memcpy(newName, name, NAME_SIZE_MAX); /* truncates longer than max */

	name_list = realloc(name_list, (name_count +1) * sizeof (char*));
	assert(name_list);
	name_list[name_count] = newName;

	return name_list[name_count++];
}

static int name_check(const char* name)
{
	unsigned int i;
	if ( !name )
	{
		fprintf(stderr, "name cannot be null\n");
		return -1;
	}

	if ( !strcmp(name, "") )
	{
		fprintf(stderr, "name cannot be blank\n");
		return -2;
	}

	for ( i=0; i<strlen(name); i++ )
		if ( !isalpha(name[i]) )
		{
			fprintf(stderr, "name contains illegal chars\n");
			return -3;
		}
	return 0; /* name is ok to use */
}

int name_delete(const char* name)
{
	unsigned int i;
	for ( i=0; i<name_count; i++ )
		if ( !strcmp(name, name_list[i]) )
		{
			free(name_list[i]);
			for ( ; i<name_count-1; i++ )
				name_list[i] = name_list[i+1];
			name_count--;
			return 0; /* list collapsed over name */
		}
	fprintf(stderr, "cannot delete; no such name\n");
	return -1;
}

char* name_new(const char* name)
{
	char* newName = name_create(name);
	if ( name_check(newName) ) 
	{
		fprintf(stderr, "cannot use the name '%s'\n", newName);
		name_delete(newName);
		return NULL;
	}
	return newName; /* stored in name_list */
}
