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

#define SWAPA(s_tack a) (a->rank = (a.next->rank + 1));
#define SWAPB(s_tack b) (b->rank = (b.next->rank - 1));
#define SWAPAB(s_tack a, s_tack b) (SWAPA(a) && SWAPB(b));
#define SWAPA2(s_tack a) (SWAPA(a) || a->rank > a.next->rank);
#define SWAPB2(s_tack b) (SWAPB(b) || b->rank < b.next->rank);
typedef struct s_tacks		s_tack;

struct			s_tacks
{
	long value;
	int rank;
	s_tack *next;
	s_tack *last;
  s_tack *n;
  s_tack *l;
};

typedef struct s_meta		met;

struct			met
{
  char *best;//0 = sa 1 = sb 2 = sab 3 = ra 4 = rb 5 = rab 6 = rra 7 = rrb 8 = rrab 9 = pa 10 = pb 11 = pab  
  long pivot;
  int num_elem;
  int len;
  int len_a;
  int len_b;
  int ret;
};

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

#endif
