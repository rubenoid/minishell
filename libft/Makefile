# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-sch <rvan-sch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 18:04:22 by rvan-sch          #+#    #+#              #
#    Updated: 2020/07/04 18:42:52 by rvan-sch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS=-Wall -Wextra -Werror -g

HFILES=-I get_next_line/

CFILES = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_dec_length.c \
	ft_hex_length.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_line_length.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strjoin_freefirst.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstsize_bonus.c \
	get_next_line/get_next_line.c \
    ft_printf/char_str_functions.c \
	ft_printf/ft_abs.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar_amount.c \
	ft_printf/ft_putnbr_ull.c \
	ft_printf/ft_putnbr_hex.c \
	ft_printf/ft_putstr.c \
	ft_printf/get_conv.c \
	ft_printf/get_flags.c \
	ft_printf/nbr_length_ull.c \
	ft_printf/parse_conv_csxup.c \
	ft_printf/parse_conv_d.c \
	ft_printf/print_char.c \
	ft_printf/print_digit.c \
	ft_printf/print_digit_p2.c \
	ft_printf/print_str.c

TEMP1=$(CFILES:get_next_line/%=%)
TEMP2=$(TEMP1:ft_printf/%=%)
OFILES=$(TEMP2:.c=.o)

all: $(NAME)

$(NAME):
	@echo "[+] libft: compiling sources ..."
	@gcc $(FLAGS) -c $(CFILES) $(HFILES)
	@echo "[+] libft: generating $(NAME)"
	@ar rcs $(NAME) $(OFILES)

clean:
	@echo "[-] libft: cleaning extra files ..."
	@rm -f $(OFILES)
	@rm -f *~
	@rm -f \#*#

fclean: clean
	@echo "[-] libft: removing $(NAME) ..."
	@rm -f $(NAME)

re: fclean all