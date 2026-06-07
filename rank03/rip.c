#include <stdio.h>
#include <unistd.h>

int	check_input(char *input);
int	scan_input(char *input);

int	main(int argc, char **argv)
{
	int	val;

	if (argc != 2)
		return (1);
	if (check_input(argv[1]) == 0)
		return (1);
	val = scan_input(argv[1]);
	return (0);
}

int	check_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != '(' || input[i] != ')')
			return (0);
		i++;
	}
	return (1);
}

int	scan_input(char *input)
{
	int	val;
	int	i;

	i = 0;
	val = 0;
	while (input[i])
	{
		if (input[i] == '(')
			val += 1;
		else
			val -= 1;
		i++;
	}
	return (val);
}
