/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:04 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/15 17:00:19 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_msg(char *str, int philo_num, t_philo *philo)
{
	size_t	curr;

	pthread_mutex_lock(philo->data->print_mutex);
	time = get_current_time() - philo->start_time;
	if (dead_check(philo) == 0)
		printf("%zu %d %s\n", time, philo_num, str);
	pthread_mutex_unlock(philo>data->print_mutex);
}

static int	check_philo(t_philo *philo)
{
	size_t	time_to_die;

	time_to_die = philo->data->time_to_die;
	pthread_mutex_lock(philo->eat_mutex);
	if (time_to_die <= (get_time() - philo->last_eat)
		&& philo->is_eating == 0)
	{
		pthread_mutex_unlock(philo->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_mutex);
	return (0);
}

int		check_is_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->num_of_philos)
	{
		if (check_philo(philo) == 1)
		{
			print_msg("is died", philo->num, philo);
			pthread_mutex_lock(philo->dead_mutex);
			*philo->data->dead_flag = 1;
			pthread_mutex_unlock(philo->dead_mutex);
		}
		//i++;
	}
	return (0);
}

int		check_is_all_ate(t_philo *philos)
{

}

void	*controller(void *ptr)
{
	t_philo	*philos_struct;

	philos_struct = (t_philo *)ptr;
	while (1)
	{
		if (check_is_dead(philos_struct) == 1
			|| check_all_ate(philos_struct) == 1)
			break ;
	}
	return (ptr);
}
