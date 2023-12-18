/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:31:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 18:34:19 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_char_list(char **nbr_list)
{
	int	i;

	i = 0;
	while (nbr_list[i])
	{
		free(nbr_list[i]);
		i++;
	}
	free(nbr_list);
}

void	free_all(char *str, int *arr, char **nbr_list)
{
	free(str);
	free_char_list(nbr_list);
	free(arr);
	error_msg();
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_void(void *ptr)
{
	free(ptr);
	error_msg();
}
