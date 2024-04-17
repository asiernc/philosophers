/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:04 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/16 21:58:20 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_msg(char *str, int philo_num, t_philo *philo)
{
	size_t	curr_time;

	pthread_mutex_lock(&philo->data->print_mutex);
	curr_time = get_time() - philo->start_time;
	if (routine_loop(philo) == 0)
		printf("%zu \033[1;34m%d\033[0m %s\n", curr_time, philo_num, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	check_philo(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	if (time_to_die <= (get_time() - philo->last_eat)// >= time_to_die
		&& philo->is_eating == 0)
	{
		pthread_mutex_unlock(&philo->data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat_mutex);
	return (0);
}

int	check_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->num_of_philos)
	{
		if (check_philo(&philo[i], philo[i].time_to_die))
		{
			print_msg("is \033[1;31mdied\033[0m", philo[i].num, philo);
			pthread_mutex_lock(&philo[0].data->dead_mutex);
			philo->data->dead_flag = 1;
			pthread_mutex_unlock(&philo[0].data->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_ate(t_philo *philo)
{
	int	i;
	int	finish;

	if (philo->num_times_to_eat == -1)
		return (0);
	i = 0;
	finish = 0;
	while (i < philo[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philo[i].data->eat_mutex);
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			finish++;
		pthread_mutex_unlock(&philo[i].data->eat_mutex);
		i++;
	}
	if (finish == philo[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philo[0].data->dead_mutex);
		*philo->dead = 1;
		pthread_mutex_unlock(&philo[0].data->dead_mutex);
		return (1);
	}
	return (0);
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
