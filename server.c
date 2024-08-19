/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:43:17 by filferna          #+#    #+#             */
/*   Updated: 2024/08/19 17:54:25 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	binary_convert(char *str)
{
	int		bits;
	int		i;
	char	c;

	if (ft_strlen(str) < 7)
		return ('-');
	i = 0;
	c = 0;
	bits = 7;
	while (str[i])
	{
		if (str[i] == '1')
			c = (c ^ 1 << bits);
		bits--;
		i++;
	}
	return (c);
}

void	ft_welcome(int id)
{
	ft_printf("\033[0;32m ___ __ __    ________  ___   __     ________  _________  ________   __       ___   ___     \n");
	ft_printf("/__//_//_/\\  /_______/\\/__/\\ /__/\\  /_______/\\/________/\\/_______/\\ /_/\\     /___/\\/__/\\    \n");
	ft_printf("\\::\\| \\| \\ \\ \\__.::._\\/\\::\\_\\  \\ \\ \\__.::._\\/\\__.::.__\\/\\::: _  \\ \\:\\ \\    \\::.\\ \\ \\ \\   \n");
	ft_printf(" \\:.      \\ \\   \\::\\ \\  \\:. `-\\  \\ \\   \\::\\ \\    \\::\\ \\   \\::(_)  \\ \\:\\ \\    \\:: \\/_) \\ \\  \n");
	ft_printf("  \\:.\\-/\\  \\ \\  _\\::\\ \\__\\:. _    \\ \\  _\\::\\ \\__  \\::\\ \\   \\:: __  \\ \\:\\ \\____\\:. __  ( (  \n");
	ft_printf("   \\. \\  \\  \\ \\/__\\::\\__/\\. \\`-\\  \\ \\/__\\::\\__/\\  \\::\\ \\   \\:.\\ \\  \\ \\:\\/___/\\: \\ )  \\ \\ \n");
	ft_printf("    \\__\\/ \\__\\/\\________\\/ \\__\\/ \\__\\/\\________\\/   \\__\\/    \\__\\/\\__\\/ \\_____\\/ \\__\\/\\__\\/ \n");
	ft_printf("PID: [%d]\033[0;37m\n", id);
}

char	*join_bit(char *str, char n)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char) + 1);
		str[i] = n;
		str[++i] = '\0';
		return (str);
	}
	new = (char *)malloc((ft_strlen(str) + 1) * sizeof(char) + 1);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = n;
	new[++i] = '\0';
	free(str);
	return (new);
}

void	handler(int signal)
{
	static char	*str;
	static char	*string;

	if (signal == SIGUSR1)
		str = join_bit(str, '1');
	else
		str = join_bit(str, '0');
	if (ft_strlen(str) == 8 && !binary_convert(str))
	{
		ft_printf("%s\n", string);
		free(string);
		free(str);
		str = NULL;
		string = NULL;
		return ;
	}
	if (ft_strlen(str) == 8)
	{
		string = join_bit(string, binary_convert(str));
		free(str);
		str = NULL;
	}
	return ;
}

int	main(void)
{
	int	id;

	id = getpid();
	ft_welcome(id);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
