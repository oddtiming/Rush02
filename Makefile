NAME		=	rush-02

CFILES		=	cleanup.c \
				dict_utils.c \
				dict.c \
				main.c \
				parse_utils.c \
				parse.c \
				print_number.c \
				utils.c \
				utils2.c


INC_DIR		=	include

SRC_DIR		=	srcs
SRCS		=	$(addprefix $(SRC_DIR)/, $(CFILES))

OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -I$(INC_DIR) -g

RM			=	rm -rf

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<


$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		fclean clean all re