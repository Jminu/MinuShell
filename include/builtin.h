#ifndef BUILTIN_H
#define BUILTIN_H

typedef struct
{
	char *func_name;
	void (*func)(char **args);
} BUILTIN_CMD;

void cd(char **args);
void pwd(char **args);

extern BUILTIN_CMD builtin_cmd[];

#endif
