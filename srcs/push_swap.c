/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/11 17:34:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*make_one_arg(char **argv)
{
	char	*one_arg;
	int		i;

	i = 1;
	if (argv[1] == NULL)
		return (NULL);
	one_arg = (char *)ft_calloc(sizeof(char), argv_lenght(argv) + 1);
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
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '0' && (str[i - 1] == '+' || str[i - 1] == '-'))
			return (0);
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '\0'
				|| !ft_isdigit(str[i + 1]) || ft_isdigit(str[i - 1])))
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			return (0);
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+'
				|| str[i + 1] == '-' || !ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*arg_to_num(char *str)
{
	char	**nbr_list;
	int		*arr;
	int		i;
	t_stack	*a;

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
		free_all(str, arr, nbr_list);
	a = create_stack(arr, i, 0);
	free(str);
	free(arr);
	free_char_list(nbr_list);
	return (a);
}

void	sort_args(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(a);
	if (is_sorted(*a))
	{
		free_stack(*a);
		return ;
	}
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b, size);
	else if (size == 5)
		sort_five(a, b, size);
	else
		sort_stack(a, b);
	free_stack(*a);
	free_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
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
			a = arg_to_num(arg_nbr);
			sort_args(&a, &b);
		}
		else
		{
			free(arg_nbr);
			error_msg();
		}
	}
	return (0);
}
