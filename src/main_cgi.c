/* main_cgi.c */

#include <stdio.h>
#include <stdlib.h>
#include "user.h"

int main(void)
{
	char *data;
	printf("Content-Type: text/plain;charset=us-ascii\n\n");
	data = getenv("QUERY_STRING");
	if ( data == NULL ) printf("<p>null input</p>\n\n");
	else printf("you done sent: %s\n\n", data);
	user_create(data);
	return 0;
}
