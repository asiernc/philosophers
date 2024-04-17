/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:11:47 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/16 21:27:46 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_destroy(data->philo[i].fork_r);
	}
	free(data->philo);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (check_input(argv))
	{
		write(2, "Arguments error\n", 16);
		return (0);
	}
	structure_init(&data, argv);
	philos_init(&data, argv);
	threads_init(&data);
	destroy_mutex(&data);
	return (0);
}
