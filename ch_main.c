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
//store input in A, then read from 0





void                    fn(int (*fun[12]) (s_tack **a, s_tack **b, m_et *m))
{
  fun[0] = sa;
  fun[1] = sb;
  fun[2] = sab;
  fun[3] = pa;
  fun[4] = pb;
  fun[5] = ra;
  fun[6] = rb;
  fun[7] = rab;
  fun[8] = rra;
  fun[9] = rrb;
  fun[10] = rrab;
  fun[11] = NULL;
}

int		  get_fun(char **cmd, int (**c) (s_tack **a, s_tack **b, m_et *m))
{
  const char      *op[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
			   "rrb", "rrr", NULL};
  int           (*fun[12]) (s_tack **a, s_tack **b, m_et *m);
  int                     j;

  fn(fun);
  j = -1;
  while (++j < 11)
    {
      if (ft_strcmp(op[j], *cmd) == 0)
	{
	  *c = fun[j];
	  return (1);
	}
    }
  return (0);
}

int		o_perate(s_tack *a, s_tack *b, int *sort)
{
  char *cmd[2];
  int ret;

  int (*c[1]) (s_tack **a, s_tack **b, m_et *m);
  while (1 == (ret = get_next_line(0, cmd)))
    {
      if(!get_fun(cmd, c))
	return(0);//error
      c[0](&a, &b, NULL);
      if (c_heck (a, sort))
	return (1);
    }
  return (0);
}

int		c_heck(s_tack *a_head, int *sort)
{
  s_tack *hold;
  long	hd;
  int c_hold;

  c_hold = sort[0];
  hd = a_head->value;
  hold = a_head;
  a_head = a_head->next;
  
  while (a_head != hold)
    {
      sort[0]--;
      if (hd > a_head->value)
	{
	  sort[0] = c_hold;
	return (0);
	}
      hd = a_head->value;
      a_head = a_head->next;
    }
  if(sort[0] != 2)
    {
      sort[0] = c_hold;
    return (0);
    }
  return(1);
}


int		main(int argc, char **argv)
{
	s_tack A;
	s_tack B;
	int *sort;
	int ret;

	sort = (int*)malloc(sizeof(int) * argc);
	B.next = NULL; B.last = NULL;
	A.next = NULL; A.last = NULL;
	argv[argc] = NULL;
	sort[0] = argc;
	if (argc == 1)
		return (0);
	if (!init_a(&A, argc, argv, sort))
	  {
	    printf("%s", "Error\n");
		return (0);
	  }
	s_ort(sort);
	if ((ret = o_perate(&A, NULL, sort)))
		printf("OK\n");
	else if (ret == 0)
		printf("KO\n");
	return (0);
}
