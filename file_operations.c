#include "monty.h"

/**
 * open_file - Opens a file for reading
 * @file_name: Path or name of the file to be opened
 */
void open_file(char *file_name)
{
  FILE *fd = fopen(file_name, "r");

  if (file_name == NULL || fd == NULL)
    err(2, file_name);

  read_file(fd);
  fclose(fd);
}

/**
 * read_file - Reads each line from a given file
 * @fd: File descriptor of the file to be read
 */
void read_file(FILE *fd)
{
  int line_number, format = 0;
  char *buffer = NULL;
  size_t len = 0;

  for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
    {
      format = parse_line(buffer, line_number, format);
    }
  free(buffer);
}

/**
 * parse_line - Parses a line from a file to determine the operation
 * @buffer: Line extracted from the file
 * @line_number: The current line number in the file
 * @format: Format of storage (0 for stack, 1 for queue)
 * Return: 0 for stack, 1 for queue depending on the operation
 */
int parse_line(char *buffer, int line_number, int format)
{
  char *opcode, *value;
  const char *delim = "\n ";

  if (buffer == NULL)
    err(4);

  opcode = strtok(buffer, delim);
  if (opcode == NULL)
    return format;
  value = strtok(NULL, delim);

  if (strcmp(opcode, "stack") == 0)
    return 0;
  if (strcmp(opcode, "queue") == 0)
    return 1;

  find_func(opcode, value, line_number, format);
  return format;
}

/**
 * find_func - Locates and calls the function associated with an opcode
 * @opcode: Operation code to be executed
 * @value: Argument for the operation code
 * @line_number: Line number in the script
 * @format: Format of storage (0 for stack, 1 for queue)
 */
void find_func(char *opcode, char *value, int line_number, int format)
{
  int i;
  int flag;

  instruction_t func_list[] = {
			       {"push", add_to_stack},
			       {"pall", print_stack},
			       {"pint", print_top},
			       {"pop", pop_top},
			       {"nop", nop},
			       {"swap", swap_nodes},
			       {"add", add_nodes},
			       {"sub", sub_nodes},
			       {"div", div_nodes},
			       {"mul", mul_nodes},
			       {"mod", mod_nodes},
			       {"pchar", print_char},
			       {"pstr", print_str},
			       {"rotl", rotl},
			       {"rotr", rotr},
			       {NULL, NULL}
  };

  if (opcode[0] == '#')
    return;

  for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
    {
      if (strcmp(opcode, func_list[i].opcode) == 0)
	{
	  call_fun(func_list[i].f, opcode, value, line_number, format);
	  flag = 0;
	  break;
	}
    }

  if (flag == 1)
    err(3, line_number, opcode);
}

/**
 * executeFunction - Executes a specific function based on the opcode
 * @func: Function to be executed
 * @opcode: Operation code
 * @value: Value associated with the operation
 * @line_number: Line number in the script
 * @format: Format of storage (0 for stack, 1 for queue)
 */
void executeFunction(op_func func, char *opcode, char *value, int line_number, int format)
{
  stack_t *node;
  int num, isNegative = 0;

  if (strcmp(opcode, "push") == 0)
    {
      if (value == NULL)
	err(5, line_number);

      num = atoi(value);
      if (num == 0 && value[0] != '0') 
	err(5, line_number);

      node = create_node(atoi(value) * isNegative);
      if (format == 0)
	func(&node, line_number);
      else if (format == 1)
	add_to_queue(&node, line_number);
    }
  else
    {
      func(&head, line_number);
    }
}


