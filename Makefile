#Variables
NAME	= miniRT
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	=  -g -Werror -Wall -Wextra -I include/
CC		= gcc
RM		= rm -f

#Include
INCLUDE_DIR	= include/

#Libft
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

#MinniLibx
#MLX_A		= libmlx.a
#MLX_DIR		= mlx/
#MLX			= $(addprefix $(MLX_DIR), $(MLX_A))
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit 

#Sources Files
SRC_FILES =	miniRT ft_pixel_put\

#SRC
SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF	=	.cache_exists


### Couleurs et fonctionnalités texte:

CURSOR_UP_1	= \033[1A
CURSOR_UP	= \033[2A
CURSOR_DOWN	= \033[1B

END         = \033[0m
BOLD        = \033[1m
ITALIC      = \033[3m
URL         = \033[4m
BLINK       = \033[5m
BLINK2      = \033[6m
SELECTED    = \033[7m

BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
VIOLET      = \033[35m
BEIGE       = \033[36m
WHITE       = \033[37m

#--------------------------------------------------------#
###-----------------------Rules------------------------###

all	: $(NAME)

$(NAME):	$(OBJ)	
	@echo "$(BOLD)$(VIOLET)$(CURSOR_UP_1)                                                                    $(CURSOR_DOWN)\n\nCOMPILER: $(GREEN)$(SELECTED)SOURCES DONE!$(END) 💎                            \n"
	@echo "$(BOLD)$(WHITE)\n-------LIBRARIES------                      \n$(CURSOR_DOWN)                                        $(END) "
		#-@make -C $(MLX_DIR)
		@echo "$(CURSOR_UP)$(BOLD)$(VIOLET)COMPILER: $(GREEN)$(SELECTED)MLX DONE!$(END)🕹                                                     "
		#@echo "$(CURSOR_DOWN)"
		-@make -C $(LIBFT_DIR)
		@echo "$(CURSOR_UP_1)$(BOLD)$(VIOLET)COMPILER: $(GREEN)$(SELECTED)LIBFT DONE!$(END)⚙️                                                    "
		-@$(CC) $(OBJ) -L. $(LIBFT) $(MLX_FLAGS) -o $(NAME)
		@sleep 1
		@echo "$(CURSOR_UP_1)$(CURSOR_DOWN)$(BOLD)$(RED)$(SELECTED)\nExecutable miniRT has descended upon the world...$(END)                     "

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	@echo "$(RED)$(BOLD)$(CURSOR_UP)Compiling...$(GREEN) $< ..$(END)            "
			-@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -Imlx -c $< -o $@

$(OBJF)	:
			@mkdir -p $(OBJ_DIR)

clean	:
			@$(RM) -r $(OBJ_DIR)
#			@make -C $(MLX_DIR) clean
			@make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJF)

fclean	:	clean
			@$(RM) $(NAME) $(LIBFT)

val:
		valgrind   --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --trace-children=yes ./$(NAME)

re		: fclean all

