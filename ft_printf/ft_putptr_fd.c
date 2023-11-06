/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
char	get_digit(void *ptr, int digit)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
	while (digit)
	{
		number = number / 16;
		digit--;
	}
	number = number % 16;
	if (number <= 9)
		return (number + '0');
	else
		return (number - 10 + 'a');
}

static
void	init(int *digit, int *result, int *start_print)
{
	*digit = 15;
	*result = 2;
	*start_print = 0;
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int	digit;
	int	result;
	int	start_print;

	if (!ptr)
		return (write(fd, "0x0", 3));
	init(&digit, &result, &start_print);
	if (ft_putchar_fd('0', fd) == -1)
		return (-1);
	if (ft_putchar_fd('x', fd) == -1)
		return (-1);
	while (digit >= 0)
	{
		if (get_digit(ptr, digit) != '0' || start_print)
		{
			if (ft_putchar_fd(get_digit(ptr, digit), fd) == -1)
				return (-1);
			start_print = 1;
			result++;
		}
		digit--;
	}
	return (result);
}
