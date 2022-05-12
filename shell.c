#include "main.h"

/**
 * convert_str_to_arr - function to convert string to array
 * @str: string to be converted
 *
 * Return: array of string
 */

char **convert_str_to_arr(char *str)
{
	char *token, **arr;
	char *delim = " :'\n''\t''\a'";
	size_t length = strlen(str) * 8;
	int count = 0;

	arr = malloc(sizeof(char *) * length);

	token = strtok(str, delim);
	while (token != NULL)
	{
	       	arr[count] = strdup(token);
		token = strtok(NULL, delim);
		count++;
	}
	arr[count] = NULL;

	return (arr);
}

/**
 * print_prompt - print the prompt message to terminal
 *
 */
void print_prompt(void)
{
	_print("#cisfun$ ");
}

/**
 * main - main implementation of the shell
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 or 1
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *buffer = NULL, **args;
	size_t buffsize = 0;
	int line_count, status = 1;

	/**
	 * The signal function receives CTRL+C and ignores
	 * it. The SIG_IGN(ignore) param can be replaced with a void
	 * pointer to a function, accepting param of "int signum".
	 */
	signal(SIGINT, SIG_IGN);
	while (status)
	{
		buffer = malloc(buffsize * sizeof(char *));

		if (buffer == NULL)
		{
			free(buffer);
			_print("Unable to allocate memory");
			exit(EXIT_FAILURE);
		}

		if (isatty(STDIN_FILENO))
			print_prompt();
		line_count = getline(&buffer, &buffsize, stdin);

		if (line_count == -1)
		{
			status = 0;
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if (*buffer == '\n')
		{
			free(buffer);
			continue;
		}

		args = convert_str_to_arr(buffer);
		status = execute_cmd(args);
		free(buffer);
		free(args);
	}

	return (0);
}
