/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 10:41:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*args_to_stack(char **nbr_list, int argc)
{
	int		*num;
	int		i;
	t_stack	*a;

	i = 0;
	num = (int *)malloc(sizeof(int) * argc);
	if (num == NULL)
		error_msg();
	while (nbr_list[i])
	{
		num[i] = ft_atoi(nbr_list[i]);
		i++;
	}
	a = create_stack(num, i);
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	return (a);
}

char	**get_args(int argc, char **argv)
{
	char	**nbr_list;
	char	*temp;
	char	*temp2;
	int		i;

	i = 1;
	temp = ft_strdup("");
	while (argv[i] && check_arg(argc, argv))
	{
		temp2 = ft_strjoin(temp, argv[i]);
		if (temp2 == NULL)
			error_msg();
		free(temp);
		temp = ft_strjoin(temp2, " ");
		if (temp == NULL)
			error_msg();
		free(temp2);
		i++;
	}
	nbr_list = ft_split(temp, ' ');
	free(temp);
	if (nbr_list == NULL)
		error_msg();
	return (nbr_list);
}

int	main(int argc, char **argv)
{
	char	**nbr_list;

	if (argc < 3)
		return (1);
	else
	{
		nbr_list = get_args(argc, argv);
		args_to_stack(nbr_list, argc);
	}
	return (0);
}
