/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:11:23 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/16 16:31:00 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	structure_init(t_data *data, char **argv)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philo)
		ft_error("Allocation error", NULL);
	data->dead_flag = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
}


void	fill_fixes_values(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else if (argv[5] && philo->num_times_to_eat == 0)
		ft_error("You must allow them to eat...", NULL);
	else
		philo->num_times_to_eat = -1;
}

void	philos_init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philo[i].num = i + 1;
		fill_fixes_values(&data->philo[i], argv);
		data->philo[i].is_eating = 0;
		data->philo[i].start_time = get_time();
		data->philo[i].last_eat = get_time();
		data->philo[i].meals_eaten = 0;
		data->philo[i].data = data;
		data->philo[i].dead = &data->dead_flag;
		data->philo[i].fork_r = NULL;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == (data->num_of_philos - 1))
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l; // 18
		/*if (pthread_create(&data->philo[i].thread, NULL,
			&philo_routine, &data->philo[i]) != 0)
			ft_error("Thread create error", data->philo[i]);*/
		i++;
	}
	/*i = -1;
	while (++i < data->num_of_philos)
	{
		if (pthread_join(&data->philo[i].thread, NULL) != 0)
			ft_error("Thread join error", NULL);
	}*/
}

int	threads_init(t_data *data)
{
	pthread_t	security_guard;
	int			i;

	if (pthread_create(&security_guard, NULL, &controller, data->philo) != 0)
		ft_error("Thread create error", NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&philo_routine, &data->philo[i]) != 0)
			ft_error("Thread create error", NULL);
		//printf("times\n");
		i++;
	}
	if (pthread_join(security_guard, NULL) != 0)
		ft_error("Thread join error", NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			ft_error("Thread join error", NULL);
		i++;
	}
	return (0);
}
/*int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->num_of_philos)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
	}
}*/
