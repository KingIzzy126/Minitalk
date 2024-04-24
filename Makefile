# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:03:21 by ialashqa          #+#    #+#              #
#    Updated: 2024/04/24 20:19:29 by ialashqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client 
NAMES = server 

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft/libft.a

SRC = client.c server.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAMEC) $(NAMES)

$(LIBFT): 
	$(MAKE) -C ./libft

$(NAMEC): client.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) client.o utils.o $(LIBFT) -o $@

$(NAMES): server.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) server.o utils.o $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAMEC) $(NAMES)

re: fclean all

.PHONY: all clean fclean re