/*
** list.c for colle2-1 file list in /u/epitech_2012/vray_s/cu/rendu/Semaine_02
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 20:45:07 2008 sebastien vray
** Last update Sat May  3 06:34:31 2008 sebastien vray
*/

#include "colle2-1.h"

t_lst	*get_node(int node, t_lst **list)
{
  int	i;
  t_lst	*cur;

  cur = *list;
  i = 0;
  while (cur && i++ < node)
    cur = cur->next;
  return (cur);
}

int	insert_data(char *name, int size, char type, int node, t_lst **list)
{
  int	i;
  t_lst	*cur;

  cur = *list;
  i = 0;
  while (cur && i++ < node)
    cur = cur->next;
  if (cur == NULL)
    return (-1);
  xfree(cur->name);
  cur->name = (char *)xcalloc((my_strlen(name) + 1) * sizeof(cur->name));
  my_strcat(cur->name, name);
  cur->size = size;
  cur->type = type;
  return (0);
}

int	del_node(int node, t_lst **list)
{
  int	i;
  t_lst *cur;
  t_lst	*next;
  t_lst	*prev;

  cur = *list;
  prev = *list;
  next = *list;
  i = 0;
  while (cur && i++ < node)
    cur = cur->next;
  if (cur == NULL)
    return (-1);
  i = 0;
  while (prev && i++ < (node - 1))
    prev = prev->next;
  i = 0;
  while (next && i++ < (node + 1))
    next = next->next;
  xfree(cur->name);
  xfree(cur);
  if (cur == *list)
    *list = next;
  if (prev)
    prev->next = next;
  return (0);
}

int	del_node2(t_lst *node, t_lst **list)
{
  t_lst	*cur;
  t_lst	*next;
  t_lst	*prev;

  cur = *list;
  prev = *list;
  next = *list;
  while (cur && cur != node)
    cur = cur->next;
  if (cur == NULL)
    return (-1);
  while (prev && prev->next != node)
    prev = prev->next;
  while (next && node->next != next)
    next = next->next;
  xfree(cur->name);
  xfree(cur);
  if (node == *list)
    *list = next;
  if (prev)
    prev->next = next;
  return (0);
}
