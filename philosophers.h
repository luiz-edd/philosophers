/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:00:20 by leduard2          #+#    #+#             */
/*   Updated: 2024/08/05 17:46:22 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define BLU "\033[0;34m"
# define GRN "\033[0;32m"
# define CYN "\033[0;36m"
# define YEL "\033[0;33m"
# define RED "\033[0;31m"
# define MAG "\033[0;35m"
# define RST "\033[0m"

typedef struct s_table
{
	size_t			number_of_philosophers;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			must_eat;
	size_t			meals_eaten;
	pthread_mutex_t mutex_table;
	pthread_mutex_t mutex_printf;
	t_fork			*forks;
	t_philo			*philos;
	bool			dinner_is_over;
}					t_table;

typedef struct s_philo
{
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_table 		*table;
	size_t			id;
	size_t			last_meal_time;
	size_t			meals_eaten;
	pthread_mutex_t mutex_philo;
	bool			is_full;
}					t_philo;

typedef struct s_fork
{
	size_t			id;
	pthread_mutex_t	mutex_fork;
}					t_fork;

// ==================	main	==================

// ==================	check_args ==================

bool				check_args(int argc, char **argv);

// ==================	utils ==================

size_t				string_to_sizet(char *str);

#endif