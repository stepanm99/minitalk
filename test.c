#include <stdio.h>

int main(void)
{
	char	c;
	int		i;

	c = '*';
	i = 0;
	while (i != 8)
	{
		printf("%i\n", (c >> i) & 1);
		i++;
	}
}