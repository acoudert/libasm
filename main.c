#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

// ft_strlen
void	ft_strlen_test(void)
{
	char	*str1 = "";
	char	*str2 = "Hello";
	char	*str3 = "Hello, World !";

	printf("ft_strlen\n");
	printf("Ori len = %-2lu |%s|\n", strlen(str1), str1);
	printf("Rep len = %-2lu |%s|\n\n", ft_strlen(str1), str1);
	
	printf("Ori len = %-2lu |%s|\n", strlen(str2), str2);
	printf("Rep len = %-2lu |%s|\n\n", ft_strlen(str2), str2);
	
	printf("Ori len = %-2lu |%s|\n", strlen(str3), str3);
	printf("Rep len = %-2lu |%s|\n\n", ft_strlen(str3), str3);
}

void	ft_strlen_segfault(char *in)
{
	char	*str1 = 0;

	strcmp(in, "ori") == 0 ? strlen(str1) : ft_strlen(str1);
}

// ft_strcpy
void	tab_reinit(char *tab, int size)
{
	while (size > 0)
		tab[--size] = 0;
}

void	ft_strcpy_test(void)
{
	char	*src1 = "";
	char	*src2 = "Hello";
	char	*src3 = "Hello, World !";
	char	dest1[1];
	char	dest2[6];
	char	dest3[15];

	printf("ft_strcpy\n");

	printf("Src str = |%s|\n", src1);
	strcpy(dest1, src1);
	printf("Ori cpy = |%s|\n", dest1);
	tab_reinit(dest1, 1);
	ft_strcpy(dest1, src1);
	printf("Rep cpy = |%s|\n\n", dest1);

	printf("Src str = |%s|\n", src2);
	strcpy(dest2, src2);
	printf("Ori cpy = |%s|\n", dest2);
	tab_reinit(dest2, 6);
	ft_strcpy(dest2, src2);
	printf("Rep cpy = |%s|\n\n", dest2);

	printf("Src str = |%s|\n", src3);
	strcpy(dest3, src3);
	printf("Ori cpy = |%s|\n", dest3);
	tab_reinit(dest3, 15);
	ft_strcpy(dest3, src3);
	printf("Rep cpy = |%s|\n\n", dest3);
}

void	ft_strcpy_segfault(char *in, char *arg)
{
	if (strcmp(arg, "dest") == 0)
	{
		char	*src = "Hello";
		char	*dest = 0;
		strcmp(in, "ori") == 0 ? strcpy(dest, src) : ft_strcpy(dest, src);
	}
	else if (strcmp(arg, "src") == 0)
	{
		char	*src = 0;
		char	dest[6];
		strcmp(in, "ori") == 0 ? strcpy(dest, src) : ft_strcpy(dest, src);
	}
}

// ft_strcmp
void	ft_strcmp_test(void)
{
	char	*s1 = "";
	char	*s2 = "";
	char	*s3 = "Hello";
	char	*s4 = "Hello";
	int	ori;
	int	rep;

	printf("ft_strcmp\n");

	printf("|%s| |%s|\n", s1, s2);
	ori = strcmp(s1, s2);
	rep = ft_strcmp(s1, s2);
	printf("Ori = %d\nRep = %d\n\n", ori, rep);
	
	printf("|%s| |%s|\n", s3, s4);
	ori = strcmp(s3, s4);
	rep = ft_strcmp(s3, s4);
	printf("Ori = %d\nRep = %d\n\n", ori, rep);
	
	printf("|%s| |%s|\n", s1, s3);
	ori = strcmp(s1, s3);
	rep = ft_strcmp(s1, s3);
	printf("Ori = %d\nRep = %d\n\n", ori, rep);
	
	printf("|%s| |%s|\n", s3, s1);
	ori = strcmp(s3, s1);
	rep = ft_strcmp(s3, s1);
	printf("Ori = %d\nRep = %d\n\n", ori, rep);
}

void	ft_strcmp_segfault(char *in, char *arg)
{
	if (strcmp(arg, "s1") == 0)
	{
		char	*src = "Hello";
		char	*dest = 0;
		strcmp(in, "ori") == 0 ? strcmp(dest, src) : ft_strcmp(dest, src);
	}
	else if (strcmp(arg, "s2") == 0)
	{
		char	*src = 0;
		char	dest[6];
		strcmp(in, "ori") == 0 ? strcmp(dest, src) : ft_strcmp(dest, src);
	}
}

// ft_write
void	ft_write_test(void)
{
	int	ori;
	int	rep;
	int	fd_ori;
	int	fd_rep;

	printf("ft_write\n");
	printf("(ft_)write(1, \"Hello\", 5)\n");
	errno = 0;
	ori = write(1, "Hello", 5);
	printf("| ori = %d | err = %s\n", ori, strerror(errno));
	errno = 0;
	rep = ft_write(1, "Hello", 5);
	printf("| rep = %d | err = %s\n", rep, strerror(errno));
	printf("\n");
	
	printf("(ft_)write(1, \"Hello\", 0)\n");
	errno = 0;
	ori = write(1, "Hello", 0);
	printf("| ori = %d | err = %s\n", ori, strerror(errno));
	errno = 0;
	rep = ft_write(1, "Hello", 0);
	printf("| rep = %d | err = %s\n", rep, strerror(errno));
	printf("\n");

	fd_ori = open("test_ori.txt", O_CREAT | O_WRONLY, 0644);
	fd_rep = open("test_rep.txt", O_CREAT | O_WRONLY, 0644);
	
	printf("(ft_)write(fd_ori/rep, \"Hello\\n\", 0)\n");
	write(fd_ori, "Hello\n", 6);
	ft_write(fd_rep, "Hello\n", 6);
	printf("Cmd: `cat test*`\n");
	system("cat test*");
	printf("Cmd: `rm test*`\n\n");
	system("rm test*");
	close(fd_ori);
	close(fd_rep);

	printf("(ft_)write(-1, \"Hello\\n\", 6)\n");
	errno = 0;
	ori = write(-1, "Hello\n", 6);
	printf("| ori = %d | err = %s\n", ori, strerror(errno));
	errno = 0;
	rep = ft_write(-1, "Hello\n", 0);
	printf("| rep = %d | err = %s\n", rep, strerror(errno));
	printf("\n");

	printf("(ft_)write(1, \"Salut\", 10)\n");
	errno = 0;
	ori = write(1, "Salut", 10);
	printf("| ori = %d | err = %s\n", ori, strerror(errno));
	errno = 0;
	rep = ft_write(1, "Salut", 10);
	printf("| rep = %d | err = %s\n", rep, strerror(errno));
	printf("\n");
	
	printf("(ft_)write(1, \"Hello\", 2000000000000000)\n");
	errno = 0;
	ori = write(1, "Hello", 2000000000000000);
	printf("| ori = %d | err = %s\n", ori, strerror(errno));
	errno = 0;
	rep = ft_write(1, "Hello", 2000000000000000);
	printf("| rep = %d | err = %s\n", rep, strerror(errno));
	printf("\n");
}

// ft_read
void	ft_read_test(void)
{
	int	ori;
	int	rep;
	int	fd_ori;
	int	fd_rep;
	char	dest_ori[10];
	char	dest_rep[10];

	printf("ft_read\n");
	tab_reinit(dest_ori, 10);
	tab_reinit(dest_rep, 10);
	printf("(ft_)read(0, dest_ori/rep, 5)\n");
	errno = 0;
	ori = read(0, dest_ori, 5);
	printf("'%s'| ori = %d | err = %s\n", dest_ori, ori, strerror(errno));
	errno = 0;
	rep = ft_read(0, dest_rep, 5);
	printf("'%s'| rep = %d | err = %s\n", dest_rep, rep, strerror(errno));
	printf("\n");
	
	tab_reinit(dest_ori, 10);
	tab_reinit(dest_rep, 10);
	errno = 0;
	fd_ori = open("main.c", O_RDONLY);
	fd_rep = open("main.c", O_RDONLY);
	printf("(ft_)read(fd_ori/rep, dest_ori/rep, 5)\n");
	ori = read(fd_ori, dest_ori, 5);
	printf("'%s'| ori = %d | err = %s\n", dest_ori, ori, strerror(errno));
	errno = 0;
	rep = ft_read(fd_rep, dest_rep, 5);
	printf("'%s'| rep = %d | err = %s\n", dest_rep, rep, strerror(errno));
	printf("\n");

	tab_reinit(dest_ori, 10);
	tab_reinit(dest_rep, 10);
	errno = 0;
	printf("(ft_)read(-1, dest_ori/rep, 5)\n");
	ori = read(-1, dest_ori, 5);
	printf("'%s'| ori = %d | err = %s\n", dest_ori, ori, strerror(errno));
	errno = 0;
	rep = ft_read(-1, dest_rep, 5);
	printf("'%s'| rep = %d | err = %s\n", dest_rep, rep, strerror(errno));
	printf("\n");
	
	tab_reinit(dest_ori, 10);
	tab_reinit(dest_rep, 10);
	errno = 0;
	printf("(ft_)read(fd_ori/rep, dest_ori/rep, 2000000000000000)\n");
	ori = read(fd_ori, dest_ori, 2000000000000000);
	printf("'%s'| ori = %d | err = %s\n", dest_ori, ori, strerror(errno));
	errno = 0;
	rep = ft_read(fd_rep, dest_rep, 2000000000000000);
	printf("'%s'| rep = %d | err = %s\n", dest_rep, rep, strerror(errno));
	printf("\n");

	char	*dest_ori2 = 0;
	char	*dest_rep2 = 0;
	tab_reinit(dest_ori, 10);
	tab_reinit(dest_rep, 10);
	errno = 0;
	printf("(ft_)read(fd_ori/rep, dest_ori2/rep2, 20)\ndest_ori2/rep2 = null ptr\n");
	ori = read(fd_ori, dest_ori2, 20);
	printf("'%s' | ori = %d | err = %s\n", dest_ori2, ori, strerror(errno));
	errno = 0;
	rep = ft_read(fd_ori, dest_rep2, 20);
	printf("'%s' | ori = %d | err = %s\n", dest_rep2, rep, strerror(errno));
	close(fd_ori);
	close(fd_rep);
	printf("\n");
}

// ft_strdup
void	ft_strdup_test(void)
{
	printf("ft_strdup\n");
	printf("(ft_)strdup(\"Hello\")\n");
	errno = 0;
	printf("ori: '%s'| err = %s\n", strdup("Hello"), strerror(errno));
	errno = 0;
	printf("rep: '%s'| err = %s\n", ft_strdup("Hello"), strerror(errno));
	printf("\n");
	
	printf("(ft_)strdup(\"\")\n");
	errno = 0;
	printf("ori: '%s'| err = %s\n", strdup(""), strerror(errno));
	errno = 0;
	printf("rep: '%s'| err = %s\n", ft_strdup(""), strerror(errno));
	printf("\n");

	char	*str = "Hello";
	printf("&str = %p\n", str);
	printf("&ori = %p\n", strdup(str));
	printf("&rep = %p\n", ft_strdup(str));
}

void	ft_strdup_segfault(char *in)
{
	char	*s = 0;

	strcmp(in, "ori") == 0 ? strdup(s) : ft_strdup(s);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_strlen_test();
		ft_strcpy_test();
		ft_strcmp_test();
		ft_write_test();
		ft_read_test();
		ft_strdup_test();
	}
	else if (strcmp(av[1], "strlen") == 0)
	{
		ac == 2 ? ft_strlen_test() : 0;
		ac > 2 ? ft_strlen_segfault(av[2]) : 0;
	}
	else if (strcmp(av[1], "strcpy") == 0)
	{
		ac == 2 ? ft_strcpy_test() : 0;
		ac > 2 ? ft_strcpy_segfault(av[2], av[3]) : 0;
	}
	else if (strcmp(av[1], "strcmp") == 0)
	{
		ac == 2 ? ft_strcmp_test() : 0;
		ac > 2 ? ft_strcmp_segfault(av[2], av[3]) : 0;
	}
	else if (strcmp(av[1], "write") == 0)
		ft_write_test();
	else if (strcmp(av[1], "read") == 0)
		ft_read_test();
	else if (strcmp(av[1], "strdup") == 0)
	{
		ac == 2 ? ft_strdup_test() : 0;
		ac > 2 ? ft_strdup_segfault(av[2]) : 0;
	}
	return (0);
}
