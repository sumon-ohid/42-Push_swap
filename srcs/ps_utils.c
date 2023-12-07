/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:28:31 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 08:29:10 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isrepeat(long num, int *arr, int size)
{
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
    	error_msg();
	while (i < size)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * argc);
	if (arr == NULL)
		error_msg();
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN || ft_isrepeat(num, arr, i) == 0)
		{
			free(arr);
			return (0);
		}
		arr[i] = num;
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
			{
				free(arr);
				return (0);
			}
		}
		i++;
	}
	free(arr);
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
	while (len < i)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg();
		temp->data = num[len];
		temp->next = NULL;
		temp->prev = last;
		if (last != NULL)
			last->next = temp;
		else
			stack_a = temp;
		last = temp;
		len++;
	}
	return (stack_a);
}

int	is_sorted(t_stack *a)
{
	int		i;
	int		j;
	int		*arr;
	t_stack	*temp;

	i = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	arr = (int *)malloc(sizeof(int) * i);
	if (arr == NULL)
		error_msg();
	j = 0;
	while (a != NULL)
	{
		arr[j] = a->data;
		a = a->next;
		j++;
	}
	j = 0;
	while (j < i - 1)
	{
		if (arr[j] > arr[j + 1])
		{
			free(arr);
			return (0);
		}
		j++;
	}
	free(arr);
	return (1);
}
