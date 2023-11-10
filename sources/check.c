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

#include "push_swap.h"

static
int	char_allowed_sign(char **c, int cursor_c, int cursor_v)
{
	char	*buffer;

	buffer = *(c + cursor_c) + cursor_v;
	if (*buffer == '-' || *buffer == '+')
	{
		if (*(buffer + 1) == '-' || *(buffer + 1) == '+')
			error();
		if (cursor_v)
			if (*(buffer - 1) != ' ')
				error();
		return (1);
	}
	return (0);
}

static
int	char_allowed(int c)
{
	if (c == ' ')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	check(int argc, char **argv)
{
	int		csr_argc;
	int		csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (!*(*(argv + csr_argc) + csr_argv))
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (char_allowed(*(*(argv + csr_argc) + csr_argv)))
			csr_argv++;
		else if (char_allowed_sign(argv, csr_argc, csr_argv))
			csr_argv++;
		else
			error();
	}
	if (argc == 1)
		error();
}
