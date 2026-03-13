int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

int	power_ten(int power, int val)
{
	int i = 0;

	while (i < power)
	{
		val *= 10;
		i++;
	}
	return (val);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	start = 0;
	int	neg = 0;
	int	pos = 0;
	int res = 0;
	int	pow;

	if (!str)
		return (0);
	if (str[start] == '+')
	{
		start++;
		pos++;
		if (!ft_isnum(str[start]))
			return (0);
	}
	else if (str[start] == '-')
	{
		neg++;
		start++;
		if (!ft_isnum(str[start]))
			return (0);
	}
	pow = ft_strlen(str) - 1;
	if (neg || pos)
		pow -= 1;
	while (str[start])
	{
		if (ft_isnum(str[start]) == 0)
			return (0);
		res += power_ten(pow, str[start] - 48);
		start++;
		pow--;
	}
	if (neg)
		res *= -1;
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	int	num1, num2;

	num1 = ft_atoi("+1234");
	num2 = atoi("+1234");
	printf("%d\n", num1);
	printf("%d\n", num2);
}
