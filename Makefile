NAME = libftprintf.a

SRCS 		= 	ft_printf.c			flags.c			initflags.c			\
				ft_putchar.c		ft_length.c		asterisk.c					\
				ft_putnbr.c			ft_putstr.c		pcnt.c				\
				integers.c			zero.c						\
				write_blanks.c		chars.c			hexadecimal.c		\
				ft_strlen.c			strings.c		pointers.c					\
				write_blanks_x.c	write_blanks_p.c	

GCC			= @gcc -Wall -Wextra -Werror
OBJS 		= $(SRCS:.c=.o)
INCLUDES 	= ./
all: $(NAME)
$(NAME) : $(SRCS) ft_printf.h
			$(GCC) -I$(INCLUDES) -c $(SRCS)
			-@ar rc $(NAME) $(OBJS)
			-@ranlib $(NAME)
test:	 
		$(GCC) -c $(SRCS)
		$(GCC) -o a.out main.c $(OBJS)
		./a.out
clean:
			-@$(RM) $(OBJS) 
fclean: clean
			-@$(RM) $(NAME)
re: 		fclean all