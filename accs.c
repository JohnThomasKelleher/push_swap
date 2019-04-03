/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:14:24 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/30 16:52:48 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hache.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

s_tack  *next_A(long hold)
{
  s_tack *new;

  new = malloc(sizeof(s_tack));
  new->next = NULL;
  new->last = NULL;
  new->value = hold;
  return (new);
}



int     c_ombine(int argc, char **argv, char **y)
{
  int i;
  int j;
  int k;

  i = 1;
  j = 0;
  k = 0;
  while (i < argc)
    {
      if (ERRA(argv[i][j]))
        return (0);
      else if (argv[i][j] != '\0')
        y[0][k++] = argv[i][j++];
      else if (argv[i][j] == '\0')
        {
          y[0][k++] = ' ';
          j = 0;
          i++;
        }
    }
  y[0][--k] = '\0';
  return (1);
}

int     bt_atoi(char **x)
{
  int ret;

  ret = 0;
  while (x[0][0] >= '0' && x[0][0] <= '9')
    {
      ret *= 10;
      ret += x[0][0] - 48;
      x[0]++;
    }
  while (!(x[0][0] >= '0' && x[0][0] <= '9') && x[0][0] != '\0')
    {
      x[0]++;
    }
  return (ret);
}

int     init_a(s_tack *A, int argc, char **argv, int *sort)
{
  //write(1, "init_a\n", 7);
  int hold;
  s_tack *first;
  int i;
  char **y;
  char *y_hold;

  i = 1;
  first = A;
  y = (char**)malloc(sizeof(char*) *1);
  int size = ft_strlen(argv[1]) + argc * 11;
  y[0] = (char*)malloc(size);
  if (!c_ombine(argc, argv, y))
    return (0);
  y_hold = y[0];
  A->value = bt_atoi(y);
  sort[i++] = A->value;
  while (y[0][0] != '\0')
    {
      hold = bt_atoi(y);
      sort[i++] = hold;
      A->next = next_A((long)hold);
      A->next->last = A;

      A = A->next;
    }
  sort[0] = i;
  A->next = first;
  first->last = A;
  //free(y_hold);
  return (1);
}

void    r_ank(int *sort, s_tack *A)
{
  int i;
  s_tack *head;
  int hold;

  head = A;
  i = 1;
  while (i < sort[0])
    {
      A = head;
      hold = 0;
      while (A != head || !hold)
	{
	  if (A->value == sort[i] && i == 1)
	    {
	      A->rank = i;
	      A->is_low = 1;
	    }
	  else if (A->value == sort[i] && i == (sort[0] -1))
	    {
	      A->rank = i;
	      A->is_high = 1;
	    }
	  else if (A->value == sort[i])
	    A->rank = i;
	  A = A->next;
	  hold++;
	}
      i++;
    }

}

void    s_ort(int *sort)
{
  //write(1, "s_ort\n", 6);
  int i;
  int not_sorted;
  int at_least_one;
  int hold;

  not_sorted = 1;

  i = 1;
  while (not_sorted)
    {
      if (sort[i] > sort[(i + 1)])
	{
	  at_least_one = 1;
	  hold = sort[i];
	  sort[i] = sort[(i + 1)];
	  sort[(i + 1)] = hold;
	}
      i++;
      if (i == (sort[0] - 1))
	{
	  if(at_least_one == 0)
	    not_sorted = 0;
	  i = 1;
	  at_least_one = 0;
	}
    }
}
