/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_free1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:06 by msumon            #+#    #+#             */
/*   Updated: 2023/12/20 10:54:01 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_str_arr(char *str, int *arr)
{
	free(str);
	free(arr);
	error_msg();
}

void	free_str_arr_nbr(char *str, int *arr, char **nbr_list)
{
	free(str);
	free_char_list(nbr_list);
	free(arr);
}

void	free_str(char *str)
{
	free(str);
	error_msg();
}
