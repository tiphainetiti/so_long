#################################################
## COLORS
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

#################################################
## ARGUMENTS

NAME				= so_long
CFLAGS				= -Wall -Werror -Wextra -g3
CC					= cc
LIBFT				= libft
FT_PRINTF			= ft_printf


#################################################
## SOURCES

SRC_FILES		=	main \
					map_init \
					map_parsing \
					map_utils1 \
					map_utils2 \
					img \
					ft_error \
					game \
					game_utils \
					bonus_mov_count \
					bonus_enemy \

SRC_FILES_2			= 	


OBJ_FILES		= $(addsuffix .o, ${SRC_FILES})



#################################################
## RULES

all : ${NAME}

%.o : %.c
		@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ_FILES}
		@make --silent -C $(LIBFT)
		@make --silent -C $(FT_PRINTF)
		@make --silent -C mlx/
		@${CC} ${CFLAGS} ${OBJ_FILES} -L $(LIBFT) -lft -L $(FT_PRINTF) -lftprintf mlx/libmlx_Linux.a -L mlx -lXext -lX11 -lm -o ${NAME}
		@echo "$(GREEN)Compilation terminée!$(END) "

clean :
		@rm -f *.o
		@make clean --silent -C $(LIBFT)
		@make clean --silent -C $(FT_PRINTF)
		clear
		@echo "$(CYAN)C'est tout propre !$(END)"

fclean : clean
		@rm -f ${NAME}
#@make clean -C mlx/
		@make fclean --silent -C $(LIBFT)
		@make fclean --silent -C $(FT_PRINTF)

re : fclean all

.PHONY : all clean fclean re