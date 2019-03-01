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
/*
  pivot 7


   15974862cdeba
   //do first, move to b in order of rank
   //do bubble, split by rank and then bubble sort with dual movments
   //other things, like merge sort


   i am just going to do recursive backtracking with help.
   any single move that make adjacent ranks touch will be performed before the recursive calls of the call 
   check for the swap to do this, or the push 




 */

void	f_inish(s_tack **a, s_tack *b, struct s_meta *m)
{
  
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

   a_hold = a[0]; 
   i = 0; 
   hold = a[0]; 
   last = a[0]->rank; 
   a[0] = a[0]->next; 
   while (a[0]->rank != hold->rank || !i) 
     { 
       if (a[0]->rank != ( last + 1) || a[0]->rank == 1) 
 	{ 
 	  a[0] = a_hold; 
 	return (0); 
 	} 
 	last = a[0]->rank; 
       a[0] = a[0]->next; 
       i++; 
     } 
   a[0] = a_hold; 
   if (b) 
   { 
   	hold = b; 
   	last = b->rank; 
 	i = 0; 
 	b = b->next; 
  	while (b != hold || !i) 
     { 
       if (b->rank != (last -1) || b->rank == m->len) 
 			return (0); 
       last = b->rank; 
       b = b->next; 
       i++; 
     } 
   } 
   f_inish(a, b, m); 
   return (1); 
 } 

 void	v_is(s_tack *a, s_tack *b, m_et *m) 
 { 
   int height; 
   int be; 
   int ay; 

   be = m->len_b; 
   ay = m->len_a; 
   height = (ay > be) ? (ay) : (be); 
   //printf("a        b\n"); 
   printf("yeah\n\n\n"); 
   while (height) 
     { 
       if (ay == height) 
 	{ 
 	  printf("%10da", a->value); 
 	  a = a->next; 
 	} 
       else 
 	printf("         a"); 
       if (be == height) 
 	{ 
 	  printf("%10db", b->value); 
 	  b = b->next; 
 	} 
       else 
 	printf("         b"); 
       be -= (be == height) ? (1) : (0); 
       ay -= (ay == height) ? (1) : (0); 
       height--; 
       printf("\n"); 
     } 
 } 

 int	x_s2(s_tack *x, m_et *m, int a) 
 { 
   int i; 
   int len; 

   i = 0; 
   len = (a) ? (m->len_a) : (m->len_b); 
   while (i < len) 
     { 
       if (a && x->rank > x->next->rank) 
 	return (0); 
       else if (x->rank < x->next->rank) 
 	return (0); 
       i++; 
     } 
   return (1); 
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
      if (a && b && SWAPAB(a, b))
	{
	  sab(&a, &b, m);
	  v_is(a, b, m);
	  m->calls++;
	  once++;
	  if (s_tage2(&a, b, m))
	    return (a);
	}
  if (a && SWAPA2(a))
    {
      sa(&a, m);
      v_is(a, b, m);
      m->calls += 1;
      once++;          
      if (s_tage2(&a, b, m))
	return (a);
    }
  if (b && SWAPB3(b, m->len_b))
    {
      sb(&b, m);
      v_is(a, b, m);
      m->calls+=1;
      once++;
      if (s_tage2(&a, b, m))
	return (a);
    }
  if (a && b && PUSHA(a, b))
    {
      pa(&a, &b, m);
      v_is(a, b, m);
      m->len_a++;
      m->calls+=1;
      once++;
      if (s_tage2(&a, b, m))
	return (a);
    }
  if (a && b && PUSHB(a, b))
    {
      pb(&a, &b, m);
      v_is(a, b, m);
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
    rra(&a, m);
  else if (x_s2(a, m, 1))
    rrb(&b, m);
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
  while (m->len_b < m->pivot)
    {
      ((a[0] && b[0] && SWAPAB(a[0], b[0]) && sab(a, b, m)) || (a[0] && SWAPA2(a[0]) && sa(a, m)));
      (b[0] && SWAPB2(b[0])) && sb(b, m);
      if (a[0]->rank <= m->pivot) 
	pb(a, b, m);
      else
	rab(a, b, m);
      ((a[0] && b[0] && SWAPAB(a[0], b[0]) && sab(a, b, m)) || (a[0] && SWAPA2(a[0]) && sa(a, m)));
      (b[0] && SWAPB2(b[0])) && sb(b, m);
    }
}

void	a_nswer(s_tack *a, m_et *m)
{
  s_tack **b;
  
  b = malloc(sizeof(s_tack*));

  s_plit(&a, b, m);
  
  a = rec(a, b[0], m);
  
  
}

/*void	p_rint( m_et *m)
{
  m->len += 0;
  int i = 0;
  char *x = m->best;

  while (i < m->i)
    {
      if (x[i] == '1')
	printf("sa\n");
      else if (x[i] == '2')
	printf("sb\n");
      else if (x[i] == '3')
	{
	printf("ss\n");
	i += 2;
	}
      else if (x[i] == '4')
	printf("pa\n");
      else if (x[i] == '5')
	printf("pb\n");
      else if (x[i] == '6')
	printf("ra\n");
      else if (x[i] == '7')
	printf("rb\n");
      else if (x[i] == '8')
	{
	printf("rr\n");
	i += 2;
	}
      else if (x[i] == '9')
	printf("rra\n");
      else if (x[i] == 'a')
	printf("rrb\n");
      else if (x[i] == 'b')
	{
	printf("rrr\n");
	i += 2;
	}
      i++;
    }
  //
}*/

void	init_m(m_et *m, int argc)
{
  m->moves = 0;
  m->best = malloc(sizeof(char) * 420);
  m->len = (argc - 1);
  m->pivot = argc /2;
  m->num_elem = (argc - 1);
  m->len_a = (argc - 1);
  m->len_b = 0;
  m->ret = 0;
  m->calls = 0;
  m->i = 0;
  m->sub = 0;
  //m->min = 0;
}

int main(int argc, char **argv)
{
  s_tack *a;
  int sort[argc];
  m_et *m;
  char ans[10000];

  a = malloc(sizeof(s_tack));
  m = malloc(sizeof(m_et));
  init_m(m, argc);
  m->best = ans;
  argv[argc] = NULL;
  if (argc == 1)
    return (0);
  if (!init_a(a, argc, argv, sort))
    {
      printf("Error\n");
      return (0);
    }
  s_ort(sort);
  r_ank(sort, a);

  a_nswer(a, m);
  //p_rint(m);
  return (0);
}
