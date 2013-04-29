#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "../Singly_linked_list/singly_linked_list.h"

#define MAX_INPUT_LEN 200
#define PROMPT ">>> "

extern char **environ;

void parse_input(char *input_str);

char *user_input,
	 *cur_command,
	 *arguments;

int main(void)
{
	user_input = malloc(sizeof(char) * MAX_INPUT_LEN);
	cur_command = malloc(sizeof(char) * MAX_INPUT_LEN);
	arguments = malloc(sizeof(char) * MAX_INPUT_LEN);

	*user_input = *cur_command = *arguments = 0;

	do
	{
		printf(/*"\n%s",*/PROMPT);
		user_input = fgets(user_input, MAX_INPUT_LEN, stdin);
		parse_input(user_input);

		if (strcmp(cur_command, "exit"))
		{
			system(user_input);
		}
	}
	while (strcmp(cur_command, "exit"));

	free(user_input);
	free(cur_command);
	free(arguments);
	return 0;
}

void parse_input(char * input_str)
{
	assert(input_str);
	char *result;
	int j;

	*(input_str + strlen(input_str) - 1) = 0;
	result = strchr(input_str, ' ');

	*arguments = 0;
	if (result)
	{
		strncpy(cur_command, input_str, result - input_str);
		*(cur_command + (result - input_str)) = 0;

		while (result < input_str + strlen(input_str) && (*result == ' ' || *result == '\t')) result++;

		j = 0;
		while (result < input_str + strlen(input_str))
		{
			*(arguments + j) = *result;
			j++;
			result++;
		}
		*(arguments + j + 1) = 0;
	}
	else
	{
		strcpy(cur_command, input_str);
	}

	//printf("Command: %s\n", cur_command);
	//printf("Arguments: %s\n", arguments);
}