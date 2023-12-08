/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/08 21:36:45 by msumon           ###   ########.fr       */
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

int arr_size_count(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	argv_lenght(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		i++;
		len = len + j;
	}
	return (len);
}

char	*make_one_arg(char **argv)
{
	char	*one_arg;
	int		i;

	i = 1;
	if (argv[1] == NULL)
		return (NULL);
	one_arg = (char *)malloc(sizeof(char) * argv_lenght(argv) + 1);
	if (one_arg == NULL)
		error_msg();
	while (argv[i])
	{
		one_arg = ft_strjoin(one_arg, argv[i]);
		if (one_arg == NULL)
			return (NULL);
		one_arg = ft_strjoin(one_arg, " ");
		if (one_arg == NULL)
			return (NULL);
		i++;
	}
	return (one_arg);
}

int	digit_sign_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' && ft_isdigit(str[i + 1])) || (str[i] == '-'
			&& ft_isdigit(str[i + 1])))
			return (1);
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	*arg_to_num(char *str)
{
	char	**nbr_list;
	int		*arr;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * ft_strlen(str));
	if (arr == NULL)
		error_msg();
	nbr_list = ft_split(str, ' ');
	if (nbr_list == NULL)
		error_msg();
	while (nbr_list[i])
	{
		arr[i] = ft_atoi(nbr_list[i]);
		i++;
	}
	if (num_validator(nbr_list, arr) == 0)
		error_msg();
	free(nbr_list);
	return (arr);
}

void	sort_args(t_stack **a, t_stack **b, int *arr)
{
	int size;

	size = arr_size_count(arr);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b, size);
	else if (size == 5)
		sort_five(a, b, size);
	else
	{
		sort_stack(a, b);
	}
	//print_stack(*a);
	free_stack(*a);
	free_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	char	*arg_nbr;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (1);
	else
	{
		arg_nbr = make_one_arg(argv);
		if (digit_sign_check(arg_nbr))
		{
			arr = arg_to_num(arg_nbr);
			a = create_stack(arr);
			sort_args(&a, &b, arr);
		}
		else
			error_msg();
	}
	return (0);
}
