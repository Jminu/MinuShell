#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void redirect(char **args)
{
	int fd;
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		// cat      a.txt      >        b.txt
		// args[0]  args[1]  args[2]    args[3]
		if (!strcmp(args[i], ">")) // cat a.txt > b.txt
		{
			fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
					0666);
			if (fd == -1)
			{
				perror("open error!");
				exit(1);
			}

			close(1);
			dup(fd);
			close(fd);
			args[i] = NULL;
			break;
		}
		else if (!strcmp(args[i], "<"))
		{
			fd = open(args[i + 1], O_RDONLY);
			if (fd == -1)
			{
				perror("open error!");
				exit(1);
			}

			close(0);
			dup(fd);
			close(fd);
			args[i] = NULL;
			break;
		}
	}
}
