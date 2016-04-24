/*
** list2.c for colle2-1 file list part 2 in /u/epitech_2012/vray_s/cu/rendu/Semaine_02
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 20:45:45 2008 sebastien vray
** Last update Sun May  4 04:31:50 2008 sebastien vray
*/

#include "colle2-1.h"

void	add_node(char *name, char type, int size, t_lst **list)
{
  t_lst *new;

  new = (t_lst *)xmalloc(5 * sizeof(new));
  new->name = (char *)xmalloc((my_strlen(name) + 1) * sizeof(new->name));
  my_strcat(new->name, name);
  new->type = type;
  new->size = size;
  new->sub = NULL;
  new->next = *list;
  *list = new;
}

void	rev_list(t_lst **begin)
{
  t_lst	*list_to_move;
  t_lst	*next_item;

  list_to_move = (*begin)->next;
  (*begin)->next = 0;
  next_item = (list_to_move != 0) ? list_to_move->next : 0;
  while (list_to_move != 0)
    {
      next_item = list_to_move->next;
      list_to_move->next = *begin;
      *begin = list_to_move;
      list_to_move = next_item;
    }
}

int	is_upper(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (0);
      i++;
    }
  return (2);
}

t_lst	*abc(t_lst *list)
{
  t_lst	*first;
  t_lst	*new;
  t_lst	*to_del;
  char	*name;

  first = list;
  to_del = NULL;
  new = NULL;
  while (first)
    {
      name = list->name;
      while (list)
        {
          if (is_upper(list->name, name) != 0)
            {
              name = list->name;
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

int	list_len(t_lst *list)
{
  int	i;

  i = 0;
  while (list)
    {
      list = list->next;
      i++;
    }
  return (i);
}
