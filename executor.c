#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void executor(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("%s\n", args[0]);
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
