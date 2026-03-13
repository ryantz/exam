#include <unistd.h>

void	ft_putstr(int c)
{
	long lc;
	char cc;
	lc = c;
	if (lc >= 0 && lc <=9)
	{
		cc = lc + '0';
		write(1, &cc, 1);
	}
	else
	{
		ft_putstr(lc / 10);
		ft_putstr(lc % 10);
	}
}

int	main(void)
{
	int	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putstr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
