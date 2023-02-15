/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:47:58 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/14 21:38:08 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, char **argv, int argc, int *i)
{
	philo[*i].number_of_philos = ft_atoi(argv[1]);
	philo[*i].time_to_die = ft_atoi(argv[2]);
	philo[*i].time_to_eat = ft_atoi(argv[3]);
	philo[*i].time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo[*i].number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo[*i].number_of_times_each_philo_must_eat = -1;
}

void	init_fork(pthread_mutex_t *forks, char **argv)
{
	int	i;
	int	err;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		err = pthread_mutex_init(&forks[i], NULL);
		if (err != 0)
		{
			printf("mutex: %d\n", err);
			error("Error: Can't create mutex");
		}
		i++;
	}
}

void	init_philo(t_philo *philo, pthread_mutex_t *forks,
	char **argv, int argc)
{
	int				i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		init_data(philo, argv, argc, &i);
		philo[i].index = i + 1;
		philo[i].eat_count = 0;
		philo[i].last_eat = get_time();
		philo[0].left_fork = &forks[philo->number_of_philos - 1];
		philo[i].left_fork = &forks[i - 1];
		philo[i].right_fork = &forks[i];
		if (philo->number_of_philos == 1)
			philo[i].left_fork = &forks[i];
		if (pthread_create(&philo[i].id, NULL, (void *)routine, &philo[i]) != 0)
			error("Error: Can't create thread\n");
		if (pthread_detach(philo[i].id) != 0)
			error("Error: Can't detach thread\n");
	}
}

/* i = 0;
while (i < philo->number_of_philos)
{
	if (i == philo->number_of_philos - 1)
	{
		if (philo[i].right_fork != philo[0].left_fork)
			printf("false__\n");
		else
			printf("%p == %p\n", philo[i].right_fork, philo[0].left_fork);
	}
	else if (philo[i].right_fork != philo[i + 1].left_fork)
		printf("false\n");
	else
		printf("%p == %p\n", philo[i].right_fork, philo[i + 1].left_fork);
	i++;
} */