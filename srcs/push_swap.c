/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/06 22:41:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_putnbr_fd(stack->data, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

t_stack	*ft_split_args(char **nbr_list, int argc)
{
	int		*num;
	int		i;
	t_stack	*a;

	i = 0;
	num = (int *)malloc(sizeof(int) * argc);
	if (num == NULL)
		error_msg();
	if (check_arg(argc, nbr_list) == 0)
		error_msg();
	while (nbr_list[i])
	{
		num[i] = ft_atoi(nbr_list[i]);
		i++;
	}
	a = create_stack(num, i);
	free(num);
	return (a);
}

char	**get_args(char **argv)
{
	char	**nbr_list;
	char	*temp;
	char	*temp2;
	int		i;

	i = 1;
	temp = ft_strdup("");
	while (argv[i])
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

void ft_next_step(int argc, char **argv)
{
	char **nbr_list;
	int i;
	
	i = argc - 1;
	nbr_list = get_args(argv);
	ft_split_args(nbr_list, i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_split_args(argv, argc);
	if (argc < 2)
		return (1);
	else
	{
		ft_next_step(argc, argv);
		print_stack(a);
	}
	return (0);
}
