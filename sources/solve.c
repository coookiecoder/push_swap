/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/09 11:27:39 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	cost_to_reset(t_list *list)
{
	int	cost;

	while (list->next && list->data > list->next->data)
		list = list->next;
	if (!list->next)
		return (0);
	cost = 0;
	while (list->next)
	{
		list = list->next;
		cost++;
	}
	return (cost);
}

static
int	find_cost(t_list *element, t_list *list_b)
{
	int	first;
	int	last;
	int	cost;

	if (element->data > find_max(list_b))
		return (cost_to_reset(list_b) + 1);
	if (element->data < find_min(list_b))
		return (cost_to_reset(list_b) + 1);
	cost = 0;
	first = list_b->data;
	last = get_last_data(list_b, 0);
	while (element->data < first && element->data > last)
	{
		first = last;
		last = get_last_data(list_b, ++cost);
	}
	return (cost);
}

static
int	find_cheapest(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;
	int		cheapest;
	int		cheapest_cost;
	int		rotate_cost;

	buffer = (*list_a)->next;
	cheapest = (*list_a)->data;
	cheapest_cost = find_cost(*list_a, *list_b);
	rotate_cost = 0;
	while (buffer && rotate_cost < cheapest_cost)
	{
		if (find_cost(buffer, *list_b) + rotate_cost++ < cheapest_cost)
		{
			cheapest_cost = find_cost(buffer, *list_b);
			cheapest = buffer->data;
		}
		buffer = buffer->next;
	}
	return (cheapest);
}

static
void	do_cheapest(t_list **list_a, t_list **list_b)
{
	int	cheapest;

	cheapest = find_cheapest(list_a, list_b);
	printf("%i", cheapest);
}

void	solve(t_list **list_a, t_list **list_b)
{
	pb(list_a, list_b);
	pb(list_a, list_b);
	do_cheapest(list_a, list_b);
}
