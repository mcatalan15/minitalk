# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:10:12 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/07/20 12:53:40 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BONUS = .bonus

CFLAGS = -Wall -Wextra -Werror

LIBFT_D = libft/
LIBFT = libft.a

NSERVER = server
NCLIENT = client

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

DEPS_S = $(SRCS_S:.c=.d)
DEPS_C = $(SRCS_C:.c=.d)


#OBJSBONUS = $(SRCSB:.c=.o)

INCLUDE = -I ./

RM = rm -f

#DEPS_BONUS = $(SRCSB:.c=.d)


all: makelibft $(NSERVER) $(NCLIENT)

makelibft:
	@make --no-print-directory -C $(LIBFT_D)

%.o: %.c
	${CC} ${CFLAGS} -MMD $(INCLUDE) -c $< -o $@

# SERVER

$(NSERVER): $(OBJS_S) $(LIBFT_D)$(LIBFT)

	ar -rcs $(NSERVER) $(OBJS_S)

-include $(DEPS_S)

# CLIENT

$(NCLIENT): $(OBJS_C) $(LIBFT_D)$(LIBFT)

	ar -rcs $(NCLIENT) $(OBJS_C)

-include $(DEPS_C)

# bonus: $(BONUS)

# $(BONUS) : $(OBJS) $(OBJSBONUS)

# 	ar -rcs $(NAME) $(OBJS) $(OBJSBONUS)

# -include $(DEPS_BONUS)

clean:
	@make clean --no-print-directory -C $(LIBFT_D)
	$(RM) $(OBJS_S) $(OBJS_C) $(DEPS_S) $(DEPS_C)

fclean: clean
	$(RM) $(NSERVER) $(NCLIENT) $(LIBFT_D)

re: fclean all

.PHONY: all clean fclean re makelibft