/*
** colle2-1.h for include file for colle2-1 in /u/epitech_2012/vray_s/cu/rendu/Semaine_02
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 19:46:37 2008 sebastien vray
** Last update Sun May  4 04:37:32 2008 sebastien vray
*/

#ifndef _COLLE2_1_H_
#define _COLLE2_1_H_
#include "libmy.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define R_O 1073741824
#define S_O 536870912
#define S_MAX 268435456
#define S_ABC 134217728

typedef struct dirent t_dir;
typedef struct stat t_stat;
typedef	struct	s_list
{
  char          *name;
  char          type;
  int           size;
  struct s_list *sub;
  struct s_list	*next;
}t_lst;

/*list functions*/
void	add_node(char *name, char type, int size, t_lst **list);
void	rev_list(t_lst **begin);
t_lst	*get_node(int node, t_lst **list);
int	insert_node(int node, t_lst **list);
int	insert_data(char *name, int size, char type, int node, t_lst **list);
int	del_node(int node, t_lst **list);
int	del_node2(t_lst *node, t_lst **list);
t_lst	*sort_list(t_lst *list);
int	list_len(t_lst *list);
t_lst	*sort_list_max(t_lst *list);
int	is_upper(char *s1, char *s2);
t_lst	*abc(t_lst *list);
void	xfree_list(t_lst *list);

/*Term functions*/
char	*xtgetstr(char *cap, char **area);
int	underline(void);
int	disable_underline(void);
int	outc(int c);
int	reverse_v(void);
int	dis_reverse(void);

/*Printing functions*/
void	print_tree(t_lst *list, int r);
int	print_sub(t_lst *list, char *decal);
void	print_ind(char *decal);

/*ls functions*/
int	xstat(char *path, t_stat *sct);
char	get_type(int mod);
int	get_files(char *path, t_lst **list);

/*tree functions*/
int	complete_tree(t_lst *list);
t_lst	*my_ls(char *path);
#endif
