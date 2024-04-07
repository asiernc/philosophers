/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:11:23 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/07 18:57:54 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	vars_init(t_data *data, char **argv)
{
	if (check_input(argv))
		ft_error("Invalid args.", NULL);
	data->philo_eat = 0; // start eat
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_eat = ft_atoi(argv[5]);
	if (argv[5] && data->num_eat == 0)
		ft_error("You must allow them to eat...", NULL);
	return (0);
}

	
