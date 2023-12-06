/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/06 16:25:34 by msumon           ###   ########.fr       */
=======
/*   Updated: 2023/12/05 23:05:40 by msumon           ###   ########.fr       */
>>>>>>> parent of 3a554d0 (OK)
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*args_to_stack(char **nbr_list, int argc)
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
<<<<<<< HEAD
	a = create_stack(num, i);
	free(num);
	return (a);
=======
>>>>>>> parent of 3a554d0 (OK)
}

char	**get_args(int argc, char **argv)
{
	char	**nbr_list;
	int		i;
	int		j;

	j = 0;
	i = 1;
<<<<<<< HEAD
	temp = ft_strdup("");
	while (argv[i])
	{
		if (check_arg(argc, argv) == 0)
			error_msg();
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
=======
	nbr_list = (char **)malloc(sizeof(char *) * argc);
>>>>>>> parent of 3a554d0 (OK)
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
<<<<<<< HEAD
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else
	{
		nbr_list = get_args(argc, argv);
		a = args_to_stack(nbr_list, argc);
		sort_stack(&a, &b);
=======
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
>>>>>>> parent of 3a554d0 (OK)
	}
	return (0);
}
