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

int	rra(s_tack *a)
{
  a = a->last;
  return (1);
}

int	rrb(s_tack *b)
{
  b = b->last;
  return (1);
}

int	ra(s_tack *a)
{
  a = a->next;
  return (1);
}

int	rb(s_tack *b)
{
  b = b->next;
  return (1);
}

int	rab(s_tack *a, s_tack *b)
{
  ra(a);
  rb(b);
  return (1);
}

int	rrab(s_tack *a, s_tack *b)
{
  rra(a);
  rrb(b);
  return (1);
}


int	sab(s_tack *a, s_tack *b)
{

  sa(a);
  sb(b);
  return (1);
}



int	sa(s_tack *a, s_tack *b)
{
  //s_tack *a_hold;
  s_tack *next_2;
  s_tack *item_2;
  //s_tack *last_2;


  if (!a)
    return (0);
  item_2 = a->next;
  next_2 = a->next->next;
  a->last->next = item_2;
  a->next->next->last = a;
  a->next->next = a;
  a->next->last = a->last;
  a->next = next_2;
  a->last = item_2;
  a = item_2;
  b += 0;

  return (1);
}

int	sb(s_tack *a, s_tack *b)
{
  //s_tack *a_hold;
  s_tack *next_2;
  s_tack *item_2;
  //s_tack *last_2;


  if (!b)
    return (0);
  item_2 = b->next;
  next_2 = b->next->next;
  b->last->next = item_2;
  b->next->next->last = a;
  b->next->next = a;
  b->next->last = a->last;
  b->next = next_2;
  b->last = item_2;
  b = item_2;
  a += 0;

  return (1);
}


int	pa(s_tack *a, s_tack *b)
{
  s_tack *b_hold;
  s_tack *src;
  s_tack *dst;


  src = b;
  dst = a;
  b = b->next;
  a = src;
  b_hold = src;
  if (!src || !src->last || !src->next)
    return (0);
  src->last->next = src->next;
  src->next->last = src->last;
  src->next = (dst) ? (dst) : (src);
  src->last = (dst && dst->last) ? (dst->last) : (src);
  (dst && dst->last) ? (dst->last->next = src) : (0);
  (dst) ? (dst->last = src) : (0);

  return (1);
}

int	pb(s_tack *a, s_tack *b)
{
  s_tack *a_hold;
  s_tack *src;
  s_tack *dst;


  src = a;
  dst = b;
  a = a->next;
  b = src;
  a_hold = src;
  if (!src || !src->last || !src->next)
    return (0);
  src->last->next = src->next;
  src->next->last = src->last;
  src->next = (dst) ? (dst) : (src);
  src->last = (dst && dst->last) ? (dst->last) : (src);
  (dst && dst->last) ? (dst->last->next = src) : (0);
  (dst) ? (dst->last = src) : (0);
  return (1);
}
