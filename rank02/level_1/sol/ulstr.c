#include <unistd.h> 
#include <stdio.h> 

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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

void ulstr(char *str)
{
	int	i = 0;
	
	while (str[i])
	{
		if (ft_isalpha(str[i]) && ft_isupper(str[i]))
			str[i] += 32;
		else if (ft_isalpha(str[i]) && ft_islower(str[i]))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	ulstr(argv[1]);
	return (0);
}
