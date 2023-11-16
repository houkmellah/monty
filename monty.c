#include "monty.h"

/**
 * main - entry point for MontyBytecode interpreter
 * @argc: command line arguments count.
 * @argv: command line arguments values.
 *
 * Return: 0 on success, otherwise error.
 */
int main(int argc, char **argv)
{
	FILE *file_stream = 0;
	char *line = 0;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, USAGE_ERROR);
		return (EXIT_FAILURE);
	}
	file_stream = fopen(argv[1], O_RDONLY);
	if (!file_stream)
	{
		fprintf(stderr, FILE_ERROR, argv[1]);
		return (EXIT_FAILURE);
	}


	while (getline(&line, &len, file_stream) != -1)
		printf("%s", line);
	return (EXIT_SUCCESS);
}
