# include <unistd.h>
# define _XOPEN_SOURCE 500
# include <signal.h>
# include <sys/types.h>
# include <locale.h>
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	void			*data;
	char			c;
	unsigned long	d;

	setlocale(LC_ALL, "");
	data = NULL;
	data = malloc(35);
	c = 'q';
	d = L'😛';
	if (!data)
		return (-1);
	printf("%lu\n", sizeof(*data));
	printf("%lu\n", sizeof(c));
	printf("%lu\n", sizeof(d));
	write(1, &c, 1);
	write(1, &d, 6);
	free(data);
	return (0);
}