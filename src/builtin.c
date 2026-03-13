#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "builtin.h"

#define MAX_PATH 1024

void cd_cmd(char **args)
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

void pwd_cmd(char **args)
{
	char pwd[MAX_PATH];

	if (getcwd(pwd, MAX_PATH) != NULL)
		puts(pwd);
}

void exit_cmd(char **args)
{
	exit(0);
}

BUILTIN_CMD builtin_cmd[] = {
	{"cd", cd_cmd},
	{"pwd", pwd_cmd},
	{"exit", exit_cmd},
	{NULL, NULL}
};
