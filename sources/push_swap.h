/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/06 15:32:16 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"

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

//function in swap.c

void	ss(t_list **list_a, t_list **list_b);
void	sx(t_list **list);

//function in push.c

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

//functoin in rotate.c

void	rr(t_list **list_a, t_list **list_b);
void	rx(t_list **list);
void	rrr(t_list **list_a, t_list **list_b);
void	rrx(t_list **list);

#endif
