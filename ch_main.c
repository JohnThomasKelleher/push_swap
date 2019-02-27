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


static    int        bt_iswhitespace(char *str)
{
  int        i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
	 || str[i] == '\v' || str[i] == '\f')
    i++;
  if (str[i] == '+')
    {
      i++;
      if (str[i] == '-')
        {
	  while (str[i] != '\0')
	    i++;
        }
    }
  return (i);
}

int                bt_atoi(const char *str)
{
  int            len;
  int            flag;
  long long    res;

  flag = 1;
  res = 0;
  len = bt_iswhitespace((char*)str);
  if (str[len] == '-')
    {
      flag *= -1;
      len++;
    }
  while ((str[len] >= '0' && str[len] <= '9') && str[len] != '\0')
    {
      res *= 10;
      res += (str[len] - 48);
      len++;
    }
  if (str[len] != '\0')
    return (-1777777);
  return (res * flag);
}

s_tack	*next_A(long hold)
{
	s_tack *new;

	new = malloc(sizeof(s_tack));
	new->next = NULL;
	new->last = NULL;
	new->value = hold;
	return (new);
}

int	init_a(s_tack *A, int argc, char **argv, int *sort)
{
	long hold;
	int i;
	s_tack *head;

	i = 2;
	if((hold = bt_atoi(argv[1])) == -1777777) 
	  return (0);
	//A = next_A((int)hold);
	sort[1] = hold;
	head = A;
	A->value = hold;
	A->is_low = 0; A->is_high = 0;
	while (i < argc)
	{
	  if (-1777777 == (hold = bt_atoi(argv[i])))
	    return (0);
	  A->is_low = 0; A->is_high = 0;
	  A->next = next_A(hold);
	  A->next->last = A;
	  A = (A->next) ? (A->next) : (A);
	  sort[i] = hold;
	  i++;
	}
	A->next = head;
	sort[0] = argc;
	head->last = A;
	return (1);
}	

void	s_ort(int *sort)
{
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
		 if (i == sort[0])
		 {
			 if(at_least_one == 0)
				 not_sorted = 0;
			 i = 1;
			 at_least_one = 0;
		 }
	 }
}

void	r_ank(int *sort, s_tack *A)
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

s_tack	*rev_rot_a(s_tack **a, s_tack **b)
{
  b += 0;
  	a[0] = a[0]->last;
	return (NULL);
}

s_tack  *rev_rot_b(s_tack **a, s_tack **b)
{
  a += 0;
  b[0] = b[0]->last;
  return (NULL);
}

s_tack *rot_a(s_tack **a, s_tack **b)
{
  b += 0;
  	a[0] = a[0]->next;
	return (NULL);
}

s_tack *rot_b(s_tack **a, s_tack **b)
{
  a += 0;
  b[0] = b[0]->next;
  return (NULL);
}

s_tack	*r_ab(s_tack **a, s_tack **b)
{
  rot_a(a, b);
  rot_b(a, b);
  return (NULL);
}

s_tack	*rr_ab(s_tack **a, s_tack **b)
{
  *a = rev_rot_a(a, b);
  *b = rev_rot_b(a, b);
  return (NULL);
}


s_tack	*swap_ab(s_tack **a, s_tack **b)
{

  *a = swap_a(a, b);
  *b = swap_b(a, b);
  return (NULL);
}



s_tack *swap_a(s_tack **a, s_tack **b)
{
  //s_tack *a_hold;
	s_tack *next_2;
	s_tack *item_2;
	//s_tack *last_2;
	
  	
	if (!a[0])
	  return (0);
	item_2 = a[0]->next;
	next_2 = a[0]->next->next;
	a[0]->last->next = item_2;
	a[0]->next->next->last = a[0];
	a[0]->next->next = a[0];
	a[0]->next->last = a[0]->last;
	a[0]->next = next_2;
	a[0]->last = item_2;
	a[0] = item_2;
  	b += 0;
	
	return (NULL);
}

s_tack *swap_b(s_tack **a, s_tack **b)
{
  //s_tack *a_hold;
  s_tack *next_2;
  s_tack *item_2;
  //s_tack *last_2;


  if (!b[0])
    return (0);
  item_2 = b[0]->next;
  next_2 = b[0]->next->next;
  b[0]->last->next = item_2;
  b[0]->next->next->last = a[0];
  b[0]->next->next = a[0];
  b[0]->next->last = a[0]->last;
  b[0]->next = next_2;
  b[0]->last = item_2;
  b[0] = item_2;
  a += 0;

  return (NULL);
}

s_tack  *push_a(s_tack **a, s_tack **b)
{
  s_tack *b_hold;
  s_tack *src;
  s_tack *dst;


  src = b[0];
  dst = a[0];
  b[0] = b[0]->next;
  a[0] = src;
  b_hold = src;
  if (!src || !src->last || !src->next)
    return (0);
  src->last->next = src->next;
  src->next->last = src->last;
  src->next = (dst) ? (dst) : (src);
  src->last = (dst && dst->last) ? (dst->last) : (src);
  (dst && dst->last) ? (dst->last->next = src) : (0);
  (dst) ? (dst->last = src) : (0);

  return (NULL);
}

s_tack  *push_b(s_tack **a, s_tack **b)
{
  s_tack *a_hold;
  s_tack *src;
  s_tack *dst;


  src = a[0];
  dst = b[0];
  a[0] = a[0]->next;
  b[0] = src;
  a_hold = src;
  if (!src || !src->last || !src->next)
    return (0);
  src->last->next = src->next;
  src->next->last = src->last;
  src->next = (dst) ? (dst) : (src);
  src->last = (dst && dst->last) ? (dst->last) : (src);
  (dst && dst->last) ? (dst->last->next = src) : (0);
  (dst) ? (dst->last = src) : (0);
  
  return (NULL);
}

void                    fn(s_tack* (*fun[12]) (s_tack **from, s_tack **x))
{
  fun[0] = swap_a;
  fun[1] = swap_b;
  fun[2] = swap_ab;
  fun[3] = push_a;
  fun[4] = push_b;
  fun[5] = rot_a;
  fun[6] = rot_b;
  fun[7] = r_ab;
  fun[8] = rev_rot_a;
  fun[9] = rev_rot_b;
  fun[10] = rr_ab;
  fun[11] = NULL;
}

int		  get_fun(char **cmd, s_tack* (**c) (s_tack **from, s_tack **x))
{
  const char      *op[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
			   "rrb", "rrr", NULL};
  s_tack*           (*fun[12]) (s_tack **from, s_tack **x);
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

  s_tack* (*c[1]) (s_tack **from, s_tack **x);
  while (1 == (ret = get_next_line(0, cmd)))
    {
      if(!get_fun(cmd, c))
	return(0);//error
      c[0](&a, &b);
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

void		ft_error()
{

}

/*int		main(int argc, char **argv)
{
	s_tack A;
	s_tack B;
	int sort[argc];
	int ret;

	B.next = NULL; B.last = NULL;
	A.next = NULL; A.last = NULL;
	//ft_memset(&A, 0, sizeof A);
	//ft_memset(&B, 0, sizeof B);
	argv[argc] = NULL;
	if (argc == 1)
		return (0);
	if (!init_a(&A, argc, argv, sort))
	  {
	    printf("%s", "Error\n");
		return (0);
	  }
	s_ort(sort);
	if ((ret = o_perate(&A, &B, sort)))
		printf("OK\n");
	else if (ret == 0)
		printf("KO\n");
	else
		ft_error();
	return (0);
}
*/
