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
int	find_cheapest(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;
	int		cheapest;
	int		cheapest_cost;
	int		rotate_cost;

	buffer = (*list_a);
	cheapest = (*list_a)->data;
	cheapest_cost = find_cost_rb(*list_a, *list_b);
	rotate_cost = 0;
	while (buffer && rotate_cost < cheapest_cost)
	{
		if (find_cost_rb(buffer, *list_b) + rotate_cost < cheapest_cost)
		{
			cheapest_cost = find_cost_rb(buffer, *list_b) + rotate_cost - 1;
			cheapest = buffer->data;
		}
		if (find_cost_rrb(buffer, *list_b) + rotate_cost++ < cheapest_cost)
		{
			cheapest_cost = find_cost_rrb(buffer, *list_b) + rotate_cost - 1;
			cheapest = buffer->data;
		}
		buffer = buffer->next;
	}
	return (cheapest);
}

static
void	chose_move(t_list **list_a, t_list **list_b)
{
	int	first;
	int	last;

	first = (*list_b)->data;
	last = get_last_data(*list_b, 0);
	if (find_cost_rb(*list_a, *list_b) <= find_cost_rrb(*list_a, *list_b))
	{
		while ((*list_a)->data < first || (*list_a)->data > last)
		{
			rx(list_b);
			write(1, "rb\n", 3);
			first = (*list_b)->data;
			last = get_last_data(*list_b, 0);
		}
		return ;
	}
	while ((*list_a)->data < first || (*list_a)->data > last)
	{
		rrx(list_b);
		write(1, "rrb\n", 4);
		first = (*list_b)->data;
		last = get_last_data(*list_b, 0);
	}
}

static
void	do_cheapest(t_list **list_a, t_list **list_b)
{
	int	cheapest;

	cheapest = find_cheapest(list_a, list_b);
	while ((*list_a)->data != cheapest)
	{
		rx(list_a);
		write(1, "ra\n", 3);
	}
	if ((*list_a)->data > find_max(*list_b))
		return (reset_and_pb(list_a, list_b));
	if ((*list_a)->data < find_min(*list_b))
		return (reset_and_pb(list_a, list_b));
	chose_move(list_a, list_b);
	pb(list_a, list_b);
	write(1, "pb\n", 3);
}

static
void	check_rra(t_list **list_a, t_list **list_b, int *moved)
{
	if (get_last_data(*list_a, 0) > (*list_b)->data && *moved < 3)
	{
		rrx(list_a);
		write(1, "rra\n", 4);
		*moved = *moved + 1;
	}
	else
	{
		pa(list_a, list_b);
		write(1, "pa\n", 3);
	}
}

int	solve(t_list **list_a, t_list **list_b)
{
	int	moved;

	moved = 0;
	pb(list_a, list_b);
	write(1, "pb\n", 3);
	if (get_len(*list_a) > 4)
	{
		pb(list_a, list_b);
		write(1, "pb\n", 3);
	}
	while ((*list_a)->next->next && (*list_a)->next->next->next)
		do_cheapest(list_a, list_b);
	if (cost_to_reset_rb(*list_b) < cost_to_reset_rrb(*list_b))
		reset_rb(list_b);
	else
		reset_rrb(list_b);
	solve_3(list_a);
	while (*list_b)
		check_rra(list_a, list_b, &moved);
	return (3 - moved);
}
