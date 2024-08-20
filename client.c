/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:46:31 by filferna          #+#    #+#             */
/*   Updated: 2024/08/20 12:06:16 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	adaptive_sleep(int len)
{
	if (len <= 10000)
		return (50);
	else if (len <= 30000)
		return (100);
	else if (len <= 60000)
		return (300);
	else if (len <= 100000)
		return (500);
	else
		return (10000);
}

void	str_sender(char *str, int id)
{
	char	temp;
	int		bits;
	int		len;
	int		i;

	len = ft_strlen(str) + 1;
	i = 0;
	bits = 7;
	while (len--)
	{
		temp = str[i];
		while (bits >= 0)
		{
			if (temp >> bits & 1)
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			bits--;
			usleep(adaptive_sleep(ft_strlen(str)));
		}
		i++;
		bits = 7;
	}
	usleep(ft_strlen(str));
	return ;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 3)
		return (ft_printf("Error: use (./client server pid \"sentece\")"));
	str_sender(av[2], ft_atoi(av[1]));
	return (0);
}
