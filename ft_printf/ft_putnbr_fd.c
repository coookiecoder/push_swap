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
long long int	ft_abs(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static
int	ft_intlen(long long int n)
{
	int	result;

	result = 0;
	n = ft_abs(n);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static
long long int	power(int n)
{
	long long int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

int	ft_putnbr_fd(long long int n, int fd)
{
	int	cursor;
	int	result;

	result = 0;
	if (n == 0)
		result += ft_putchar_fd(48, fd);
	if (n == 0)
		return (result);
	if (n < 0)
	{
		if (ft_putchar_fd(45, fd) == -1)
			return (-1);
	}
	else
		result--;
	result++;
	cursor = ft_intlen(n);
	while (cursor)
	{
		if (ft_putchar_fd(ft_abs(n / power(cursor--) % 10) + 48, fd) == -1)
			return (-1);
		result++;
	}
	return (result);
}
