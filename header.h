/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:44:24 by filferna          #+#    #+#             */
/*   Updated: 2024/08/19 17:54:56 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <signal.h>

void	ft_welcome(int id);
char	binary_convert(char *str);
void	ft_welcome(int id);
void	str_sender(char *str, int id);
char	*join_bit(char *str, char n);
void	handler(int signal);

#endif