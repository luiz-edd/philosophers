/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:43:14 by leduard2          #+#    #+#             */
/*   Updated: 2024/06/25 16:34:28 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_table(t_table *table, char **argv)
{
	size_t	i;

	i = 0;
	table->number_of_philosophers = string_to_size_t(argv[1]);
	table->time_to_die = string_to_size_t(argv[2]);
	table->time_to_eat = string_to_size_t(argv[3]);
	table->time_to_sleep = string_to_size_t(argv[4]);
	if (argv[5])
		table->must_eat = string_to_size_t(argv[5]);
	else
		table->must_eat = -1;
	table->dinner_is_over = false;
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	table->forks = (t_fork *)malloc(sizeof(t_fork)
			* table->number_of_philosophers);
	table->philo = (t_philo *)malloc(sizeof(t_philo)
			* table->number_of_philosophers);
	while (i < table->number_of_philosophers)
	{
		table->forks->id = i + 1;
		pthread_mutex_init(&table->forks[i].fork_mutex, NULL);
		i++;
	}
}
