/*
** ls_fct.c for functions for ls in /u/epitech_2012/vray_s/cu/public/colle
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 22:51:27 2008 sebastien vray
** Last update Mon May  5 00:15:44 2008 sebastien vray
*/

#include "colle2-1.h"

int	check_types[] =
  {
    S_IFIFO, S_IFCHR, S_IFDIR, S_IFBLK, S_IFREG, S_IFLNK, S_IFSOCK, 0
  };

char	types[] =
  {
    'p', 'c', 'd', 'b', '-', 'l', 's', 0
  };

char	get_type(int mod)
{
  int	i;

  i = 0;
  while (check_types[i] != 0)
    {
      if ((mod & S_IFMT) == check_types[i])
        {
          return (types[i]);
        }
      i++;
    }
  return (0);
}

int		get_files(char *path, t_lst **list)
{
  t_stat	sct;
  char		type;
  int		size;

  if (xstat(path, &sct) == -1)
    return (-1);
  if (path[0] == '.')
    return (0);
  if ((sct.st_mode & S_IEXEC) == S_IEXEC && \
      (sct.st_mode & S_IXGRP) == S_IXGRP && (sct.st_mode & S_IXOTH) == S_IXOTH && \
      (sct.st_mode & S_IFDIR) != S_IFDIR && (sct.st_mode & S_IFLNK) != S_IFLNK)
    type = 'x';
  else
    type = get_type(sct.st_mode);
  size = sct.st_size;
  add_node(path, type, size, list);
  return (0);
}

int	xstat(char *path, t_stat *sct)
{
  if (stat(path, sct) == -1)
    {
      print_err("Can't get ");
      print_err(path);
      print_err(" properties\n");
      my_putstr(strerror(errno));
      return (-1);
    }
  return (0);
}

t_lst	*sort_list_max(t_lst *list)
{
  t_lst	*first;
  t_lst	*new;
  t_lst	*to_del;
  int	min;

  first = list;
  to_del = NULL;
  new = NULL;
  while (first)
    {
      min = list->size;
      while (list)
        {
          if (list->size <= min)
            {
              min = list->size;
              to_del = list;
            }
          list = list->next;
        }
      add_node(to_del->name, to_del->type, to_del->size, &new);
      del_node2(to_del, &first);
      list = first;
    }
  return (new);
}

t_lst	*sort_list(t_lst *list)
{
  t_lst	*first;
  t_lst	*new;
  t_lst	*to_del;
  int	max;

  first = list;
  to_del = NULL;
  new = NULL;
  while (first)
    {
      max = list->size;
      while (list)
	{
	  if (list->size > max || list->size == max)
	    {
	      max = list->size;
	      to_del = list;
	    }
	  list = list->next;
	}
      add_node(to_del->name, to_del->type, to_del->size, &new);
      del_node2(to_del, &first);
      list = first;
    }
  return (new);
}
