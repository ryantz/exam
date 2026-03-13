#include <unistd.h>

int remove_leading_space(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			break;
	}
	return (i);
}

int	ft_is_printable(char c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

void print_first(char *str)
{
	int start;
	start = remove_leading_space(str);
	while (str[start])
	{
		if (ft_is_printable(str[start]))
			write(1, &str[start], 1);
		start++;
		if (str[start] == ' ' || str[start] == '\t')
		{
			write(1, "\n", 1);
			break;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
		print_first(argv[1]);
	return (0);
}
