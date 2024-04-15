/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:04 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/15 11:44:45 by anovio-c         ###   ########.fr       */
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
