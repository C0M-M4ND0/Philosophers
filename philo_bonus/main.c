/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:43:44 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/01 10:28:08 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (write(2, "ERROR : Incorrect Arguments !\n", 30), 1);
	if (ft_initialization(&data, ac, av) == 1)
		return (1);
	if (ft_creat_process(&data, (&data)->philo))
		return (write(2, "ERROR : There is Something wrong !\n", 35), 1);
	return (0);
}
