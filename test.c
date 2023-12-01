#include <stdio.h>

int main(void)
{
	char	c;
	int		i;

	c = ' ';
	i = 0;
	while (c != '~')
	{
		while (i != -1)
		{
			printf("%i", (c >> i) & 1);
			i--;
		}
		printf(" = %c\n", c);
		i = 7;
		c++;
	}
}
