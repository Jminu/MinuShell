#include <string.h>
#include <stdio.h>

#define SEPERATOR " "
#define MAX_LINE 1024
#define MAX_ARGS 64

void parse_line(char *line, char **args)
{
	char *p;
	int position = 0;

	p = strtok(line, SEPERATOR);
	while (p != NULL)
	{
		args[position] = p;
		position++;
		p = strtok(NULL, " ");
	}
	args[position] = NULL;
}

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


