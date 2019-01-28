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

int	rra(s_tack **a, s_tack **b)
{
  b += 0;
  a[0] = a[0]->last;
  return (NULL);
}

int	rrb(s_tack **a, s_tack **b)
{
  a += 0;
  b[0] = b[0]->last;
  return (NULL);
}

int	ra(s_tack **a, s_tack **b)
{
  b += 0;
  a[0] = a[0]->next;
  return (NULL);
}

int	rb(s_tack **a, s_tack **b)
{
  a += 0;
  b[0] = b[0]->next;
  return (NULL);
}

int	rab(s_tack **a, s_tack **b)
{
  rot_a(a, b);
  rot_b(a, b);
  return (NULL);
}

int	rrab(s_tack **a, s_tack **b)
{
  *a = rev_rot_a(a, b);
  *b = rev_rot_b(a, b);
  return (NULL);
}


int	sab(s_tack **a, s_tack **b)
{

  *a = swap_a(a, b);
  *b = swap_b(a, b);
  return (NULL);
}



int	sa(s_tack **a, s_tack **b)
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

int	sb(s_tack **a, s_tack **b)
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


int	pa(s_tack **a, s_tack **b)
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

int	pb(s_tack **a, s_tack **b)
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
