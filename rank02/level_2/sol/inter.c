#include <unistd.h>
#include <stdio.h>

// not working because its comparing to itself too
int	ret_str2_index(char *str1, char *str2, char c)
{
	int	i = 0;
	while (str1[i])
	{
		if (c == str1[i])
			return (i);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	index;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (argv[1][i])
	{
		index = ret_str2_index(argv[1], argv[2], argv[1][i]);
		printf("index: %d\n", index);
		if (i == index)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		index = ret_str2_index(argv[1], argv[2], argv[2][i]);
		printf("index: %d\n", index);
		if (i == index)
			write(1, &argv[2][i], 1);
		i++;
	} 
	return (0);
}
