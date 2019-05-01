NAME = ft_ls

$(NAME):
	@gcc  -c -Wall -Werror -Wextra arg_files.c tabs_to_free.c collect.c errors.c file_op.c ft_ls.c ft_r.c ft_t.c ls_l.c print.c put.c sort.c tools.c
	@make -C ft_printf
	@gcc *.o ./ft_printf/libftprintf.a -o $(NAME)
all: $(NAME)

clean:
	@make clean -C ft_printf
	@rm -f *.o
	
fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean  all
