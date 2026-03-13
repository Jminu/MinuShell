#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "builtin.h"

#define MAX_PATH 1024

void cd(char **args)
{
	char pwd[MAX_PATH];
	getcwd(pwd, MAX_PATH);

	if (!strcmp(args[1], ".."))
		chdir("..");
	else
	{
		strcat(pwd, "/");
		strcat(pwd, args[1]);
		chdir(pwd);
	}
}

void pwd(char **args)
{
	char pwd[MAX_PATH];

	if (getcwd(pwd, MAX_PATH) != NULL)
		puts(pwd);
}

BUILTIN_CMD builtin_cmd[] = {
	{"cd", cd},
	{"pwd", pwd},
	{NULL, NULL}
};
