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
{
  v_is(a[0], b);
  while (m->len_b >  0) 
     { 
       pa(a, &b, m); 
       //m->len_b--; 
     } 
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

void	v_is(s_tack *a, s_tack *b)
{
  s_tack *hold;
  int i;

  i = 0;
  hold = a;
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
s_tack *rec(s_tack *a, s_tack *b, m_et *m)
{
  //int ret;
  int once = 1;
  
  if(s_tage2(&a, b, m))
    return (a);
  while (once)
    {
      once = 0;
      //v_is(a, b);
      if (a && b && SWAPAB(a, b, m))
	{
	  sab(&a, &b, m);
	  m->calls++;
	  once++;
	  if (s_tage2(&a, b, m))
	    return (a);
	}
      if (a && SWAPA2(a, m))
    {
      sa(&a, NULL,  m);
      m->calls += 1;
      once++;          
      if (s_tage2(&a, b, m))
	return (a);
    }
  if (b && SWAPB2(b, m))
    {
      sb(NULL, &b, m);
      m->calls+=1;
      once++;
      if (s_tage2(&a, b, m))
	return (a);
    }
if (a && b && x_s2(b, m, 0) && PUSHB(a, b))
    {
      pb(&a, &b, m);
      m->len_b++;
      m->calls +=1;
      once++;
      if (s_tage2(&a, b, m))
	return (a);
	}
    }
  if (s_tage2(&a, b, m))
    return (a);
  else if (x_s2(b, m, 0))
    rra(&a, NULL, m);
  else if (x_s2(a, m, 1))
    rrb(NULL, &b, m);
  else
    rrab(&a, &b, m);
  m->calls++;
  return (rec(a, b, m));
  

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
      ((a[0] && b[0] && SWAPAB(a[0], b[0], m) && sab(a, b, m)) || (a[0] && SWAPA2(a[0], m) && sa(a, NULL, m)));
      (b[0] && SWAPB2(b[0], m)) && sb(NULL, b, m);
      if (s_tage2(a, b[0], m))
	return ;
      if (a[0]->rank <= m->pivot) 
	pb(a, b, m);
      else
	ra(a, NULL,  m);
      if (s_tage2(a, b[0], m))
	return ;
      ((a[0] && b[0] && SWAPAB(a[0], b[0], m) && sab(a, b, m)) || (a[0] && SWAPA2(a[0], m) && sa(a, NULL, m)));
      (b[0] && SWAPB2(b[0], m)) && sb(NULL, b, m);
      if (s_tage2(a, b[0], m))
	return ;
    }
  m->hold = 0;
}

void	a_nswer(s_tack *a, m_et *m)
{
  //write(1, "in a_nswer\n", 12);
  s_tack **b;
  
  b = malloc(sizeof(s_tack*));
  b[0] = NULL;
  s_plit(&a, b, m);
  //write(1, "after split\n", 12);
  if (!m->fin)
    a = rec(a, b[0], m);
  
  
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
  //m->min = 0;
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
  v_is(a, NULL);
  s_ort(sort);
  r_ank(sort, a);
  printf("\n________________\n");
  v_is(a, NULL);
  m->pivot = (sort[0] - 1) / 2;
  m->len = sort[0] - 1;
  m->len_a = m->len;
  m->num_elem = m->len;
  //write(1, "before a_nswer", 20);
  a_nswer(a, m);
  printf("%d\n", m->moves);
  //p_rint(m);
  return (0);
}
