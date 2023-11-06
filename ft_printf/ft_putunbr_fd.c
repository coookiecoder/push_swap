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
int	ft_intlen(long long int n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static
int	power(int n)
{
	int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	cursor;
	int	result;
	int	buffer;

	result = 0;
	if (n == 0)
		result += ft_putchar_fd(48, fd);
	if (n == 0)
		return (result);
	cursor = ft_intlen(n);
	while (cursor)
	{
		buffer = ft_putchar_fd((n / power(cursor--) % 10) + 48, fd);
		if (buffer == -1)
			return (-1);
		result += buffer;
	}
	return (result);
}
