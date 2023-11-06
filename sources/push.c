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

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_b)
	{
		buffer = (*list_b)->next;
		(*list_b)->next = (*list_a);
		(*list_a) = (*list_b);
		(*list_b) = buffer;
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_a)
	{
		buffer = (*list_a)->next;
		(*list_a)->next = (*list_b);
		(*list_b) = (*list_a);
		(*list_a) = buffer;
	}
}
