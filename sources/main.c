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

int	sorted(t_list *list)
{
	while (list->next && list->data < list->next->data)
		list = list->next;
	list = list->next;
	if (!list)
		return (1);
	return (0);
}

void	make_left_rra(t_list **list_a, int left_rra)
{
	if (get_len(*list_a) == 3 || get_len(*list_a) == 2)
		return ;
	while (left_rra)
	{
		rrx(list_a);
		write(1, "rra\n", 4);
		left_rra--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		left_rra;

	check(argc, argv);
	list_a = setup(argc, argv);
	list_b = NULL;
	left_rra = 0;
	if (get_len(list_a) == 1 || sorted(list_a))
		return (clear_list(&list_a), 0);
	if (get_len(list_a) == 2)
	{
		if (list_a->data > list_a->next->data)
		{
			rrx(&list_a);
			write(1, "rra\n", 4);
		}
	}
	if (get_len(list_a) == 3)
		solve_3(&list_a);
	if (get_len(list_a) > 3)
		left_rra = solve(&list_a, &list_b);
	make_left_rra(&list_a, left_rra);
	clear_list(&list_a);
	return (0);
}
