#################################################
## ARGUMENTS

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= cc
AR				= ar -rcs
LIBFT			= libft

#################################################
## SOURCES

SRC_FILES		= ft_printf \
				ft_print_char \
				ft_print_str \
				ft_print_nbr \
				ft_print_ptr \
				ft_print_hexa \
				ft_print_unsigned \
				ft_putchar \

OBJ_FILES		= $(addsuffix .o, ${SRC_FILES})

#################################################
## RULES

all : ${NAME}

${NAME} : ${OBJ_FILES}
		make -C $(LIBFT)
		cp $(LIBFT)/libft.a ${NAME}
		${AR} ${NAME} ${OBJ_FILES}

%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

clean :
		rm -f *.o
		make clean -C $(LIBFT)

fclean : clean
		rm -f ${NAME}
		make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re