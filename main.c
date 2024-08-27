#include "philo.h"

// ./philo 5 800 200 200 [5]
//  philo_nbr, time_to_die, time_to_eat, time_to_sleep, [nbr_meals]

int	main(int argc, char **argv)
{
	t_table table;

	validate_arguments(argc, argv);
	init_data(argv, &table);
}