# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:10:12 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/10/04 12:38:34 by mcatalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_D = libft/
LIBFT = libft.a

FT_PRINTF_D = ft_printf/
FT_PRINTF = libftprintf.a

NSERVER = server
NCLIENT = client

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

DEPS_S = $(SRCS_S:.c=.d)
DEPS_C = $(SRCS_C:.c=.d)

INCLUDE = -I./
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: makelibft $(NSERVER) $(NCLIENT)

makelibft:
	@make --no-print-directory -C $(LIBFT_D)

makeftprintf:
	@make --no-print-directory -C $(FT_PRINTF_D)

%.o: %.c
	${CC} ${CFLAGS} -MMD $(INCLUDE) -c $< -o $@

# SERVER

$(NSERVER): $(OBJS_S) $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_S) -o $@ $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
-include $(DEPS_S)

# CLIENT

$(NCLIENT): $(OBJS_C) $(LIBFT_D)$(LIBFT)  $(FT_PRINTF_D)$(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_C) -o $@ $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
-include $(DEPS_C)

clean:
	@make clean --no-print-directory -C $(LIBFT_D)
	@make clean --no-print-directory -C $(FT_PRINTF_D)
	$(RM) $(OBJS_S) $(OBJS_C) $(DEPS_S) $(DEPS_C)

fclean: clean
	$(RM) $(NSERVER) $(NCLIENT) $(DEPS_C) $(DEPS_S)

re: fclean all

.PHONY: all clean fclean re makelibft makeftprintf