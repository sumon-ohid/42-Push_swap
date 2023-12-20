/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/12/20 10:53:08 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*make_one_arg(char **argv)
{
	int		i;
	char	*arg_nbr;
	char	*temp;

	i = 1;
	arg_nbr = ft_strdup("");
	if (arg_nbr == NULL)
		return (NULL);
	while (argv[i])
	{
		temp = ft_strjoin(arg_nbr, argv[i]);
		if (temp == NULL)
		{
			free(arg_nbr);
			return (NULL);
		}
		arg_nbr = ft_strjoin(temp, " ");
		if (arg_nbr == NULL)
		{
			free(temp);
			return (NULL);
		}
		i++;
	}
	return (arg_nbr);
}

int	digit_sign_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i > 0)
			if (str[i] == '0' && (str[i - 1] == '+' || str[i - 1] == '-'))
				return (0);
		if (i > 0)
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
		free_str(str);
	nbr_list = ft_split(str, ' ', 0, 0);
	if (nbr_list == NULL)
		free_str_arr(str, arr);
	while (nbr_list[i])
	{
		arr[i] = ft_atoi(nbr_list[i]);
		i++;
	}
	if (num_validator(nbr_list, arr) == 0)
		free_all(str, arr, nbr_list);
	a = create_stack(arr, i, 0);
	if (a == NULL)
		free_all(str, arr, nbr_list);
	free_str_arr_nbr(str, arr, nbr_list);
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
			if (!a)
				free(arg_nbr);
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
