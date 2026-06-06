#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**init_grid(char ***grid, int n);
char	**init_and_increment_result(char ***result, int n);
char 	**solve(char ***result, char **grid, int row, int n);
int		is_valid(char **grid, int row, int col, int n);
void	parse_grid_to_result(char **grid, char ***result, int n);
void	print_arr(char **arr, int n);
size_t	ft_strlen(char *str);
size_t	ft_arrlen(char **arr);
void	free_all(char **arr);

int	main(int argc, char **argv)
{
	int		n;
	char	**grid;
	char	**result;

	if (argc != 2)
	{
		perror("Wrong arg count");
		return (1);
	}
	result = NULL;
	n = atoi(argv[1]);
	init_grid(&grid, n);
	solve(&result, grid, 0, n);
	free_all(grid);
	print_arr(result, n);
	free_all(result);
	return (0);
}

char	**init_grid(char ***grid, int n)
{
	int	i;
	int	j;

	*grid = malloc((n + 1) * sizeof(char *));
	if (!*grid)
		return (NULL);
	(*grid)[n] = NULL;
	i = 0;
	while (i < n)
	{
		(*grid)[i] = malloc((n + 1) * sizeof(char));
		if (!(*grid)[i])
		{
			free_all(*grid);
			return (NULL);
		}
		(*grid)[i][n] = 0;
		j = 0;
		while (j < n)
		{
			(*grid)[i][j] = '.';
			j++;
		}
		i++;
	}
	return (*grid);
}

char	**init_and_increment_result(char ***result, int n)
{
	char	**tmp;
	size_t	len;

	len = ft_arrlen(*result);
	if (len == 0)
	{
		*result = malloc((1 + 1) * sizeof(char *));
		if (!*result)
			return (NULL);
		(*result)[1] = NULL;
		(*result)[0] = malloc((n + 1) * sizeof(char));
		if (!(*result)[0])
		{
			free_all(*result);
			return (NULL);
		}
		(*result)[0][n] = 0;
		return (*result);
	}
	tmp = realloc(*result, ((len + 1 + 1) * sizeof(char *)));
	*result = tmp;
	(*result)[len] = malloc((n + 1) * sizeof(char));
	if (!(*result)[len])
	{
		free_all(*result);
		return (NULL);
	}
	(*result)[len + 1] = NULL;
	return (*result);
}

void	parse_grid_to_result(char **grid, char ***result, int n)
{
	int	row;
	int	col;
	size_t	len;

	row = 0;
	len = ft_arrlen(*result);
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (grid[row][col] == 'Q')
				(*result)[len - 1][row] = col + '0';
			col++;
		}
		row++;
	}
	(*result)[len - 1][n] = 0;
}

char	**solve(char ***result, char **grid, int row, int n)
{
	int		col;

	col = 0;
	if (row == n)
	{
		init_and_increment_result(result, n);
		parse_grid_to_result(grid, result, n);
		return (*result);
	}
	while (col < n)
	{
		if (is_valid(grid, row, col, n))
		{
			grid[row][col] = 'Q';
			solve(result, grid, row + 1, n);
			grid[row][col] = '.';
		}
		col++;
	}
	return (*result);
}

int	is_valid(char **grid, int row, int col, int n)
{
	int	i;

	i = 1;
	while (i <= row)
	{
		if (grid[row - i][col] == 'Q')
			return (0);
		i++;
	}
	i = 1;
	while (i <= col && i <= row)
	{
		if (grid[row - i][col - i] == 'Q')
			return (0);
		i++;
	}
	i = 1;
	while (i <= row && i <= (n - 1 - col))
	{
		if (grid[row - i][col + i] == 'Q')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_arrlen(char **arr)
{
	size_t	arrlen;

	if (!arr)
		return (0);
	arrlen = 0;
	while (arr[arrlen])
		arrlen++;
	return (arrlen);
}

void	print_arr(char **arr, int n)
{
	size_t	i;
	int		j;
	size_t	len;

	len = ft_arrlen(arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (n - 1))
		{
			write(1, &arr[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, &arr[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	free_all(char **arr)
{
	size_t	len;
	size_t	i;

	len = ft_arrlen(arr);
	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
