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
char	get_digit(unsigned int number, int digit)
{
	while (digit)
	{
		number = number / 16;
		digit--;
	}
	number = number % 16;
	if (number <= 9)
		return (number + '0');
	else
		return (number - 10 + 'A');
}

int	ft_puthexu_fd(unsigned int number, int fd)
{
	int		digit;
	char	buffer;
	_Bool	start_print;
	int		result;

	digit = 8;
	start_print = 0;
	result = 0;
	while (digit >= 0)
	{
		buffer = get_digit(number, digit--);
		if (buffer != '0' || start_print || digit < 0)
		{
			if (ft_putchar_fd(buffer, fd) == -1)
				return (-1);
			start_print = 1;
			result++;
		}	
	}
	return (result);
}
