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

void	reset_rb(t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rx(list_b);
		write(1, "rb\n", 3);
	}
}

void	reset_rrb(t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rrx(list_b);
		write(1, "rrb\n", 4);
	}
}
