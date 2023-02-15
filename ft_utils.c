/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:48:04 by adashyan          #+#    #+#             */
/*   Updated: 2023/02/10 14:48:05 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{	
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

void	error(char *msg)
{	
	ft_putstr_fd(msg, 2);
	return ;
}