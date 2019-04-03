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

int	rra(s_tack **a, s_tack **b, m_et *m)
{
  m += 0;
  b += 0;
  a[0] && (a[0] = a[0]->last);
  return (1);
}

int	rrb(s_tack **a, s_tack **b, m_et *m)
{
  m += 0;
  a += 0;
  if (b[0])
    b[0] = b[0]->last;
  return (1);
}

int	ra(s_tack **a, s_tack **b, m_et *m)
{
  m += 0;
  b += 0;
  if (a[0])
    a[0] = a[0]->next;
  return (1);
}

int	rb(s_tack **a, s_tack **b, m_et *m)
{
  m += 0;
  a += 0;
  if (b[0])
    b[0] = b[0]->next;
  return (1);
}

int	rab(s_tack **a, s_tack **b, m_et *m)
{
  //m && printf("rr\n");
  if (m)
    m->sub = 1;
  ra(a, b,  m);
  rb(a, b, m);
  if (m)
    {
      m->sub = 0;
    }
  return (1);
}

int	rrab(s_tack **a, s_tack **b, m_et *m)
{
  //m && printf("rrr\n");
  if (m)
    m->sub = 1;
  rra(a, b,  m);
  rrb(a, b, m);
  if (m)
    {
      m->sub = 0;
    }
  return (1);
}


int	sab(s_tack **a, s_tack **b, m_et *m)
{
  //m && printf("ss\n");
  if (m)
    m->sub = 1;
  sa(a, b, m);
  sb(a, b, m);
  if (m)
    {
      m->sub = 0;
    }
  return (1);
}



int	sa(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *one;
  s_tack *two;
  s_tack *three;
  s_tack *four;
  //s_tack **last_2;
  //1234 1324

  if (!a || !a[0])
    return (1);
  b += 0;
  if (a[0]->next == a[0]->last)
    {
      ra(a, b, m);
      return (1);
    }
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
  return (1);
}

int	sb(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *one;
  s_tack *two;
  s_tack *three;
  s_tack *four;
  //s_tack **last_2;
  //1234 1324
  
  if (!b || !b[0])
    return (1);
  a += 0;
  if (b[0]->next == b[0]->last)
    {
      rb(a, b, m);
      return (1);
    }
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
  return (1);
}


int	pb(s_tack **a, s_tack **b, m_et *m)
{
  s_tack *last_a;
  s_tack *h_a;
  s_tack *next_a;
  s_tack *last_b;
  s_tack *h_b;
  
  //a += 0;
  if (!a || !a[0])
    return (1);

  m && (m->pivot += (m && m->hold) ? (0) : (1));
  last_a = a[0]->last;
  h_a = a[0];
  next_a = a[0]->next;
  last_b = (b[0]) ? (b[0]->last) : (NULL);
  h_b = b[0];
  
  last_a->next = next_a;
  next_a->last = last_a;
  a[0] = next_a;
  if (last_a == a[0])
    {
      a[0] = NULL;
    }


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
  
  if (m)
    {
      m->len_a--;
      m->len_b++;
    }
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

  //b += 0;
  if (!b || !b[0])
    return (1);
  m && (m->pivot -= (m->hold) ? (1) : (0));
  
  
  last_b = b[0]->last;
  h_b = b[0];
  next_b = b[0]->next;
  last_a = (a[0]) ? (a[0]->last) : (NULL);
  h_a = a[0];


  last_b->next = next_b;
  next_b->last = last_b;
  b[0] = next_b;
  if (last_b == h_b)
    {
      b[0] = NULL;
    }

  h_b->last = last_a;
  h_b->next = h_a;
  (last_a) ? (last_a->next  = h_b) : (0);
  (h_a) ? (h_a->last = h_b) : (0);
  a[0] = h_b;
  if (m)
    {
      m->len_a++;
      m->len_b--;
    }
  //m->best[m->i++] = '4';
  return (1);
}
