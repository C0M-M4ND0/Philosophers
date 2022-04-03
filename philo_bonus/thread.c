/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:35:14 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 22:10:00 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_creat_thread(t_data *data, t_philo *philo)
{
	philo->check_die_time = get_time();
	if (pthread_create(&philo->thread_id, NULL,
			routine_fonction, (void *)philo))
		exit(1);
	pthread_detach(philo->thread_id);
	ft_check_death(data, philo);
	exit(0);
}
