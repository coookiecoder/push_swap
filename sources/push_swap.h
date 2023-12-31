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

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

//function in error.c

void		error(void);

//function in check.c

void		check(int argc, char **argv);

//function in setup.c

t_list		*setup(int argc, char **argv);

//function in list.c

t_list		*create(int *data, int len);
int			get_next_data(t_list *list, int data);
void		clear_list(t_list **list);

//function in list_utils.c

int			find_max(t_list *list);
int			find_min(t_list *list);
int			get_len(t_list *list);
int			get_last_data(t_list *list, int offset);
void		reset_and_pb(t_list **list_a, t_list **list_b);

//function in ft_atoi.c

int			ft_atoi(const char *nptr, int *cursor_nptr);
long int	ft_atoi_long(const char *nptr, int *cursor_nptr);

//function in swap.c

void		ss(t_list **list_a, t_list **list_b);
void		sx(t_list **list);

//function in push.c

void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);

//function in rotate.c

void		rr(t_list **list_a, t_list **list_b);
void		rx(t_list **list);
void		rrr(t_list **list_a, t_list **list_b);
void		rrx(t_list **list);

//function in solve.c

int			solve(t_list **list_a, t_list **list_b);

//function in solve_3.c

void		solve_3(t_list **list);

//function in find_cost.c

int			cost_to_reset_rb(t_list *list);
int			cost_to_reset_rrb(t_list *list);
int			find_cost_rb(t_list *element, t_list *list_b);
int			find_cost_rrb(t_list *element, t_list *list_b);

//function in reset.c

void		reset_rb(t_list **list);
void		reset_rrb(t_list **list);

#endif
