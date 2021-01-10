#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct			s_list
{
	void		*data;
	struct s_list	*next;
}				t_list;

int     ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int	ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void*));

//ft_atoi_base
void	ft_atoi_base_test(void)
{
	char	*str = "1010";
	char	*base = "1";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));
	
	str = "1010";
	base = "01 ";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));
	
	str = "1010";
	base = "\n01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "1010";
	base = "-01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "1010";
	base = "0+1";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "1010";
	base = "011";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "1010";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = " \t\n 1010";
	base = "0123456789";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  a 1010";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  0";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t -baba";
	base = "ab";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t +--1010";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t +-++-+-10000000ab01";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t +-++-+-11111111ab01";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t --+FFilo";
	base = "0123456789ABCDEF";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t --+FFFFilo";
	base = "0123456789ABCDEF";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t ---2147483648  ";
	base = "0123456789";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t \r-10000000000000000000000000000000  ";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

	str = "  \t \r--1111111111111111111111111111111  ";
	base = "01";
	printf("str : |%s|\n", str);
	printf("base: |%s|\n", base);
	printf("res : %d\n\n", ft_atoi_base(str, base));

}

// ft_list_push_front
void	ft_list_push_front_test(void)
{
	t_list	*elem = 0;
	int	data_int = 10;
	char	*data_str = "Hello";
	char	data_char = 'A';

	printf("Before ft_list_push_front call\n");
	printf("                         elem : %p\n", elem);
	printf("                     data_int : %d\n", data_int);
	printf("                     data_str : %s\n", data_str);
	printf("                    data_char : %c\n\n", data_char);
	
	printf("ft_list_push_front(&elem, &data_int)\n");
	ft_list_push_front(&elem, &data_int);
	printf("                         elem : %p\n", elem);
	printf("                    &data_int : %p\n", &data_int);
	printf("                   elem->data : %p\n", elem->data);
	printf("            *(int*)elem->data : %d\n", *(int*)elem->data);
	printf("                   elem->next : %p\n\n", elem->next);
	
	printf("ft_list_push_front(&elem, data_str)\n");
	ft_list_push_front(&elem, data_str);
	printf("                         elem : %p\n", elem);
	printf("                     data_str : %p\n", data_str);
	printf("                   elem->data : %p\n", elem->data);
	printf("            (char*)elem->data : %s\n", (char*)elem->data);
	printf("                   elem->next : %p\n\n", elem->next);
	
	printf("ft_list_push_front(&elem, &data_char)\n");
	ft_list_push_front(&elem, &data_char);
	printf("                         elem : %p\n", elem);
	printf("                   &data_char : %p\n", &data_char);
	printf("                   elem->data : %p\n", elem->data);
	printf("           *(char*)elem->data : %c\n", *(char*)elem->data);
	printf("                   elem->next : %p\n\n", elem->next);

	printf("             elem->next->next : %p\n", elem->next->next);
	printf("       elem->next->next->data : %p\n", elem->next->next->data);
	printf("*(int*)elem->next->next->data : %d\n", *(int*)elem->next->next->data);
	printf("       elem->next->next->next : %p\n\n", elem->next->next->next);
	
}

// ft_list_size
void	ft_list_size_test(void)
{
	t_list	*elem = 0;
	int	data = 10;
	int	i = 0;
	int	res;

	while (i < 5)
	{
		printf("ft_list_push_front nb of calls = %d\n", i);
		printf("                 list size res = %d\n\n", ft_list_size(elem));
		ft_list_push_front(&elem, &data);
		i++;
	}
}

// ft_list_sort
int	ft_ascending_order(void *d1, void *d2)
{
	int	res;

	res = (*(int*)d1 > *(int*)d2) ? 1 : 0;
	return (res);
}

void	ft_list_sort_test(void)
{
	t_list	*elem = 0;
	t_list	*temp = 0;
	int	nb[5];
	int 	i = 0;
	int	i_temp;

	while (i < 5)
	{
		nb[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("ft_list_push_front nb of calls = %d\n", i);
		ft_list_sort(&elem, &ft_ascending_order);
		temp = elem;
		i_temp = 0;
		while (temp)
		{
			printf("*(int*)elem->(next * %d)->data = %d\n", i_temp, *(int*)temp->data);
			temp = temp->next;
			i_temp++;
		}
		printf("\n");
		ft_list_push_front(&elem, &nb[i]);
		i < 4 ? printf("Adding int %d in front\n", nb[i]) : 0;
		i++;
	}
	printf("Already sorted list\n");
	elem = 0;
	i = 4;
	while (i >= 0)
	{
		ft_list_push_front(&elem, &nb[i]);
		i--;
	}
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %d\n", i_temp, *(int*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	printf("\nCall ft_list_sort\n");
	ft_list_sort(&elem, &ft_ascending_order);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %d\n", i_temp, *(int*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	printf("\nRandom list\n");
	int	n = 1;
	elem = 0;
	ft_list_push_front(&elem, &nb[1]);
	ft_list_push_front(&elem, &nb[0]);
	ft_list_push_front(&elem, &n);
	ft_list_push_front(&elem, &nb[2]);
	ft_list_push_front(&elem, &nb[3]);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %d\n", i_temp, *(int*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	printf("\nCall ft_list_sort\n");
	ft_list_sort(&elem, &ft_ascending_order);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %d\n", i_temp, *(int*)temp->data);
		temp = temp->next;
		i_temp++;
	}
}

// ft_list_remove_if
int	ft_cmp_nb(char *a, char *b)
{
	if (*a == *b)
		return (0);
	return (1);
}

int	ft_greater_eq_nb(char *a, char *b)
{
	if (*a >= *b)
		return (0);
	return (1);
}

void	ft_free(void *a)
{
	free(a);
}

void	ft_list_remove_if_test(void)
{
	t_list	*elem = 0;
	t_list	*temp = 0;
	char	**data;
	int	data_ref;
	int 	i = 0;
	int	i_temp;

	data = (char**)malloc(sizeof(char*) * 10);
	while (i < 10)
	{
		data[i] = (char*)malloc(sizeof(char) * 1);
		data[i][0] = i + 'A';
		i++;
	}
	i = 9;
	printf("Create list\n");
	while (i >= 0)
	{
		ft_list_push_front(&elem, data[i]);
		i--;
	}
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(char*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data = A\n");
	char	a = 'A';
	ft_list_remove_if(&elem, &a, &ft_cmp_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(char*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data = C\n");
	int	c = 'C';
	ft_list_remove_if(&elem, &c, &ft_cmp_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data = J\n");
	int	j = 'J';
	ft_list_remove_if(&elem, &j, &ft_cmp_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data = T\n");
	int	t = 'T';
	ft_list_remove_if(&elem, &t, &ft_cmp_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data >= G\n");
	int	g = 'G';
	ft_list_remove_if(&elem, &g, &ft_greater_eq_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	
	printf("\nRemove elem if elem->data >= B\n");
	int	b = 'B';
	ft_list_remove_if(&elem, &b, &ft_greater_eq_nb, &ft_free);
	i_temp = 0;
	temp = elem;
	while (temp)
	{
		printf("*(int*)elem->(next * %d)->data = %c\n", i_temp, *(char*)temp->data);
		temp = temp->next;
		i_temp++;
	}
	printf("elem = %p\n\n", temp);
}

int	main(int ac, char **av)
{
        if (ac == 1)
		printf("Not enough arg\n");
	else if (strcmp(av[1], "atoi_base") == 0)
		ft_atoi_base_test();
	else if (strcmp(av[1], "list_push_front") == 0)
		ft_list_push_front_test();
	else if (strcmp(av[1], "list_size") == 0)
		ft_list_size_test();
	else if (strcmp(av[1], "list_sort") == 0)
		ft_list_sort_test();
	else if (strcmp(av[1], "list_remove_if") == 0)
		ft_list_remove_if_test();
	return (0);
}
