// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   old.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/12 15:26:39 by leduard2          #+#    #+#             */
// /*   Updated: 2024/06/12 15:26:40 by leduard2         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// void	*thread_routine(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	while (1)
// 	{
// 		if (philo->id % 2 == 0)
// 		{
// 			//eating
// 			pthread_mutex_lock(&arr_mutex[philo->left]);
// 			printf("%d take a fork °%d\n", philo->id, philo->right);
// 			pthread_mutex_lock(&arr_mutex[philo->right]);
// 			printf("%d take a fork °%d\n", philo->id, philo->left);
// 			printf("%d eating\n", philo->id);
// 			usleep(200000);
// 			pthread_mutex_unlock(&arr_mutex[philo->left]);
// 			pthread_mutex_unlock(&arr_mutex[philo->right]);
// 		}
// 		else
// 		{
// 			pthread_mutex_lock(&arr_mutex[philo->right]);
// 			printf("%d take a fork °%d\n", philo->id, philo->right);
// 			pthread_mutex_lock(&arr_mutex[philo->left]);
// 			printf("%d take a fork °%d\n", philo->id, philo->left);
// 			printf("%d eating\n", philo->id);
// 			usleep(200000);
// 			pthread_mutex_unlock(&arr_mutex[philo->right]);
// 			pthread_mutex_unlock(&arr_mutex[philo->left]);
// 		}
// 		//sleeping
// 		printf("%d sleeping\n", philo->id);
// 		usleep(200000);
// 		//thinking
// 		printf("%d thinking\n", philo->id);
// 	}
// 	return (NULL);
// }

// int	main(int argc, char **argv)
// {
// 	t_philo arr_philo[4];
// 	pthread_t arr_thread[4];
// 	;
// 	int i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		pthread_mutex_init(&arr_mutex[i], NULL);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		arr_philo[i].id = i;
// 		arr_philo[i].left = i;
// 		arr_philo[i].right = i + 1 % 4;
// 		pthread_create(&arr_thread[i], NULL, thread_routine, &arr_philo[i]);

// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		pthread_join(arr_thread[i], NULL);
// 		i++;
// 	}
// 	printf("end");
// 	return (0);
// }