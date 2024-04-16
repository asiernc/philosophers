/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:40:53 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/16 17:18:27 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	routine_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->num % 2 == 0)
		ft_usleep(1);
	while (!routine_loop(philo))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (ptr);
}

void	is_thinking(t_philo *philo)
{
	print_msg("is thinking", philo->num, philo);
}

void	is_sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo->num, philo);
	ft_usleep(philo->time_to_sleep);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	print_msg("has taken a fork", philo->num, philo);
	if (philo->data->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		//printf("inside eating\n");
		pthread_mutex_unlock(philo->fork_r);
		return ;
	}
	pthread_mutex_lock(&philo->fork_l);
	print_msg("has taken a fork", philo->num, philo);
	philo->is_eating = 1;
	print_msg("is eating", philo->num, philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_eat = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}
