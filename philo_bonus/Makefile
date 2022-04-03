# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:18:01 by oabdelha          #+#    #+#              #
#    Updated: 2022/04/02 10:51:52 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = main.c ft_atoi.c checking.c initialization.c get_time.c thread.c routine.c utils.c process.c

CNVRT = $(SRC:.c=.o)

HEADER = philo_bonus.h

all: $(NAME)

$(NAME): $(CNVRT) $(HEADER)
	@$(CM) $(FLAG) $(CNVRT) -lpthread -o philo_bonus

%.o : %.c $(HEADER)
	@$(CM) $(FLAG) -o $@  -c $<

clean:
	@rm -rf $(CNVRT) philo_bonus
	
fclean: clean
	@rm -rf $(NAME)
	
norm:
	@norminette $(SRC) $(HEADER)
re: fclean all
