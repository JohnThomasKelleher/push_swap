/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 23:17:50 by jkellehe          #+#    #+#             */
/*   Updated: 2019/01/28 23:18:01 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hache.h"

int           main(int argc, char **argv)
{
  s_tack A;
  s_tack B;
  int sort[argc];
  int ret;

  B.next = NULL; B.last = NULL;
  A.next = NULL; A.last = NULL;
  //ft_memset(&A, 0, sizeof A);
  //ft_memset(&B, 0, sizeof B);
  argv[argc] = NULL;
  if (argc == 1)
    return (0);
  if (!init_a(&A, argc, argv, sort))
    {
      printf("%s", "Error\n");
      return (0);
    }
  s_ort(sort);
  if ((ret = o_perate(&A, &B, sort)))
    printf("OK\n");
  else if (ret == 0)
    printf("KO\n");
  else
    ft_error();
  return (0);
}
