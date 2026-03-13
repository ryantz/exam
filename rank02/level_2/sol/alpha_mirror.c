#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	ft_index2(char c)
{
	int	i = 0;
	//26
	char *range = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (range[i])
	{
		if (c == range[i])
			write(1, &range[25 - i], 1);
		i++;
	}
}

void	ft_index1(char c)
{
	int	i = 0;
	//26
	char *range = "abcdefghijklmnopqrstuvwxyz";

	while (range[i])
	{
		if (c == range[i])
			write(1, &range[25 - i], 1);
		i++;
	}
}

void alpha_mirror(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (ft_isalpha(str[i]) && ft_islower(str[i]))
			ft_index1(str[i]);
		else if (ft_isalpha(str[i]) && ft_isupper(str[i]))
			ft_index2(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	alpha_mirror(argv[1]);
	return (0);
}
