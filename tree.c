/*
** tree.c for  in /u/epitech_2012/dupont_m/cu/rendu/colles/Semaine_01
** 
** Made by mick dupont
** Login   <dupont_m@epitech.net>
** 
** Started on  Fri May  2 21:48:39 2008 mick dupont
** Last update Sun May  4 04:29:16 2008 sebastien vray
*/

#include "colle2-1.h"

void	print_ind(char *decal)
{
  my_putchar('|');
  if (decal)
    my_putstr(decal);
  my_putchar('\\');
}

int	complete_tree(t_lst *list)
{
  while (list)
    {
      if (list->type == 'd' && !list->sub)
	{
	  list->sub = my_ls(list->name);
	  complete_tree(list->sub);
	}
      list = list->next;
    }
  return (0);
}

void	xfree_list(t_lst *list)
{
  t_lst	*old;

  old = NULL;
  while (list)
    {
      old = list;
      if (list->type == 'd')
	xfree_list(list->sub);
      list = list->next;
      xfree(old->name);
      xfree(old);
    }
}
