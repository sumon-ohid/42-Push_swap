/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:07 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 22:41:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack *stack_a)
{
    int temp;

    temp = stack_a->data;
    stack_a->data = stack_a->next->data;
    stack_a->next->data = temp;
}

void	sort_two(t_stack *stack_a)
{
    if (stack_a->next->data < stack_a->data)
        sa(stack_a);
}

void error_msg(char *msg)
{
    write(2, "Error!!\n", 8);
    ft_putstr_fd(msg, 2);
    exit(1);
}

int check_arg(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-' && argv[i][j] != '+')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

t_stack	*create_stack(int argc, char **argv)
{
    t_stack	*stack;
    t_stack	*temp;
    int		i;

    i = 1;
    stack = NULL;
    while (i < argc)
    {
        temp = (t_stack *)malloc(sizeof(t_stack));
        if (temp == NULL)
            error_msg("Malloc Failed\n");
        temp->data = ft_atoi(argv[i]);
        temp->next = stack;
        stack = temp;
        i++;
    }
    return (stack);
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

int		main(int argc, char **argv)
{
    t_stack	*stack_a;

    stack_a = NULL;
    if (argc < 2)
        return (0);
    if (argc == 2)
    {
        if (check_arg(argc, argv) == 0)
            error_msg("Only numbers are allowed\n");
        else
            error_msg("Mininum two numbers are required\n");
    }
    else
    {
        if (check_arg(argc, argv) == 0)
            error_msg("Only numbers are allowed\n");
        if (argc < 5)
        {
            if (check_arg(argc, argv) == 0)
                error_msg("Invalid Argument\n");
            stack_a = create_stack(argc, argv);
            sort_two(stack_a);
            print_stack(stack_a);
        }
        else
           error_msg("Too many arguments\n");
    }
    return (0);
}
