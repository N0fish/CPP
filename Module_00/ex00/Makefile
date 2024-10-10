# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algultse <algultse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 21:44:44 by algultse          #+#    #+#              #
#    Updated: 2024/10/10 15:38:02 by algultse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = ./obj/
SRCDIR = ./

SRC =  megaphone.cpp
OBJS = $(SRC:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re