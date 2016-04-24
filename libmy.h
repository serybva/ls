/*
** libmy.h for header file for libmy functions in /u/epitech_2012/vray_s/cu/rendu/lib/my
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri Feb 15 18:32:52 2008 sebastien vray
** Last update Sun May  4 04:34:52 2008 sebastien vray
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_
void	*xrecalloc(void *ptr, int n);
void	*xrealloc(void *ptr, int n);
void	print_err(char *str);
void	*xcalloc(int n);
char	*my_strdup(char *str1, char *str2);
void	xfree(void *ptr);
int	size_of_ptr_tab(char *str, int start, char separator);
void	*xmalloc(int n);
int	my_strlen(const char *str);
int	randomize(int seed, int min, int max);
int	my_nbrlen(int nb);
int	my_getnbr(char *str);
int	my_is_prime(int nombre);
int	my_is_prime_sup(int nb);
int	my_isneg(int n);
int	my_power_rec(int nb, int power);
int	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putnbr_base(int n, char *base);
int	my_putstr(char *str);
void	my_putstr_len(int start, char *str, int end);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *str1, char *str2);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strncat(char *str1, char *str2, int n);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
void	my_swap(int *a, int *b);
#endif
