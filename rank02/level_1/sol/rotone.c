#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	rotone(char c)
{
	if (ft_isalpha(c))
	{
		c -= 1;
		if ((ft_isupper(c + 1) && c < 65) || (ft_islower(c + 1) && c < 97))
			c += 26;
	}
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc != 2)
		return (1);
	while (argv[1][i])
	{
		rotone(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
