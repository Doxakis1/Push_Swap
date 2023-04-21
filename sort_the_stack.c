/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:42:00 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/21 13:32:26 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sort_the_stack(t_stack *stack_a, int a_stack_size)
{
	long	j;
	short	test;
	t_stack	*curr;

	j = 0;
	curr = &stack_a[0];
	while (++j <= a_stack_size)
	{
		test = find_next_smol(&stack_a[0], j, 0, &stack_a[0]);
		if (!test)
			return (0);
	}
	j = -1;
	while (++j < a_stack_size)
	{
		curr->nbr = curr->sorted;
		if (curr->nbr == 0)
			curr->nbr = a_stack_size;
		curr = curr->next;
	}
	return (1);
}

short	find_next_smol(t_stack *stack_a, long j, int check, t_stack *start)
{
	t_stack	*curr;
	t_stack	*smol;

	curr = &stack_a[0];
	smol = NULL;
	while (check != 2)
	{	
		if (curr == start)
			check++;
		if (curr != start && smol != NULL && curr->nbr == smol->nbr)
			return (0);
		if (curr->sorted == 0 && smol == NULL)
		{
			curr->sorted = j;
			smol = curr;
		}
		if (curr->sorted == 0 && curr->nbr < smol->nbr)
		{
			curr->sorted = j;
			smol->sorted = 0;
			smol = curr;
		}
		curr = curr->next;
	}
	return (1);
}
