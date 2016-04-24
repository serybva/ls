/*
** ls.c for ls in /u/epitech_2012/vray_s/cu/rendu/Semaine_02
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Fri May  2 19:49:34 2008 sebastien vray
** Last update Sun May  4 04:38:41 2008 sebastien vray
*/

#include "colle2-1.h"

t_lst	*my_ls(char *path)
{
  t_dir	*dir;
  t_lst *list;
  DIR	*dirc;

  list = NULL;
  if (path[0] != '.' && path[1] != '\0')
    chdir(path);
  dirc = opendir(".");
  while ((dir = readdir(dirc)) != NULL)
    {
      get_files(dir->d_name, &list);
    }
  closedir(dirc);
  return (list);
}

int	print_sub(t_lst *list, char *decal)
{
  printf("|%s\\.\n|%s\\..\n", decal, decal);
  while (list)
    {
      if (list->type == 'd')
        {
	  print_ind(decal);
          reverse_v();
          printf("%s\n", list->name);
          dis_reverse();
	  print_sub(list->sub, my_strdup(decal, "     "));
        }
      else if (list->type == 'x')
        {
	  print_ind(decal);
          underline();
          printf("%s\n", list->name);
          disable_underline();
        }
      else
        printf("|%s\\%s\n", decal, list->name);
      list = list->next;
    }
  xfree(decal);
  return (0);
}

void	print_tree(t_lst *list, int r)
{
  char	*decal;

  decal = NULL;
  my_putstr("|\n|\\.\n|\\..\n");
  while (list)
    {
      if (list->type == 'd')
	{
	  print_ind(NULL);
	  reverse_v();
	  printf("%s\n", list->name);
	  dis_reverse();
	  if (r == 1)
	    print_sub(list->sub, my_strdup(decal, "     "));
	}
      else if (list->type == 'x')
	{
	  print_ind(NULL);
	  underline();
	  printf("%s\n", list->name);
	  disable_underline();
	}
      else
	printf("|\\%s\n", list->name);
      list = list->next;
    }
}

int	opt(int argc, char **argv)
{
  int	opt;

  opt = 0;
  argc -= 1;
  while (argc > 0)
    {
      if (my_strcmp("-R", argv[argc]) == 0 && my_strlen(argv[argc]) == 2)
        opt |= R_O;
      else if (my_strcmp("-S", argv[argc]) == 0 && my_strlen(argv[argc]) == 2)
        opt |= S_MAX;
      else if (my_strcmp("-s", argv[argc]) == 0 && my_strlen(argv[argc]) == 2)
	opt |= S_O;
      else if (my_strcmp("-S2", argv[argc]) == 0 && my_strlen(argv[argc]) == 3)
	opt |= S_ABC;
      else if (my_strcmp("-R", argv[argc]) != 0 &&\
	       my_strcmp("-S", argv[argc]) != 0 &&\
	       my_strcmp("-s", argv[argc]) != 0 &&\
	       my_strcmp("-S2", argv[argc]) != 0)
	{
	  printf("Unknow %s enter normal mode\n", argv[argc]);
	  opt = 0;
	}
      argc--;
    }
  return (opt);
}

int	main(int argc, char **argv)
{
  t_lst	*list;
  int	options;

  options = opt(argc, argv);
  list = my_ls(".");
  rev_list(&list);
  if ((options & S_MAX) == S_MAX)
    list = sort_list_max(list);
  if ((options & S_O) == S_O)
    list = sort_list(list);
  if ((options & S_ABC) == S_ABC)
    list = abc(list);
  if ((options & R_O) == R_O)
    {
      complete_tree(list);
      print_tree(list, 1);
    }
  else
    print_tree(list, 0);
  xfree_list(list);
  return (0);
}
