NAME = rtv1

SRCS = srcs/main.c srcs/input_manager.c srcs/vector_manager.c \
	srcs/color_manager.c srcs/matrix_manager.c srcs/matrix_manager_2.c \
	srcs/transformation.c srcs/matrix_determinant.c srcs/matrix_putmatrix.c \
	srcs/matrix_submatrix.c srcs/intersections.c srcs/ray_manager.c

OFILES = main.o

all: $(NAME)

$(NAME):
	@echo creating library...
	@make -C libft
	@echo compiling..
	@gcc $(SRCS) libft/libft.a -lpthread -o $(NAME) -I includes -l mlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
	@echo $(NAME) created

cata:
	@make -C libft
	@echo compiling ..
	@gcc $(SRCS) libft/libft.a -lpthread -I /usr/X11/include -I includes -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(NAME) created

clean:
	@echo cleaning...
	@rm -f $(OFILES)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make fclean -C libft

re: fclean all
