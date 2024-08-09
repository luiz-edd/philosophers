/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:24:17 by leduard2          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:02 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assign_forks(t_table *table, size_t philo_pos)
{
	if (philo_pos % 2 == 0)
	{
		table->philos[philo_pos].first_fork = &table->forks[philo_pos];
		table->philos[philo_pos].second_fork = &table->forks[(philo_pos + 1)
			% table->number_of_philosophers];
	}
	else
	{
		table->philos[philo_pos].first_fork = &table->forks[(philo_pos + 1)
			% table->number_of_philosophers];
		table->philos[philo_pos].second_fork = &table->forks[philo_pos];
	}
}

void	set_philo_and_forks(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].is_full = false;
		table->philos[i].table = table;
		assign_forks(table, i);
		pthread_mutex_init(&table->philos[i].mutex_philo, NULL);
		i++;
	}
}
