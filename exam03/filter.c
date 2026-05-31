#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int	collect_line(int fd, char *buffer, char **entire_input);
char	*filter(char **entire_string, char *pattern);

int	main(int argc, char **argv)
{
	int		fd;
	char	*entire_input;
	char	*buffer;
	char	*pattern;

	if (argc != 2)
	{
		perror("Error: not enough args");
		return (1);
	}
	pattern = argv[1];
	fd = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = 0;
	collect_line(fd, buffer, &entire_input);
	filter(&entire_input, pattern);
	printf("%s\n", entire_input);
	free(entire_input);
	return (0);
}

// define buffer and add into large buffer till \n
int	collect_line(int fd, char *buffer, char **entire_input)
{
	ssize_t	bytes_read;
	size_t		total;
	char	*tmp;
	size_t		i;

	total = 0;
	*entire_input = malloc(1 * sizeof(char));
	if (!*entire_input)
		return (0);
	(*entire_input)[0] = '\0';
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(*entire_input, total + bytes_read + 1);
		if (!tmp)
		{
			free(*entire_input);
			return (0);
		}
		*entire_input = tmp;
		i = 0;
		while (i < (size_t)bytes_read)
		{
			(*entire_input)[total + i] = buffer[i];
			i++;
		}
		total += bytes_read;
		(*entire_input)[total] = '\0';
	}
	return (1);
}

char	*filter(char **entire_string, char *pattern)
{
	size_t	i;
	size_t	j;
	char	*replace;

	i = 0;
	replace = malloc(strlen(pattern) + 1 * sizeof(char));
	if (!replace)
		return (NULL);
	replace[strlen(pattern)] = '\0';
	while (i < strlen(pattern))
	{
		replace[i] = '*';
		i++;
	}
	i = 0;
	while ((*entire_string)[i])
	{
		j = 0;
		while (pattern[j])
		{
			if ((*entire_string)[i + j] == pattern[j])
				j++;
			else
				break;
		}
		if (j == strlen(pattern))
			memmove(*entire_string + i, replace, strlen(pattern));
		i++;
	}
	free(replace);
	return (*entire_string);
}
