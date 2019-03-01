/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundancy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:31:23 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/27 19:31:26 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hache.h"

int	rra(s_tack **a, m_et *m)
{
  m->len += 0;
  a[0] = a[0]->last;
  m->moves++;
  if (!m->sub)
	 printf("rra\n");
  return (1);
}

int	rrb(s_tack **b, m_et *m)
{
  m->len += 0;
  if (b[0])
    b[0] = b[0]->last;
  m->moves++;
  if(!m->sub)
    printf("rrb\n");
  return (1);
}

int	ra(s_tack **a, m_et *m)
{
  m->len += 0;
  if (a[0])
    a[0] = a[0]->next;
  m->moves++;
  if (!m->sub)
    printf("ra\n");
  return (1);
}

int	rb(s_tack **b, m_et *m)
{
  m->len += 0;
  if (b[0])
    b[0] = b[0]->next;
  m->moves++;
  if (!m->sub)
    printf("rb\n");
  return (1);
}

int	rab(s_tack **a, s_tack **b, m_et *m)
{
  m->len += 0;
  printf("rr\n");
  m->sub = 1;
  ra(a, m);
  rb(b, m);
  m->sub = 0;
  m->moves++;
  return (1);
}

int	rrab(s_tack **a, s_tack **b, m_et *m)
{
  m->len += 0;
  printf("rrr\n");
  m->sub = 1;
  rra(a, m);
  rrb(b, m);
  m->sub = 0;
  m->moves++;
  return (1);
}


int	sab(s_tack **a, s_tack **b, m_et *m)
{
  m->len += 0;
  printf("ss\n");
  m->sub = 1;
  sa(a, m);
  sb(b, m);
  m->sub = 0;
  m->moves++;
  return (1);
}



int	sa(s_tack **a, m_et *m)
{
  s_tack *one;
  s_tack *two;
  s_tack *three;
  s_tack *four;
  //s_tack **last_2;
  //1234 1324

  if (m->len_a == 2)
    {
      ra(a, m);
      return (1);
    }
  m->len += 0;
  one = a[0]->last;
  two = a[0];
  three = a[0]->next;
  four = a[0]->next->next;
  one->next = three;
  three->last = one;
  three->next = two;
  two->last = three;
  two->next = four;
  four->last = two;
  a[0] = three;
  m->moves++;
  if (!m->sub)
    printf("sa\n");
  //m->best[m->i++] = '1';
  return (1);
}

int	sb(s_tack **b, m_et *m)
{
  s_tack *one;
  s_tack *two;
  s_tack *three;
  s_tack *four;
  //s_tack **last_2;
  //1234 1324
  if (m->len_b == 2)
    {
      rb(b, m);
      return (1);
    }
  m->len += 0;
  one = b[0]->last;
  two = b[0];
  three = b[0]->next;
  four = b[0]->next->next;
  one->next = three;
  three->last = one;
  three->next = two;
  two->last = three;
  two->next = four;
  four->last = two;
  b[0] = three;
  m->moves++;
  if (!m->sub)
    printf("sb\n");
  //m->best[m->i++] = '2';
  return (1);
}


int	pb(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *last_a;
  s_tack *h_a;
  s_tack *next_a;
  s_tack *last_b;
  s_tack *h_b;
  
  

  last_a = a[0]->last;
  h_a = a[0];
  next_a = a[0]->next;
  last_b = (b[0]) ? (b[0]->last) : (NULL);
  h_b = b[0];
  

  last_a->next = next_a;
  next_a->last = last_a;
  a[0] = next_a;

  h_a->last = last_b;
  h_a->next = h_b;
  (last_b) ? (last_b->next  = h_a) : (0);
  (h_b) ? (h_b->last = h_a) : (0);
  if (!b[0])
    {
      h_a->next = h_a;
      h_a->last = h_a;

    }
  b[0] = h_a;
  
  m->len_a--;
  m->len_b++;
  m->moves++;
  printf("pb\n");
  //m->best[m->i++] = '5';
  return (1);
}

int	pa(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *last_b;
  s_tack *h_b;
  s_tack *next_b;
  s_tack *last_a;
  s_tack *h_a;




  last_b = b[0]->last;
  h_b = b[0];
  next_b = b[0]->next;
  last_a = (a[0]) ? (a[0]->last) : (NULL);
  h_a = a[0];


  last_b->next = next_b;
  next_b->last = last_b;
  b[0] = next_b;

  h_b->last = last_a;
  h_b->next = h_a;
  (last_a) ? (last_a->next  = h_b) : (0);
  (h_a) ? (h_a->last = h_b) : (0);
  a[0] = h_b;
  m->len_a++;
  m->len_b--;
  m->moves++;
  printf("pa\n");
  //m->best[m->i++] = '4';
  return (1);
}
