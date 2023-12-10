/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:14 by msumon            #+#    #+#             */
/*   Updated: 2023/12/10 22:21:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra_until_min(t_stack **stack, int num)
{
	int	cost;

	cost = 0;
	while ((*stack)->data != num)
	{
		rra(stack);
		cost++;
	}
	return (cost);
}

t_stack *copy_stack(t_stack *stack)
{
	t_stack *copy;
	t_stack *temp;

	copy = NULL;
	while (stack)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (temp == NULL)
			error_msg();
		temp->data = stack->data;
		temp->next = NULL;
		if (copy == NULL)
			copy = temp;
		else
		{
			temp->next = copy;
			copy = temp;
		}
		stack = stack->next;
	}
	return (copy);
}

int get_min_position(t_stack *arr, int min)
{
	int position;

	position = 0;
	while (arr)
	{
		if (arr->data == min)
			return (position);
		position++;
		arr = arr->next;
	}
	return (position);
}

void sort_stack(t_stack **a, t_stack **b, int *arr)
{
	int position;
	int min;
    int size;
	t_stack *last;
	(void)arr;

	min = find_min(*a);
	position = get_min_position(*a, min);
    last = get_last_element(*a);
    size = get_stack_size(a);
    while (size > 2)
    {
		last = get_last_element(*a);
        min = find_min(*a);
		position = get_min_position(*a, min);
        if (last->data == min)
        {
            rra(a);
            pb(a, b);
        }
		else if (position < size / 2)
        {
            rotate_until_min(a, min);
            pb(a, b);
        }
		else
		{
			rra_until_min(a, min);
			pb(a, b);
		}
        size--;
    }
    if (size == 2 && is_sorted(*a) == 0)
        sort_three(a);
    while (*b)
        pa(a, b);
	print_stack(a);
}

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	rotate_until_mid(t_stack **stack, int mid_num)
{
	while ((*stack)->data != mid_num)
		ra(stack);
}

// void	sort_stack(t_stack **stack_a, t_stack **stack_b, int *arr)
// {
//     int *sorted_arr;
//     int mid_num;
//     int stack_size;
// 	int value;
	
// 	value = 0;
//     stack_size = get_stack_size(stack_a);
//     sorted_arr = ft_sort_int_tab(arr, arr_size_count(arr));
//     mid_num = sorted_arr[arr_size_count(arr) / 2];
//     while (stack_size > 0)
//     {
//         while ((*stack_a))
// 		{
// 			if ((*stack_a)->data < mid_num)
// 			{
// 				value = (*stack_a)->data;
// 				rotate_until_mid(stack_a, mid_num);
// 				pb(stack_a, stack_b);
// 			}
// 		}
//         stack_size = get_stack_size(stack_a);
//     }
// }