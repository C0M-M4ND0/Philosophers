# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:18:01 by oabdelha          #+#    #+#              #
#    Updated: 2022/03/31 08:47:25 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = main.c ft_atoi.c checking.c initialization.c get_time.c threads.c routine.c utils.c

CNVRT = $(SRC:.c=.o)

HEADER = philo.h

all: $(NAME)

$(NAME): $(CNVRT) $(HEADER)
	@$(CM) $(FLAG) $(CNVRT) -lpthread -o philo

%.o : %.c $(HEADER)
	@$(CM) $(FLAG) -o $@  -c $<

clean:
	@rm -rf $(CNVRT) philo
	
fclean: clean
	@rm -rf $(NAME)
	
norm:
	@norminette $(SRC) $(HEADER)
re: fclean all
