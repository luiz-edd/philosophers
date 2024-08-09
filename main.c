/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:32:19 by leduard2          #+#    #+#             */
/*   Updated: 2024/06/26 15:31:04 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table table;
	
	if(check_args(argc, argv))
	{
		set_table(&table, argv);
		set_philos(&table);
		start_dinner(&table);
		
	}
	return (EXIT_FAILURE);
}