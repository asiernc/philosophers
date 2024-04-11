/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:11:23 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/11 16:39:43 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	data_init(t_data *data, char **argv)
{
	if (check_input(argv))
		ft_error("Invalid args.", NULL);
	data->stop = 0;
	data->philo_eat = 0; // start eat
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_times_to_eat = ft_atoi(argv[5]);
	if (argv[5] && data->num_times_to_eat == 0)
		ft_error("You must allow them to eat...", NULL);
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philo)
		ft_error("Allocation error", NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	//pthread_mutex_init(&data->stop_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	return (0);
}

int	philos_init(t_data *data)
{
	int	i;

	data->start_time = get_time();
	i = -1;
	while (++i < data->num_of_philos)
	{
		data->philo[i].num = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].data = data;
		data->philo[i].fork_r = NULL;
		data->philo[i].last_eat = get_time();
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->num_of_philos)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		// create the threads here? and the join
		if (pthread_create(&data->philo[i].thread, NULL,
			&philo_routine, &data->philo[i]) != 0)
			ft_error("Thread create error", data->philo[i]);
	}
	i = -1;
	while (++i < data->num_of_philos)
	{
		if (pthread_join(&data->philo[i].thread, NULL) != 0)
			ft_error("Thread join error", NULL);
	}
	//data->start_time = get_time();
	printf("time start = %ld\n", data->time_start);
	return (0);
}	
