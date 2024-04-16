/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:49:12 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/16 15:25:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_error(char *str, t_data *data)
{
	if (data)
		free(data);
		//ft_free(data);
	perror(str);
	exit(1);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Improved version of sleep function

int	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < miliseconds)
		usleep(500);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL) == -1)
		ft_error("gettimeofday() error", NULL);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}
