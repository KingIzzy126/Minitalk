# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:03:21 by ialashqa          #+#    #+#              #
#    Updated: 2024/04/24 16:38:17 by ialashqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client 
NAMES = server 
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft/libft.a

SRC = client.c server.c utils.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = client_bonus.c server_bonus.c utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAMEC) $(NAMES)

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

$(LIBFT): 
	$(MAKE) -C ./libft

$(NAMEC): client.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) client.o utils.o $(LIBFT) -o $@

$(NAMES): server.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) server.o utils.o $(LIBFT) -o $@

$(NAMEC_BONUS): client_bonus.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) client_bonus.o utils.o $(LIBFT) -o $@

$(NAMES_BONUS): server_bonus.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) server_bonus.o utils.o $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAMEC) $(NAMES) $(NAMEC_BONUS) $(NAMES_BONUS)

re: fclean all

.PHONY: all clean fclean re