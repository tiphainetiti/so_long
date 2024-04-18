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
CFLAGS				= -Wall -Werror -Wextra -O3 -g3
CC					= cc
LIBFT				= libft
BUILD				= objs/
INCLUDE				= so_long.h


#################################################
## SOURCES

SRC_FILES		=	main \
					struct_init \
					map_init \
					map_parsing \
					map_utils1 \
					map_utils2 \
					img \
					img_load \
					ft_error \
					game \
					game_utils \
					map_parsing_enemy \
					bonus_mov_count \
					bonus_enemy \
					animations \

SRC			= 	$(addprefix srcs/, $(SRC_FILES))


OBJ_FILES		= $(addprefix $(BUILD), $(addsuffix .o, $(SRC_FILES)))



#################################################
## RULES

${NAME} : ${OBJ_FILES} $(INCLUDES)
	@make --silent -C $(LIBFT)
	@make --silent -C mlx/
	@${CC} ${CFLAGS} ${OBJ_FILES} -L $(LIBFT) -lft mlx/libmlx_Linux.a -L mlx -lXext -lX11 -lm -o ${NAME}
	@echo "$(GREEN)Compilation done!$(END)"

objs/%.o: srcs/%.c
	@mkdir -p ${BUILD}
	@${CC} ${CFLAGS} -c $< -o $@
#@echo "$(YELLOW)Object's compilation done.$(END)"

all : ${NAME}

clean :
	@rm -rf $(BUILD)*.o
	@make clean --silent -C $(LIBFT)
	clear
	@echo "$(CYAN)All clean !$(END)"

fclean : clean
	@rm -f ${NAME}
#@make clean -C mlx/
	@make fclean --silent -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re