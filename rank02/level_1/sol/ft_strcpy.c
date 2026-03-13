char *ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	char *s1;
//
//	s1 = malloc(sizeof(char) * 6);
//	ft_strcpy(s1, "Hello there");
//	printf("%s\n", s1);
//}
