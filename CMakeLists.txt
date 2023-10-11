cmake_minimum_required(VERSION 3.21)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)

add_executable(push_swap
        includes/ft_printf.h
        includes/push_swap.h
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_calloc.c
        libft/ft_free_str.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmapi.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strtrim.c
        libft/ft_substr.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        src/check/check.c
        src/check/check_errors.c
        src/ft_printf/ft_printf.c
        src/ft_printf/s_c_p_d_i.c
        src/ft_printf/u_x_X.c
        src/init/free_utils.c
        src/init/init_list.c
        src/operation/push.c
        src/operation/reverse_rotate.c
        src/operation/rotate.c
        src/operation/swap.c
        src/sorting/index.c
        src/sorting/sorting_more.c
        src/sorting/sorting_under_5.c
        src/sorting/sorting_under_5_bis.c
        src/main.c
        src/utils.c
        src/utils_bis.c)
