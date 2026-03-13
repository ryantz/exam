#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	process_num(char *str)
{
	int	i = 0;
	int	res = 0;
	
	if (str[i] == '-' && str[i + 1] == '-')
		return (0);
	res = atoi(str);
	return (res);
}

int	main(int argc, char **argv)
{
	int	num1, num2;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	num1 = process_num(argv[1]);
	num2 = process_num(argv[3]);
	if (num1 != 0 && num2 != 0)
	{
		if (argv[2][0] == '-')
			printf("%d\n", num1 - num2);
		else if (argv[2][0] == '+')
			printf("%d\n", num1 + num2);
		else if (argv[2][0] == '*')
			printf("%d\n", num1 * num2);
		else if (argv[2][0] == '/')
			printf("%d\n", num1 / num2);
		else if (argv[2][0] == '%')
			printf("%d\n", num1 % num2);
	}
	return (0);
}
