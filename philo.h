#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

// colors printf
# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;

// ./philo 5 800 200 200 [5]
//  philo_nbr, time_to_die, time_to_eat, time_to_sleep, [nbr_meals]
struct					s_fork
{
	int					id;
	t_mtx				fork;
};

struct					s_philo
{
	int					id;
	long				meals_counter;
	// time passed from last meal
	long				last_meal_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	// a philo is a thread
	pthread_t			thread_id;
};

struct					s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	long				end_simulation;
	// array forks
	t_fork				*t_fork;
	// array philos
	t_philo				*t_philo;
};

/*________________PROTOTYPES________________*/

/*-------------main.c--------------*/

/*-------------parse_inputs.c--------------*/
void					parse_inputs(int argc, char **argv, t_table *table);

/*-------------utils.c--------------*/
void					error_exit(const char *error);
long					ft_atol(char *str);

/*-------------validade_args.c--------------*/
void					validate_arguments(int argc, char **argv);

#endif