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

#include <stdio.h>

typedef struct s_tacks		s_tack;

struct			s_tacks
{
	long value;
	int rank;
	s_tack *next;
	s_tack *last;
}
