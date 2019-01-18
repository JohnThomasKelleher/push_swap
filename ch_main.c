/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:14:24 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/17 22:27:47 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hache.h>

#store input in A, then read from 0

s_tack	*next_A(long hold)
{
	stack *new;

	new = malloc(sizeof(s_tack));
	new->value = hold;
	return (new);
}

void	init_a(s_tack *A, int argc, char **argv, int *sort)
{
	long hold;
	int i;
	s_tack *head;

	head = A;
	i = 2;
	if (!(hold = itoa(argv[1])))
		return (0);
	A->value = hold;
	while (i < argc)
	{
		if (!(hold = itoa(argv[i])))
				return (0);
		sort[i] = hold;
		A->next = next_A(hold);
		A = A->next;
		i++;
	}
	sort[0] = argc;
	head->last = A;
	A->next = head;
	return (1);
}	

void	s_ort(int *sort)
{
	 int i;
	int not_sorted;
	int at_least_one;

	
	not_sorted = 1;

	 i = 1;
	 while (not_sorted)
	 {
		 if (sort[i] > sort[(i + 1)])
		{
			at_least_one = 1;
			hold = sort[i];
			sort[i] = sort[(i + 1)];
			sort[(i + 1)] = hold;
		}
		i++;
		 if (i == sort[0])
		 {
			 if(at_least_one == 0)
				 not_sorted = 0;
			 i = 1;
			 at_least_one = 0;
		 }
	 }
}

void	r_ank(int *sort, s_tack *A)
{
	int i;
	s_tack *head;

	head = A;
	i = 1;
	while (i < sort[0])
	{
		A = head;
		while (A)
		{
			if (A->value == sort[i])
				A->rank = i;
			A = A->next;
		}
		i++;
	}
}

int		o_perate(s_tack *a, s_tack *b)
{
	//return 1 if everything went ok, 0 if invalid operations
}

int		c_heck(s_tack *a_head, s_tack *b_head, int *sort)
{

}

int		main(int argc, char **argv)
{
	s_tack A_head[1];
	s_tack B[1];
	int sort[argc];
	int ret;

	argv[argc] = NULL;
	if (argc == 1)
		return (0);
	if (!init_a(A_head), argc, argv, sort)
		return (0);
	s_ort(sort);
	if (!o_perate(A_head, B))
		ft_error();
	if (1 == (ret = c_heck(A_head, sort)))
		printf("OK\n");
	else if (ret == 0)
		printf("KO\n");
	else
		ft_error();
}
