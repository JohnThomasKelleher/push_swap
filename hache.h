/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hache.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:05:12 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/17 22:13:26 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HACHE_H
# define HACHE_H
#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

#define SWAPA(a) (a->rank == (a->next->rank + 1))
#define SWAPB(b) (b->rank == (b->next->rank - 1))
#define SWAPAB(a, b) (SWAPA2(a) && SWAPB2(b))
#define SWAPA2(a) (SWAPA(a) || a->rank > a->next->rank)
#define SWAPB2(b) (SWAPB(b) || b->rank < b->next->rank)
#define PUSHA(a, b) (b->rank == (a->rank - 1))
#define PUSHB(a, b) (a->rank == (b->rank + 1))


typedef struct s_tacks		s_tack;
typedef struct s_meta		m_et;

struct			s_tacks
{
	long value;
	int rank;
	s_tack *next;
	s_tack *last;
  s_tack *n;
  s_tack *l;
};


struct			s_meta
{
  char *best;//0 = sa 1 = sb 2 = sab 3 = ra 4 = rb 5 = rab 6 = rra 7 = rrb 8 = rrab 9 = pa 10 = pb 11 = pab  
  long pivot;
  int num_elem;
  int len;
  int len_a;
  int len_b;
  int ret;
  int calls;
  int min;
};   



void    a_nswer(s_tack a, m_et m);
void    s_plit(s_tack *a, s_tack *b, m_et m);
int     c_heck2(s_tack *a, s_tack *b, m_et m);
int     rec(s_tack *a, s_tack *b, m_et m);
int     s_tage2(s_tack *a, s_tack *b, m_et m);
int             c_heck(s_tack *a_head, int *sort);
s_tack *swap_a(s_tack **a, s_tack **b);
s_tack *swap_b(s_tack **a, s_tack **b);
s_tack  *rev_rot_a(s_tack **a, s_tack **b);
s_tack  *rev_rot_b(s_tack **a, s_tack **b);
s_tack *rot_a(s_tack **a, s_tack **b);
s_tack *rot_b(s_tack **a, s_tack **b);
s_tack  *r_ab(s_tack **a, s_tack **b);
s_tack  *rr_ab(s_tack **a, s_tack **b);
s_tack  *swap_ab(s_tack **a, s_tack **b);
s_tack *swap_a(s_tack **a, s_tack **b);
s_tack *swap_b(s_tack **a, s_tack **b);
s_tack  *push_a(s_tack **a, s_tack **b);
s_tack  *push_b(s_tack **a, s_tack **b);
int     rra(s_tack *a);
int     rrb(s_tack *b);
int     ra(s_tack *a);
int     rb(s_tack *b);
int     rab(s_tack *a, s_tack *b);
int     rrab(s_tack *a, s_tack *b);
int     sab(s_tack *a, s_tack *b);
int     sa(s_tack *a);
int     sb(s_tack *b);
int     pa(s_tack *a, s_tack *b);
  int     pb(s_tack *a, s_tack *b);


#endif
