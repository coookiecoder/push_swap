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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

//function in error.c

void	error(void);

//function in check.c

void	check(int argc, char **argv);

//function in setup.c

t_list	*setup(int argc, char **argv);

//function in list.c

t_list	*create(int *data, int len);
void	clear_list(t_list *list);
void	print_list(t_list *list);

//function in ft_atoi.c

int		ft_atoi(const char *nptr, int *cursor_nptr);


#endif
