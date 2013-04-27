#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
char *cur_command;

int main(void)
{
	cur_command = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	*cur_command = 0;

	//while (strcmp(cur_command, "exit"))
	//{
	//	fgets(cur_command, MAX_COMMAND_LENGTH, stdin);
	//}

	fgets(cur_command, MAX_COMMAND_LENGTH, stdin);

	free(cur_cofgets cmmand);
	return 0;
}

char *extract_command(char * input_str)
{

}