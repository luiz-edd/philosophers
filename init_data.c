#include "philo.h"

void init_data(char **argv, t_table *table)
{
	table->philo_nbr = (int)ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->number_of_meals = 0;
	if (argc == 6)
		table->number_of_meals = ft_atol(argv[5]);
	table->mutex_fork = malloc(table->philo_nbr
			* sizeof(t_mtx));
}