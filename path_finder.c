#include "shell.h"

/**
 * path_finder - Finds the full path of a command in the PATH environment.
 * @cmd: The command to find.
 * @work_buffer: Buffer to store the full path.
 * Return: EXIT_SUCCESS if the command is found, EXIT_FAILURE otherwise.
 */
int path_finder(char *cmd, char *work_buffer)
{
	char *token, *var_path;
	char *var_value_path = _getenv("PATH");

	if ((cmd[0] == '/' || strncmp(cmd, "./", 2) == 0 ||
				strncmp(cmd, "../", 3) == 0) &&
			file_checker(cmd) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);

	if (!var_value_path || !*var_value_path)
		return (EXIT_FAILURE);

	var_path = strdup(var_value_path);
	if (!var_path)
		return (EXIT_FAILURE);

	for (token = strtok(var_path, ":"); token; token = strtok(NULL, ":"))
	{
		if (sprintf(work_buffer, "%s/%s", token, cmd) < 0)
		{
			free(var_path);
			return (EXIT_FAILURE);
		}

		if (file_checker(work_buffer) == EXIT_SUCCESS)
		{
			free(var_path);
			return (EXIT_SUCCESS);
		}
	}

	free(var_path);
	return (EXIT_FAILURE);
}
