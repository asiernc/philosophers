/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:11:47 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/15 16:25:09 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (check_input(argv))
		return (1);
	structure_init(&data, argv);
	philos_init(&data);
	threads_init(&data);
	clear_all(NULL, &data);
	//init.philo
	printf("Num philos: %d\n", data.num_of_philo);
	printf("time to die: %d\n", data.time_to_die);
	printf("time to eat: %d\n", data.time_to_eat);
	printf("time to sleep: %d\n", data.time_to_sleep);
	printf("nums eat: %d", data.num_eat);
	return (0);
}
