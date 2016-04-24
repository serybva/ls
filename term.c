/*
** term.c for functions for termcaps using in /u/epitech_2012/vray_s/cu/rendu/Semaine_02
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 23:01:45 2008 sebastien vray
** Last update Sun May  4 03:38:37 2008 sebastien vray
*/

#include "colle2-1.h"

int	outc(int c)
{
  my_putchar(c);
  return (0);
}

char	*xtgetstr(char *cap, char **area)
{
  char	*res;

  res = tgetstr(cap, area);
  if (!res)
    {
      print_err("Tgetstr cannot get ");
      print_err(cap);
      print_err("\n");
      return (NULL);
    }
  else
    return (res);
}

int	underline(void)
{
  char	bp[1024];
  char	*term;
  char	**area;
  char	*cap;

  area = NULL;
  if ((term = getenv("TERM")) == NULL)
    {
      print_err("Cannot determine term\n");
      return (-1);
    }
  if (tgetent(bp, term) != 1)
    return (-1);
  cap = xtgetstr("us", area);
  if (!cap)
    return (-1);
  tputs(cap, 1, outc);
  return (0);
}

int	disable_underline(void)
{
  char	bp[1024];
  char	*term;
  char	**area;
  char	*cap;

  area = NULL;
  if ((term = getenv("TERM")) == NULL)
    {
      print_err("Cannot determine term\n");
      return (-1);
    }
  if (tgetent(bp, term) != 1)
    {
      xfree(term);
      return (-1);
    }
  cap = xtgetstr("ue", area);
  if (!cap)
    {
      xfree(term);
      return (-1);
    }
  tputs(cap, 1, outc);
  return (0);
}

int	reverse_v(void)
{
  char	bp[1024];
  char	*term;
  char	**area;
  char	*cap;

  area = NULL;
  if ((term = getenv("TERM")) == NULL)
    {
      print_err("Cannot determine term\n");
      return (-1);
    }
  if (tgetent(bp, term) != 1)
    return (-1);
  cap = xtgetstr("so", area);
  if (!cap)
    return (-1);
  tputs(cap, 1, outc);
  return (0);
}

int	dis_reverse(void)
{
  char	bp[1024];
  char	*term;
  char	**area;
  char	*cap;

  area = NULL;
  if ((term = getenv("TERM")) == NULL)
    {
      print_err("Cannot determine term\n");
      return (-1);
    }
  if (tgetent(bp, term) != 1)
    return (-1);
  cap = xtgetstr("se", area);
  if (!cap)
    return (-1);
  tputs(cap, 1, outc);
  return (0);
}
