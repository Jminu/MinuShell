#ifndef BUILTIN_H
#define BUILTIN_H

typedef struct
{
	char *func_name;
	void (*func)(char **args);
} BUILTIN_CMD;

void cd_cmd(char **args);
void pwd_cmd(char **args);
void exit_cmd(char **args);

extern BUILTIN_CMD builtin_cmd[];

#endif
