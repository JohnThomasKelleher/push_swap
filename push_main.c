/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:26:52 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/30 17:23:14 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hache.h"

void	f_inish(s_tack **a, s_tack *b, struct s_meta *m)
{//do_push(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
  //v_is(a[0], b);
  while (m->len_b >  0) 
     { 
       do_push(a, &b, m, 0, 1); 
       //m->len_b--; 
     }
  m->best[m->moves++] = '\0';
  m->fin = 1;
 } 

 int	s_tage2(s_tack **a, s_tack *b, struct s_meta *m) //check for the prerotated end condition 
 { 
   s_tack *hold; 
   int last; 
   int i; 
   s_tack *a_hold; 
   int low_a;
   int high_b;

   high_b = 0;
   a_hold = a[0]; 
   i = 0; 
   hold = a[0]; 
   last = a[0]->rank; 
   a[0] = a[0]->next; 
   low_a = last;
   while (a[0]->rank != hold->rank || !i) 
     { 
       if (a[0]->rank != (last + 1) && m->len_a != 1)
 	{ 
 	  a[0] = a_hold; 
 	return (0); 
 	}
       if (a[0]->rank < low_a)
	 low_a = a[0]->rank;
 	last = a[0]->rank; 
       a[0] = a[0]->next; 
       i++; 
     }
   a[0] = a_hold; 
   if (b && b != b->next) 
   { 
   	hold = b; 
   	last = b->rank; 
 	i = 0; 
 	b = b->next;
	high_b = last;
  	while (b != hold || !i) 
     { 
       if (b->rank != (last -1)) 
 			return (0);
       if (b->rank > high_b)
	 high_b = b->rank;
       last = b->rank; 
       b = b->next; 
       i++; 
     } 
   } 
   if (low_a < high_b)
     return (0);
   f_inish(a, b, m); 
   m->fin = 1;
   return (1); 
 } 


 int	x_s2(s_tack *x, m_et *m, int a) 
 { 
   int i; 
   int len; 

   i = 0; 
   len = (a) ? (m->len_a) : (m->len_b);
   len -= 1;
   x = x->next;
   while (i < len) 
     { 
       if (a && x->rank != (x->last->rank + 1)) 
 	return (0);
       else if (x->rank != (x->last->rank - 1)) 
 	return (0); 
       x = x->next;
       i++; 
     } 
   return (1); 
 } 

void	v_is(s_tack *a, s_tack *b, m_et *m)
{
  s_tack *hold;
  int i;

  i = 0;
  hold = a;
  printf("%c i:%d moves:%d\n", m->best[(m->moves -1)], (m->i - 1), m->moves);
  printf("%d\n", m->moves);
  printf("AAAAAAA\n");
  while (a && (a != hold || !i))
    {
      printf("rank: %d value: %d\n", a->rank, a->value);
      a = a->next;
      i++;
    }
  hold = b;
  i = 0;
  printf("BBB\n");
  while (b && (b != hold || !i))
    {
      printf("rank: %d value: %d\n", b->rank, b->value);
      b = b->next;
      i++;
    }
}





int	c_heck2(s_tack *a, s_tack *b, m_et *m)
{
	int i;

	i = 0;
	if (b)
	b += 0;
	if (!a)
		return (0);
  while (i < m->len)
  {
	  if (a->rank <= a->last->rank)
		  	return (0);
	  a = a->last;
	i++;
  }
  if (i == m->len)	
  	return (1);
  return (0);
}

void	s_plit(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *hold;

  hold = a[0];
  m->hold = 1;
  if (s_tage2(a, NULL, m))
    return ;
  while (m->len_b < m->pivot)
    {
      ((a[0] && b[0] && SWAPAB(a[0], b[0], m) && sab(a, b, m)) || (a[0] && SWAPA2(a[0], m) && do_swap(a, b, m, 0, 1)));
      (b[0] && SWAPB2(b[0], m)) && do_swap(a, b, m, 0, 0);;
      if (s_tage2(a, b[0], m))
	return ;
      if (a[0]->rank <= m->pivot) 
	do_push(a, b, m, 0, 0);
      else
	do_rotate(a, b, m, 0, 1);
      if (s_tage2(a, b[0], m))
	return ;
      ((a[0] && b[0] && SWAPAB(a[0], b[0], m) && do_ss(a, b, m, 0, 0)) || (a[0] && SWAPA2(a[0], m) && do_swap(a, b, m, 0, 1)));
      (b[0] && SWAPB2(b[0], m)) && do_swap(a, b, m, 0, 0);
      if (s_tage2(a, b[0], m))
	return ;
    }
  m->hold = 0;
}

void	p_rant(m_et *m)
{
  int i = 0;
  while (i < m->moves && m->best[i] != '\0')
    {
      (m->best[i] == 'a') ? (write(1, "sa\n", 3)) : (0);
      (m->best[i] == 'b') ? (write(1, "sb\n", 3)) : (0);
      (m->best[i] == 'c') ? (write(1, "ss\n", 3)) : (0);
      (m->best[i] == 'd') ? (write(1, "ra\n", 3)) : (0);
      (m->best[i] == 'e') ? (write(1, "rb\n", 3)) : (0);
      (m->best[i] == 'f') ? (write(1, "rr\n", 3)) : (0);
      (m->best[i] == 'g') ? (write(1, "rra\n", 4)) : (0);
      (m->best[i] == 'h') ? (write(1, "rrb\n", 4)) : (0);
      (m->best[i] == 'i') ? (write(1, "rrr\n", 4)) : (0);
      (m->best[i] == 'j') ? (write(1, "pa\n", 3)) : (0);
      (m->best[i] == 'k') ? (write(1, "pb\n", 3)) : (0);
	i++;
    }
}

void	a_nswer(s_tack *a, m_et *m)
{
  //write(1, "in a_nswer\n", 12);
  s_tack **b;
  
  b = malloc(sizeof(s_tack*));
  b[0] = NULL;
  s_plit(&a, b, m);
  //write(1, "after split\n", 12);
  if (!m->fin && rec(&a, b[0], m))
      {
	p_rant(m);
      }
  else if (m->fin)
    p_rant(m);
  else
    printf("oh shit\n");
  
}


void	init_m(m_et *m, int argc)
{
  m->moves = 0;
  //m->best = malloc(sizeof(char) * 420);
  m->len = (argc - 1);
  m->pivot = argc /2;
  m->num_elem = (argc - 1);
  m->len_a = (argc - 1);
  m->len_b = 0;
  m->ret = 0;
  m->calls = 0;
  m->i = 0;
  m->sub = 0;
  m->fin = 0;
  m->hold = 0;
  m->req = 0;
  //m->min = 0;
}

void set_req(m_et *m)
{
  /*
   3->3?
5 ->12
100->700
500->5500

   */
  if (m->len <= 3)
    m->req = 3;
  else if(m->len <=5)
    m->req = 12;
  else if(m->len <= 100)
    m->req = 700;
  else if(m->len <= 500)
    m->req = 5500;
  
}


int main(int argc, char **argv)
{
  s_tack *a;
  int *sort;//ft_strlen(argv[1]) * 11 + argc];
  m_et *m;
  //char ans[100];

  sort = malloc(sizeof(int) * (ft_strlen(argv[1]) + argc));
  a = malloc(sizeof(s_tack) * 2);
  m = malloc(sizeof(m_et) * 2);
  init_m(m, argc);
  if (argc == 1)
    {
      return (0);
    }
  
  if (!init_a(a, argc, argv, sort))
    {
      printf("Error\n");
      return (0);
     }
  //v_is(a, NULL);
  s_ort(sort);
  r_ank(sort, a);
  //printf("\n________________\n");
  //v_is(a, NULL);
  m->pivot = (sort[0] - 1) / 2;
  m->len = sort[0] - 1;
  m->len_a = m->len;
  m->num_elem = m->len;
  set_req(m);
  m->best = (char*)malloc(sizeof(char) * m->req + 1);

  //write(1, "before a_nswer", 20);
  a_nswer(a, m);
  printf("%d\n", m->moves);
  //p_rint(m);
  return (0);
}
