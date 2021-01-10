NAME = libasm.a
SRC = ft_strlen.s \
      ft_strcpy.s \
      ft_strcmp.s \
      ft_write.s \
      ft_read.s \
      ft_strdup.s
SRC_B = ft_atoi_base_bonus.s \
	ft_list_push_front_bonus.s \
	ft_list_size_bonus.s \
	ft_list_sort_bonus.s \
	ft_list_remove_if_bonus.s
OBJ = $(SRC:.s=.o)
OBJ_B = $(SRC_B:.s=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ_B) $(OBJ)
	ar rc $(NAME) $(OBJ_B) $(OBJ)
	ranlib $(NAME)

%.o : %.s
	nasm -f elf64 $< -o $@

clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME)
	rm -rf main main_bonus

re : fclean all

main : $(NAME)
	gcc main.c $(NAME) -o $@ -no-pie

main_bonus : bonus
	gcc main_bonus.c $(NAME) -o $@ -no-pie
