#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "executor.h"
#include "builtin.h"

#define MAX_PATH 1024

void executor(char **args)
{
	pid_t pid;
	int i;

	for (i = 0; builtin_cmd[i].func_name != NULL; i++)
	{
		if (!strcmp(builtin_cmd[i].func_name, args[0]))
		{
			builtin_cmd[i].func(args);
			return;
		}
	}

	pid = fork();
	if (pid == 0)
	{
		redirect(args);
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error\n");
			exit(1);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		perror("fork error!\n");
		exit(1);
	}
}
