NAME = libft.a

ITOA_VARIATIONS_PATH = ./itoa-variations
PRINTER_FACTORY_PATH = ./printer-factory

SRCS = \
	$(ITOA_VARIATIONS_PATH)/ft_itoa_variations.c\
	$(ITOA_VARIATIONS_PATH)/ft_itoa_utils.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_char.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_str.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_decimal_int.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_decimal_unsigned_int.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_hexadecimal_lower.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_hexadecimal_upper.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_percent.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_memory_address.c\
	ft_atoi.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_putendl_fd.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_putnbr_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_calloc.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_putstr_fd.c \
	ft_strjoin.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_itoa.c \
	ft_memset.c \
	ft_split.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_putchar_fd.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strrchr.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstpop.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstmap.c\
	ft_lstiter.c \
	ft_printf.c
	
FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: %.c
	cc ${FLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: clean fclean all

so:
	cc -nostartfiles -fPIC $(FLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
