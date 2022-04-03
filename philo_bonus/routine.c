/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:49:59 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/02 13:07:40 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(int time_limit)
{
	long long	time;

	time = get_time();
	usleep((time_limit - (time_limit * 0.03)) * 1000);
	while ((get_time() - time) < time_limit)
		usleep(1);
}

void	ft_start_eat(t_data *data, t_philo *philo)
{
	sem_wait(data->eating);
	print_message(data, "is eating", philo->id);
	philo->check_die_time = get_time();
	sem_post(data->eating);
	(philo->eat)++;
	ft_usleep(data->time_to_eat);
}

int	ft_taking_fork(t_data *data, t_philo *philo)
{
	sem_wait(data->forks);
	print_message(data, "has taken a fork", philo->id);
	sem_wait(data->forks);
	print_message(data, "has taken a fork", philo->id);
	ft_start_eat(philo->data, philo);
	sem_post(data->forks);
	sem_post(data->forks);
	if (data->check_eat)
		return (1);
	return (0);
}

void	*routine_fonction(void *philo)
{
	t_philo	*copy_of_philo;
	t_data	*data;

	copy_of_philo = (t_philo *)philo;
	data = copy_of_philo->data;
	if (copy_of_philo->id % 2)
		usleep(10000);
	while (!(data->die))
	{
		if (data->nbrofphilo < 2)
		{
			print_message(data, "has taken a fork", copy_of_philo->id);
			ft_usleep(data->time_to_die);
			break ;
		}
		if (ft_taking_fork(data, copy_of_philo))
			break ;
		print_message(data, "is sleeping", copy_of_philo->id);
		ft_usleep(data->time_to_sleep);
		print_message(data, "is  thinking", copy_of_philo->id);
	}
	return (NULL);
}
