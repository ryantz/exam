#include <unistd.h>

char to_lower(char c)
{
	if (c >= 65 && c <= 90)
		c += 32;

	return (c);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	get_index(char c)
{
	int i = 0;

	char *letters = "abcdefghijklmnopqrstuvwxz";
	while (letters[i])
	{
		if (to_lower(c) == letters[i])
			return (i);
		i++;
	}
	return (0);
}

void repeat_alpha(char *str)
{
	int	i = 0, j = 0;
	int	loop = 0;

	while (str[i])
	{
		if (is_alpha(str[i]))
		{
			j = 0;
			loop = get_index(str[i]);
			while (j < loop)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	repeat_alpha(argv[1]);
	return (0);
}
