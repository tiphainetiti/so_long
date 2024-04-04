#################################################
## ARGUMENTS

NAME				= libft.a
CFLAGS				= -Wall -Werror -Wextra
CC					= cc
AR					= ar -rcs

#################################################
## SOURCES

SRC_FILES			= ft_atoi \
					ft_bzero \
					ft_calloc \
					ft_isalnum \
					ft_isalpha \
					ft_isascii \
					ft_isdigit \
					ft_isprint \
					ft_memchr \
					ft_memcmp \
					ft_memcpy \
					ft_memmove \
					ft_memset \
					ft_strchr \
					ft_strdup \
					ft_strlcat \
					ft_strlcpy \
					ft_strlen \
					ft_strncmp \
					ft_strnstr \
					ft_strrchr \
					ft_tolower \
					ft_toupper \
					ft_substr \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_strjoin \
					ft_strtrim \
					ft_itoa \
					ft_strmapi \
					ft_striteri \
					ft_split \

OBJ_FILES			= $(addsuffix .o, ${SRC_FILES})

SRC_BONUS			= ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap \

OBJ_BONUS			= $(addsuffix .o, ${SRC_BONUS})

#################################################
## RULES

${NAME} : ${OBJ_FILES}
		${AR} ${NAME} ${OBJ_FILES}

all : ${NAME}

%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

clean :
		rm -f *.o

fclean : clean
		rm -f ${NAME}

re : fclean all

bonus : ${OBJ_BONUS}
		${AR} ${NAME} ${OBJ_BONUS}

.PHONY : all clean fclean re