#include "main.h"
/**
 * execute_cmd - handles the execution of the commands passed with args
 * @args: array of command with arguments to run it with
 *
 * Return: 1(success) 0(failure)
 */

int execute_cmd(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	return (1);
}
