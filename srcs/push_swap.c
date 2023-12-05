/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/05 23:05:40 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_stack *stack_a)
{
	int	temp;

	if (stack_a->data > stack_a->next->data)
	{
		temp = stack_a->data;
		stack_a->data = stack_a->next->data;
		stack_a->next->data = temp;
		ft_printf("sa\n");
	}
	else
		error_msg();
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_putnbr_fd(stack->data, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	ft_split_args(char **nbr_list, int argc)
{
	int *num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	num = (int *)malloc(sizeof(int) * argc);
	if (num == NULL)
		error_msg();
	while (nbr_list[i])
	{
		num[j] = ft_atoi(nbr_list[i]);
		printf("%d\n", num[j]);
		j++;
		i++;
	}
}

char	**get_args(int argc, char **argv)
{
	char	**nbr_list;
	int		i;
	int		j;

	j = 0;
	i = 1;
	nbr_list = (char **)malloc(sizeof(char *) * argc);
	if (nbr_list == NULL)
		error_msg();
	while (argv[i])
	{
		nbr_list[j] = (char *)malloc(sizeof(char) * ft_strlen(argv[i]));
		if (nbr_list[j] == NULL)
			error_msg();
		nbr_list[j] = ft_strjoin(argv[i], " ");
		i++;
		j++;
	}
	return (nbr_list);
}

int	main(int argc, char **argv)
{
	char	**nbr_list;
	int		i;

	i = 0;
	nbr_list = (char **)malloc(sizeof(char *) * argc);
	if (nbr_list == NULL)
		error_msg();
	if (argc < 3)
		return (1);
	else
	{
		while (i < argc)
		{
			nbr_list[i] = (char *)malloc(sizeof(char) * ft_strlen(argv[i]));
			if (nbr_list[i] == NULL)
				error_msg();
			nbr_list = get_args(argc, argv);
			printf("%s", nbr_list[i]);
			i++;
		}
		ft_split_args(nbr_list, argc);
	}
	return (0);
}
