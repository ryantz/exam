#include <unistd.h>

void	search_replace(char *ori, char *str1, char *str2)
{
	int	i = 0;
	while (ori[i])
	{
		if (ori[i] == str1[0])
			write(1, &str2[0], 1);
		else
			write(1, &ori[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (argv[2][1] || argv[3][1])
	{
		write(1, "\n", 1);
		return (1);
	}
	search_replace(argv[1], argv[2], argv[3]);
	return (0);
}
