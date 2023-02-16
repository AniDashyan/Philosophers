/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:48:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/14 21:11:58 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo, pthread_mutex_t *forks, char **argv, int argc)
{
	init_fork(forks, argv);
	init_philo(philo, forks, argv, argc);
}

int	philo_work(t_philo *philo, pthread_mutex_t *forks)
{
	int				i;

	while (1)
	{
		i = -1;
		while (++i < philo->number_of_philos)
		{
			if (is_dead(&philo[i]) || stop_philos(philo))
			{
				free_philo(philo, forks);
				return (1);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if ((argc == 5 || argc == 6) && check_arg(argv, argc) == 1)
	{
		forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
		if (!forks)
			error("Error: Can't allocate memory!\n");
		philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!philo)
			error("Error: Can't allocate memory!\n");
		init(philo, forks, argv, argc);
		philo_work(philo, forks);
	}
	else
		error("Invalid arguments!\n");
	return (0);
}
