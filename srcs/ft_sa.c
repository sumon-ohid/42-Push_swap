/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:28:36 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 14:41:10 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack *a)
{
	int temp;

	if (a->data > a->next->data)
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		ft_printf("sa\n");
	}
    else
        error_msg();
}
