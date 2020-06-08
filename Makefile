NAME = rtv1

SRCS = 	srcs/main.c \
		srcs/rtv_init.c \
		srcs/input_manager.c \
		srcs/ppm.c \
		srcs/vectors/vector_manager.c \
		srcs/vectors/vector_calculation.c \
		srcs/vectors/vector_calculation_2.c \
		srcs/colors/color_manager.c \
		srcs/colors/color_convert.c \
		srcs/matrix/matrix_manager.c \
		srcs/matrix/matrix_manager_2.c \
		srcs/matrix/matrix_determinant.c \
		srcs/matrix/matrix_putmatrix.c \
		srcs/matrix/matrix_submatrix.c \
		srcs/transformation.c \
		srcs/new_intersect.c \
		srcs/ray_manager.c \
		srcs/sphere.c \
		srcs/light.c \
		srcs/tuples.c \
		srcs/world.c \
		srcs/view_transform.c \
		srcs/camera.c \
		srcs/prepare_computation.c \
		srcs/lighting.c \
		srcs/objects/shape.c \
		srcs/scene.c \
		srcs/objects/plane.c \
		srcs/objects/cube.c \
		srcs/objects/cylinder.c \
		srcs/objects/cone.c

OFILES = $(SRCS:.c=.o)

.PHONY: all clean

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
	@echo clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make fclean -C libft

re: fclean all
