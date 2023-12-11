/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:28:31 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 15:53:19 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isrepeat(long num, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int num_validator(char **str, int *arr)
{
	long i;
	long num;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = ft_atol(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		else if (ft_isrepeat(num, arr, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*create_stack(int *num, int i)
{
	t_stack	*stack_a;
	t_stack	*temp;
	t_stack	*last;
	int		len;

	len = 0;
	stack_a = NULL;
	last = NULL;
	while (i)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg();
		temp->data = num[len];
		temp->rank = 0;
		temp->next = NULL;
		temp->prev = last;
		if (last != NULL)
			last->next = temp;
		else
			stack_a = temp;
		last = temp;
		len++;
		i--;
	}
	return (stack_a);
}

