# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filferna <filferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 13:54:13 by filferna          #+#    #+#              #
#    Updated: 2024/08/05 15:00:13 by filferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SV = server.c

CL = client.c

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/libftprintf.a

COMPILER = cc

FLAGS = -Wall -Werror -Wextra


all:libs $(NAME)

$(NAME):

server: $(SV)
	$(COMPILER) $(FLAGS) $(SV) $(LIBFT) $(PRINTF) -o server
	
client: $(CL)
	$(COMPILER) $(FLAGS) $(CL) $(LIBFT) $(PRINTF) -o client

libs:
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf

re: fclean all

clean:
	rm -f server
	rm -f client

fclean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean
	rm -f server
	rm -f client
