NAME = minishell
LIBFT = ./libft

SRCS = main.c \
		ft_split_shell.c \
		ft_split_to_tok.c \
		ft_split_to_tok_2.c \
		ft_set_rdir.c \
		exec_addons.c \
		executing.c \
		list.c		\
		ft_builtin_switch.c \
		free.c	\
		init.c	\
		semicolon.c \
		addons.c \
		get_next_line_ext.c \
		ft_clean_quotes.c \
		var_exhange.c	\
		validity_check.c \
		ft_set_rdir_addons.c \
		ft_split_shell_addons.c \
		builtins/builtin_addons.c \
		builtins/cd.c \
		builtins/echo.c \
		builtins/env.c \
		builtins/exit.c \
		builtins/export.c \
		builtins/pwd.c \
		builtins/unset.c


OBJ = main.o \
		ft_split_shell.o \
		ft_split_to_tok.o \
		ft_split_to_tok_2.o \
		ft_set_rdir.o	\
		exec_addons.o \
		executing.o \
		list.o		\
		builtins/*.o \
		free.o	\
		init.o	\
		semicolon.o \
		addons.o \
		get_next_line_ext.o \
		ft_clean_quotes.o \
		var_exhange.o \
		validity_check.o \
		ft_set_rdir_addons.o \
		ft_split_shell_addons.o \
		builtins/builtin_addons.o \
		builtins/cd.o \
		builtins/echo.o \
		builtins/env.o \
		builtins/exit.o \
		builtins/export.o \
		builtins/pwd.o \
		builtins/unset.o

FLAGS = -Wall -Wextra -Werror

CC	  = gcc

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFT)
	$(CC) $^ -Llibft -lft -o $(NAME) $(FLAGS)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

run: re
	./minishell
