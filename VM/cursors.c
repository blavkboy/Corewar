/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/17 17:00:54 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_list		*ft_create_cursor(int i, t_env *e)
{
	t_cursor	*newcursor;

	newcursor = malloc(sizeof(t_cursor));
	if (newcursor == NULL)
		return (NULL);
	newcursor->id = i;
	newcursor->carry = 0;
	newcursor->cycle = 0;
	newcursor->index = e->player[i].index_start;
	newcursor->next = NULL;
	return (newcursor);
}

t_list		*ft_add_cursor_to_stack(t_list *stack, int i, t_env *e)
{
	while (stack && stack->next)
		stack = stack->next;
	stack->next = ft_create_cursor(i, e);
	return (stack);
}

t_list		*ft_init_cursor(t_env *e)
{
	int 		i;
	t_cursor	*stack;
	t_cursor	*head;

	i = -1;
	stack = NULL;
	while(++i e->player_amount)
		stack = ft_add_cursor_to_stack(stack, i, e);
	return (stack);
}