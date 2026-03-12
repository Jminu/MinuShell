#include <string.h>
#include <stdio.h>
#include "parser.h"

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
