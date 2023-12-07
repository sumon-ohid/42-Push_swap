/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/07 08:44:14 by msumon           ###   ########.fr       */
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

// void	print_char_list(char **nbr_list)
// {
// 	int	i;

// 	i = 0;
// 	while (nbr_list[i])
// 	{
// 		ft_putstr_fd(nbr_list[i], 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// }

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
		free_num(num);
	while (nbr_list[i])
	{
		num[i] = ft_atoi(nbr_list[i]);
		i++;
	}
	a = create_stack(num, i);
	if (a == NULL)
		free_num(num);
	free_char_list(nbr_list);
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
		{
			free(temp2);
			error_msg();
		}
		temp = ft_strjoin(temp2, " ");
		if (temp == NULL)
		{
			free(temp);
			error_msg();
		}
		i++;
	}
	nbr_list = ft_split(temp, ' ');
	free(temp);
	if (nbr_list == NULL)
	{
		free(nbr_list);
		error_msg();
	}
	return (nbr_list);
}

void	sort_args(t_stack **a, t_stack **b, int argc)
{
	if (argc == 3)
		sa(a);
	else
	{
		sort_stack(a, b);
		//print_stack(*a);
	}
	free_stack(*a);
	free_stack(*b);
}

// ******** Still need to handle "54 52 53 51 50" case ********
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**nbr_list;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (1);
	else
	{
		nbr_list = get_args(argv);
		a = ft_split_args(nbr_list, argc - 1);
		if (a == NULL)
			error_msg();
		if (is_sorted(a) == 1)
			return (1);
		sort_args(&a, &b, argc);
	}
	return (0);
}
