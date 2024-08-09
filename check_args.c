/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:43:36 by leduard2          #+#    #+#             */
/*   Updated: 2024/08/05 15:57:23 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_args(int argc, char **argv)
{
	if(check_number_of_args(argc))
		return (false);
}

bool	check_number_of_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Correct usage: ./philo 'number_of_philosophers'\
 'time_to_die' 'time_to_eat' 'time_to_sleep' [number_of_times_each_\
 philosopher_must_eat]\n-> Times are in milliseconds and the last\
  argument is optional\n");
		return (false);
	}
	return (true);
}
