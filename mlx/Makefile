#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11
#colours and text:

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

%.o:%.c
	@echo "$(RED)$(BOLD)$(CURSOR_UP_1)Compiling... $(BLUE) $<                                  "
	-@$(CC) -w $(CFLAGS) -o $@ -c $< 

%.o:%.m
	@echo "$(RED)$(BOLD)$(CURSOR_UP_1)Compiling... $(BLUE) $< $(END)                                   "
	-@$(CC) -w $(CFLAGS) -o $@ -c $< 

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "$(CURSOR_UP_1)                                      "
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
