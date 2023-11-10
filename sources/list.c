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
int	intchr(int *data, int sample, int len)
{
	int	occurence;
	int	cursor;

	cursor = 0;
	occurence = 0;
	while (cursor < len)
		if (*(cursor++ + data) == sample)
			occurence++;
	if (occurence != 1)
		return (1);
	return (0);
}

static
void	check_duplicate(int *data, int len)
{
	int	cursor;

	cursor = 0;
	while (cursor < len)
	{
		if (intchr(data, *(data + cursor++), len))
		{
			free(data);
			error();
		}
	}
}

t_list	*create(int *data, int len)
{
	int		cursor;
	t_list	*result;
	t_list	*buffer;

	check_duplicate(data, len);
	cursor = 0;
	result = malloc(sizeof(t_list));
	if (!result)
		error();
	buffer = result;
	buffer->data = *data;
	cursor++;
	while (cursor < len)
	{
		buffer->next = malloc(sizeof(t_list));
		buffer = buffer->next;
		if (!buffer)
			error();
		buffer->data = *(data + cursor);
		cursor++;
	}
	buffer->next = NULL;
	return (result);
}

int	get_next_data(t_list *list, int data)
{
	while (list->data != data)
		list = list->next;
	return (list->next->data);
}

void	clear_list(t_list **list)
{
	t_list	*buffer;
	t_list	*buffer_next;

	buffer = *list;
	while (buffer->next)
	{
		buffer_next = buffer->next;
		free(buffer);
		buffer = buffer_next;
	}
	free(buffer);
}
