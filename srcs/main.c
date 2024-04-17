/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:11:47 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/17 11:06:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(char *str, t_data *data)
{
	int	i;

	if (str)
		printf("%s\n", str);
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
	{
		destroy_mutex("Incorrect number of arguments", NULL);
		return (1);
	}
	if (check_input(argv))
	{
		printf("Arguments error.\n");
		return (1);
	}
	structure_init(&data, argv);
	philos_init(&data, argv);
	threads_init(&data);
	destroy_mutex(NULL, &data);
	return (0);
}
