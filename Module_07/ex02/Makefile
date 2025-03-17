# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algultse <algultse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 22:14:00 by algultse          #+#    #+#              #
#    Updated: 2025/03/07 22:20:21 by algultse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = ./obj/
SRCDIR = ./srcs/
INCDIR = ./include/

SRC = main.cpp
SRC_42 = main-42.cpp

OBJS = $(SRC:%.cpp=$(OBJDIR)%.o)
OBJS_42 = $(SRC_42:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

42: $(NAME)-42

$(NAME)-42: $(OBJS_42)
	$(CXX) $(CXXFLAGS) $(OBJS_42) -o $(NAME)-42

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(NAME)-42

re: fclean all

.PHONY: all 42 clean fclean re