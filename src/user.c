/* user.c */

#include <stdio.h> /* FILE sprintf fopen fwrite fclose */
#include <string.h> /* strcpy strcat */

#define USER_NAME_LENGTH_MAX 20

struct user { int id; };

FILE* user_create(const char* name)
{
	FILE* fp;
	struct user newUser;
	char path[80];

	sprintf(path, "cw_users/%s", name);

	fp = fopen(path, "wb");
	fwrite(&newUser, sizeof (struct user), 1, fp);

	return fp;
}
