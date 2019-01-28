/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:26:52 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/27 15:26:54 by jkellehe         ###   ########.fr       */
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

int	s_tage2(s_tack a, s_tack b, met m) //check for the prerotated end condition
{

}

int	rec(s_tack a, s_tack b, met m)
{
  int check;
  
  check = (m->calls >= m->min) ? (1) : (0);
    if(c_heck2(a, b, m) && check)
      return (1);
  if (SWAPAB2(a, b) && sab(*a, *b) && (m->calls += 1) && check)
    {
      if(c_heck2(a, b, m))
	return (1);
    }
  else if (SWAPA2(a) && sa(*a) && (m->calls += 1) && check)
    (c_heck2(a, b, m)) ? (return (1)) : (return (0));
  else if (SWAPB2(b) && sb(*b) && (m->calls += 1) && check)
    (c_heck2(a, b, m)) ? (return (1)) : (return (0));
  if (PUSHA(a, b) && pa(*a, *b) && (m->calls += 1) && check)
    (c_heck2(a, b, m)) ? (return (1)) : (return (0));
  else if (PUSHB(a, b) && pb(*a, *b) && (m->calls += 1) && check0)
    (c_heck2(a, b, m)) ? (return (1)) : (return (0));
  if (s_tage2(a, b, m) && c_heck2(a, b, m))
    return (1);
  rrab(a, b);
  return (rec(a, b, m));
  

}

int	c_heck2(s_tack a, s_tack b, met m)
{
  s_tack  hold;
  int	r_hold;

  r_hold = a->rank - 1;
  hold = a;
  while (a != hold)
    {
      if (a->rank != (r_hold + 1))
	return (0);
      r_hold++;
      a = a->next;
      
    }
  b = hold;
  r_hold = b->rank -1;
  while (b != hold)
    {
      if (b->rank != (r_hold + 1))
	return (0);
      r_hold++;
      b = b->next;
    }
  return (1);
  
}

void	s_plit(s_tack a, s_tack b, met m)
{
  s_tack hold;
  
  hold = a;
  while (a != hold)
    {
      if (a->rank <= pivot && (SWAPB2(b) && sb(&b))) 
	pb(&a, &b);
      else if ((SWAPAB2(a, b) && sab(&a, &b)) || (SWAPA2(a) && sa(&a)) || 1)
	rab(&a, &b);
       
      a = a.next;
      
    }
}

void	a_nswer(s_tack a, met m)
{
  s_tack b;
  
  b.next = NULL, b.last = NULL;
  s_plit(a, b);
  
  rec(a);
  
  
}


int main(int argc, char **argv)
{
  s_tack A;
  //s_tack B;
  int sort[argc];
  int ret;
  met m;
  
  m.best = malloc(sizeof(char) * 5500);
  //B.next = NULL; B.last = NULL;
  A.next = NULL; A.last = NULL;
  m->len = argc;
  m->pivot = argc /2;
  argv[argc] = NULL;
  if (argc == 1)
    return (0);
  if (!init_a(&A, argc, argv, sort))
    {
      printf("Error\n");
      return (0);
    }
  s_ort(sort);
  r_ank(sort, A);

  a_nswer(A, m);
  p_rint(m);
  return (0);
}
