#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

#define MAX_LINE 1024
#define MAX_ARGS 64

int main()
{
	char line[MAX_LINE];
	char *args[MAX_ARGS];

	while (1)
	{
		printf("MinuShell> ");
		fflush(stdout);
		fgets(line, MAX_LINE, stdin);
		line[strlen(line) - 1] = NULL;
		parse_line(line, args);
		executor(args);
	}
	return 0;
}
