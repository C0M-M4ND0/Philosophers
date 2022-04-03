/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:52:29 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 13:44:16 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	long long		check_die_time;
	int				eat;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				nbrofphilo;
	pid_t			*child_pid;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_each_philo_must_eat;
	int				die;
	int				check_eat;
	long long		beginning_time;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eating;
	t_philo			*philo;
}				t_data;

int			check_args(int ac, char **av);
int			ft_atoi(const char *str);
void		*routine_fonction(void	*philo);
int			ft_initialization(t_data *philo, int ac, char **av);
long long	get_time(void);
int 		ft_creat_process(t_data *data, t_philo *philo);
void		ft_creat_thread(t_data *data, t_philo *philo);
void		print_message(t_data *data, char *string, int philo_id);
void		ft_check_death(t_data *data, t_philo *philo);
void		ft_end_philo(t_data *data);
void		kill_process(t_data *data);

#endif
