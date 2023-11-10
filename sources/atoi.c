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

static
void	ft_getsign(const char *c, int *sign, int *cursor, int *cursor_nptr)
{
	if (*c == '+')
		*sign = 1;
	else if (*c == '-')
		*sign = -1;
	else
		*sign = 0;
	*cursor = *cursor + 1;
	*cursor_nptr = *cursor_nptr + 1;
	return ;
}

static
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, int *cursor_nptr)
{
	int	cursor;
	int	sign;
	int	result;

	cursor = 0;
	result = 0;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor, cursor_nptr);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
	{
		cursor++;
		*cursor_nptr = *cursor_nptr + 1;
	}
	while (ft_isdigit(*(nptr + cursor)))
	{
		result = (result * 10) + *((char *)nptr + cursor++) - '0';
		*cursor_nptr = *cursor_nptr + 1;
	}
	if (!cursor)
		*cursor_nptr = *cursor_nptr + 1;
	return (result * sign);
}
