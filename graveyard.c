
int     do_swap(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  if (ay)
    {
      if (undo)
	{
	  sa(a, b, m);
	  m->moves--;
	  m->i--;
	  m->best[m->moves] = ' ';
	  return (1);
	}
      sa(a, b, m);
      m->best[m->moves] = 'a';
      m->moves++;
      return (1);
    }
  if (undo)
    {
      sb(a, b, m);
      m->moves--;
      m->best[m->moves] = ' ';
      return (1);
    }
  sb(a, b, m);
  m->best[m->moves] = 'b';
  m->moves++;
  return (1);
}

int     do_ss(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  ay+=0;
  if (undo)
    {
      sa(a, b, m);
      sb(a, b, m);
      m->moves--;
      m->best[m->moves] = ' ';
      return (1);
    }
  sa(a, b, m);
  sb(a, b, m);
  m->best[m->moves] = 'c';
  m->moves++;
  return (1);

}

int     do_push(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  if (ay)
    {
      if (undo)
        {
          pa(a, b, m);
          m->moves--;
          m->best[m->moves] = ' ';
          return (1);
        }
      pa(a, b, m);
      m->best[m->moves] = 'j';
      m->moves++;
      return (1);
    }
  if (undo)
    {
      pb(a, b, m);
      m->moves--;
      m->i--;
      m->best[m->moves] = ' ';
      return (1);
    }
  pb(a, b, m);
  m->best[m->moves] = 'k';
  m->moves++;
  m->i++;
  return (1);
}

int     do_rotate(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  if (ay)
    {
      if (undo)
        {
          rra(a, b, m);
          m->moves--;

          m->best[m->moves] = ' ';
          return (1);
        }
      ra(a, b, m);
      m->best[m->moves] = 'd';
      m->moves++;
      return (1);
    }
  if (undo)
    {
      rrb(a, b, m);
      m->moves--;
      m->best[m->moves] = ' ';
      return (1);
    }
  rb(a, b, m);
  m->best[m->moves] = 'e';
  m->moves++;
  return (1);
}

int do_rr(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  ay+=0;
  if (undo)
    {
      rrab(a, b, m);
      m->moves--;

      m->best[m->moves] = ' ';
      return (1);
    }
  rab(a, b, m);
  m->best[m->moves] = 'f';
  m->moves++;
  return (1);
}

int    do_rev_rotate(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  if (ay)
    {
      if (undo)
        {
          ra(a, b, m);
          m->moves--;
          m->best[m->moves] = ' ';
          return (1);
        }
      rra(a, b, m);
      m->best[m->moves] = 'g';
      m->moves++;
      return (1);
    }
  if (undo)
    {
      rb(a, b, m);
      m->moves--;

      m->best[m->moves] = ' ';
      return (1);
    }
  rrb(a, b, m);
  m->best[m->moves] = 'h';
  m->moves++;
  return (1);
}

int do_rrr(s_tack **a, s_tack **b, m_et *m, int undo, int ay)
{
  ay+=0;
  if (undo)
    {
      rab(a, b,m);
      m->moves--;
      m->best[m->moves] =' ';
      return (1);
    }
  rrab(a, b, m);
  m->best[m->moves] = 'i';
  m->moves++;
  return (1);
}

int     rec(s_tack **a, s_tack *b, m_et *m)
{
  v_is(a[0], b, m);
  /*if (m->i > 12)
    {
      printf("LAST MOVE%c\n moves:%d", m->best[(m->moves - 1)], m->moves);
      }*/
  if (s_tage2(a, b, m))
    {
      f_inish(a, b, m);
      return (1);
    }
  if(m->moves >= (m->req - m->len_b))
    return (0);

do_ss(a, &b, m, 0, 0); //ss
if (!L_AST(m, 'c') && !L_AST(m, 'b') && !L_AST(m, 'a') && rec(a, b, m))
  return (1);
do_ss(a, &b, m, 1, 0);

do_swap(a, &b, m, 0, 1); //sa
if (!L_AST(m, 'c') && !L_AST(m, 'b') && !L_AST(m, 'a') && rec(a, b, m))
  return (1);
do_swap(a, &b, m, 1, 1);

do_swap(a, &b, m, 0, 0); //sb
if (!L_AST(m, 'c') && !L_AST(m, 'b') && !L_AST(m, 'a') && rec(a, b, m))
  return (1);
do_swap(a, &b, m, 1, 0);

do_push(a, &b, m, 0, 1); //pa
if (!L_AST(m, 'k') && rec(a, b, m))
  return (1);
do_push(a, &b, m, 1, 1);

do_push(a, &b, m, 0, 0); //pb
if (!L_AST(m, 'j') && rec(a, b, m))
  return (1);
do_push(a, &b, m, 1, 0);

do_rr(a, &b, m, 0, 0); //rr
if (!L_AST(m, 'i') && !L_AST(m, 'g') && !L_AST(m, 'h') && !L_AST(m, 'e') && !L_AST(m, 'f') && rec(a, b, m))
  return (1);
do_rr(a, &b, m, 1, 0);

do_rotate(a, &b, m, 0, 1); //ra
if (!L_AST(m, 'i') && !L_AST(m, 'g') && !L_AST(m, 'h') && !L_AST(m, 'e') && !L_AST(m, 'f') && rec(a, b, m))
  return (1);
do_rotate(a, &b, m, 1, 1);

do_rotate(a, &b, m, 0, 0);  //rb
if (!L_AST(m, 'i') && !L_AST(m, 'g') && !L_AST(m, 'h') && !L_AST(m, 'e') && !L_AST(m, 'f') && rec(a, b,m))
  return (1);
do_rotate(a, &b, m, 1, 0);

do_rrr(a, &b, m, 0, 0);  //rrr
if (!L_AST(m, 'f') && !L_AST(m, 'i') && !L_AST(m, 'g') && !L_AST(m, 'h') && !L_AST(m, 'e') && rec(a, b, m))
  return (1);
do_rrr(a, &b, m, 1, 0);

do_rev_rotate(a, &b, m, 0, 1); //rra
if (!L_AST(m, 'd') && !L_AST(m, 'f') && rec(a, b, m))
  return (1);
do_rev_rotate(a, &b, m, 1, 1);

do_rev_rotate(a, &b, m, 0, 0);  //rrb
if (!L_AST(m, 'e') && !L_AST(m, 'f') && rec(a, b, m))
  return (1);
do_rev_rotate(a, &b, m, 1, 0);

return (0);
}
