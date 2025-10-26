#include <unistd.h>

void	print_comb(char *comb, int n, int is_last)
{
	write(1, comb, n);
	if (!is_last)
		write(1, ", ", 2);
}

void	generate_comb(char *comb, int pos, int n, char prev)
{
	char	c;
	int		is_last;

	c = prev + 1;
	is_last = 0;
	while (c <= '9')
	{
		comb[pos] = c;
		if (pos + 1 == n)
		{
			is_last = (comb[0] == '9' - n + 1);
			print_comb(comb, n, is_last);
		}
		else
		{
			generate_comb(comb, pos + 1, n, c);
		}
		c++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n <= 0 || n >= 11)
		return ;
	generate_comb(comb, 0, n, '0' - 1);
}
