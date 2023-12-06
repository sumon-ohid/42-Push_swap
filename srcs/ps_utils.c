/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:28:31 by msumon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/06 16:26:35 by msumon           ###   ########.fr       */
=======
/*   Updated: 2023/12/05 14:36:39 by msumon           ###   ########.fr       */
>>>>>>> parent of 3a554d0 (OK)
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

int	check_arg(int argc, char **argv)
{
	int		*arr;
	long	num;
	int		i;
	int		j;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		error_msg();
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(('0' <= argv[i][j] && argv[i][j] <= '9') || (j == 0
						&& (argv[i][j] == '+' || argv[i][j] == '-'))))
			{
				free(arr);
				return (0);
			}
			j++;
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN || ft_isrepeat(num, arr, i - 1) == 0)
		{
			free(arr);
			return (0);
		}
		arr[i - 1] = num;
		i++;
	}
	free(arr);
	return (1);
}

t_stack	*create_stack(int argc, char **argv, t_stack *stack)
{
	t_stack	*temp;
	int		i;

<<<<<<< HEAD
	len = i - 1;
	stack_a = NULL;
	while (len >= 0)
=======
	i = 1;
	stack = NULL;
	temp = NULL;
	while (i < argc)
>>>>>>> parent of 3a554d0 (OK)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg();
<<<<<<< HEAD
		temp->data = num[len];
		temp->next = stack_a;
		temp->prev = NULL;
		if (stack_a != NULL)
			stack_a->prev = temp;
		stack_a = temp;
		len--;
	}
	free (temp);
	return (stack_a);
=======
		temp->data = ft_atoi(argv[i]);
		temp->next = stack;
		stack = temp;
		i++;
	}
	return (stack);
>>>>>>> parent of 3a554d0 (OK)
}
