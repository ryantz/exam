#include <unistd.h>

int	ret_str1_index(char *str1, char c)
{
	int i = 0;

	while (str1[i])
	{
		if (c == str1[i])
			return (i);
		i++;
	}
	return (0);
}

int	ret_str2_index(char *str1, char *str2, char c)
{
	int i = 0;
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
	return (0);
}

int	main(int argc, char **argv)
{
	int i = 0;
	int first_app;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	// first string
	while (argv[1][i])
	{
		first_app = ret_str1_index(argv[1], argv[1][i]);
		if (first_app == i)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		first_app = ret_str2_index(argv[1], argv[2], argv[2][i]);
		if (first_app == i)
			write(1, &argv[2][i], 1);
		i++;
	}
	return (0);
}
