/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiercara <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:11:47 by asiercara         #+#    #+#             */
/*   Updated: 2024/04/15 17:22:27 by anovio-c         ###   ########.fr       */
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
	//clear_all(NULL, &data);
	return (0);
}
