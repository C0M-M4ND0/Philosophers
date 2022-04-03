/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:12:14 by oabdelha          #+#    #+#             */
/*   Updated: 2022/03/31 08:55:19 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57) && c != '-' && c != '+')
		return (0);
	else
		return (1);
}

int	check_if_digit(char **list)
{
	int	i;
	int	j;

	i = 1;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (ft_isdigit(list[i][j]) == 0 || (ft_isdigit(list[i][j]) == 1
						&& (list[i][j + 1] == '-' || list[i][j + 1] == '+')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if ((ac > 6) || (ac < 5))
		return (1);
	if (check_if_digit(av) == 1)
		return (1);
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (1);
		if (ft_atoi(av[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}
