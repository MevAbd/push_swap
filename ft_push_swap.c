/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:00:46 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/02 00:22:18 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_choose_five(t_stack *st)
{
	st = ft_write_instruct("pb\n", st);
	st = ft_write_instruct("pb\n", st);
	st = ft_choose_three(st);
	st = ft_moov(st);
	st = ft_moov_bis(st);
	return (st);
}

t_stack	*ft_two(t_stack *st, char *str)
{
	st = ft_write_instruct(str, st);
	return (st);
}

t_stack	*ft_choose_three(t_stack *st)
{
	st = ft_three(st);
	if (ft_order(st->st_a) != 1)
		st = ft_three(st);
	return (st);
}

t_stack	*ft_choose_algo(t_stack *st, int ac)
{
	if (ac == 3)
		st = ft_two(st, "sa\n");
	else if (ac == 4)
		st = ft_choose_three(st);
	else if (ac == 6)
		st = ft_five(st);
	else
		st = ft_quick_five(st);
	return (st);
}

int	main(int ac, char **av)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (st == NULL)
		return (0);
	st->st_a = NULL;
	st->st_b = NULL;
	if (ac == 1)
	{
		free(st);
		return (0);
	}
	if ((ft_check_min_max(ac, av) == -1) || (!(ac >= 2)))
	{
		free(st);
		if (ft_check_min_max(ac, av) == -1)
			ft_error();
		return (0);
	}
	st->st_a = ft_init_a(ac, av);
	st->st_b = ft_init_a(0, NULL);
	if (ft_order(st->st_a) == -1)
		st = ft_choose_algo(st, ac);
	ft_free_stack(st);
	return (0);
}
