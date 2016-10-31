//
// Arbitre.cpp for Arbitre in /home/lalin_r/rendu/gommoku/lalin_r
// 
// Made by lalin_r
// Login   <lalin_r@epitech.net>
// 
// Started on  Sun Oct 30 11:30:37 2016 lalin_r
// Last update Mon Oct 31 10:50:48 2016 lalin_r
//

#include	"Arbitre.hh"

Arbitre::Arbitre()
{
  int	i = 0;
  int	j = 0;

  _player_1 = 0;
  _player_2 = 0;
  _map = (int **)(malloc(sizeof(int *) * 19));
  while (j < 19)
    _map[j++] = (int *)(malloc(sizeof(int) * 19));
  while (i < 19)
    {
      j = 0;
      while (j < 19)
	_map[i][j++] = 0;
      i++;
    }
}

Arbitre::Arbitre(int **map)
{
}

Arbitre::~Arbitre()
{
}

int	Arbitre::check_unassaillable_d_h_g(int **tab, int i, int j, int player)
{
  while (i >= 0 && j >= 0)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i--;
      j--;
    }
  return (2);
}

int	Arbitre::check_unassaillable_d_h_d(int **tab, int i, int j, int player)
{
  while (i >= 0 && j < 19)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i--;
      j++;
    }
  return (2);
}

int	Arbitre::check_unassaillable_d_b_g(int **tab, int i, int j, int player)
{
  while (i < 19 && j >= 0)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i++;
      j--;
    }
  return (2);
}

int	Arbitre::check_unassaillable_d_b_d(int **tab, int i, int j, int player)
{
  while (i < 19 && j < 19)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i++;
      j++;
    }
  return (2);
}

int	Arbitre::check_unassaillable_h(int **tab, int i, int j, int player)
{
  while (i >= 0)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i--;
    }
  return (2);
}

int	Arbitre::check_unassaillable_b(int **tab, int i, int j, int player)
{
  while (i < 19 && j>= 0)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      i++;
    }
  return (2);
}

int	Arbitre::check_unassaillable_g(int **tab, int i, int j, int player)
{
  while (j>= 0)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      j--;
    }
  return (2);
}

int	Arbitre::check_unassaillable_d(int **tab, int i, int j, int player)
{
  while (j < 19)
    {
      if (tab[i][j] == 0)
	return (0);
      if (tab[i][j] != player)
	return (1);
      j++;
    }
  return (2);
}

int	Arbitre::tmp_d_h_g(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_d_h_g(tab, i - 1, j - 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_d_h_d(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_d_h_d(tab, i - 1, j + 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_d_b_g(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_d_b_g(tab, i + 1, j - 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_d_b_d(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_d_b_d(tab, i + 1, j + 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_h(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_h(tab, i, j - 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_b(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_b(tab, i, j + 1, player, five + 1));
  return (0);
}

int	Arbitre::tmp_g(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_g(tab, i - 1, j, player, five + 1));
  return (0);
}

int	Arbitre::tmp_d(int **tab, int i, int j, int player, int five)
{
  if (five == 5)
    return (1);
  if ((i < 0 || j < 0) && (i >= 19 || j >= 19))
    return (0);
  if (tab[i][j] == player)
    return (tmp_d(tab, i + 1, j, player, five + 1));
  return (0);
}

int	Arbitre::check_take()
{
  if (_player_1 == 10)
    return (1);
  if (_player_2 == 10)
    return (2);
  return (0);
}

int	Arbitre::check_exist(int earth)
{
  if (earth == 0)
    return (0);
  return (-1);
}

int	Arbitre::check_win_five(int **tab, int start_i, int start_j, int end_i, int end_j)
{
  int	i = start_i;
  int	j = start_j;

  if (start_i == end_i && start_j == end_j)
    return (1);
  /*if (check_unassaillable_d_h_g(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_d_h_d(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_d_b_g(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_d_b_d(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_h(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_b(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_g(tab, i, j, tab[i][j]) >= 1 &&
    check_unassaillable_d(tab, i, j, tab[i][j]) >= 1)*/
  if (check_unassaillable_d_h_g(tab, i, j, tab[i][j]) +
      check_unassaillable_d_b_d(tab, i, j, tab[i][j]) >= 2 &&
      check_unassaillable_d_h_d(tab, i, j, tab[i][j]) +
      check_unassaillable_d_b_g(tab, i, j, tab[i][j]) >= 2 &&
      check_unassaillable_h(tab, i, j, tab[i][j]) +
      check_unassaillable_b(tab, i, j, tab[i][j]) >= 2 &&
      check_unassaillable_g(tab, i, j, tab[i][j]) +
      check_unassaillable_d(tab, i, j, tab[i][j]) >= 2)
    {
      if (start_i != end_i && start_j != end_j)
	{
	  if (start_i < end_i)
	    {
	      if (start_j < end_j)
		return (check_win_five(tab, start_i + 1, start_j + 1, end_i, end_j));
	      return (check_win_five(tab, start_i + 1, start_j - 1, end_i, end_j));
	    }
	  else
	    { 
	      if (start_j < end_j)
		return (check_win_five(tab, start_i - 1, start_j + 1, end_i, end_j));
	      return (check_win_five(tab, start_i - 1, start_j - 1, end_i, end_j));
	    }
	}
      if (start_j != end_j)
	{
	  if (start_j < end_j)
	    return (check_win_five(tab, start_i, start_j + 1, end_i, end_j));
	  return (check_win_five(tab, start_i, start_j - 1, end_i, end_j));
	}
      if (start_i != end_i)
	{
	  if (start_i < end_i)
	    return (check_win_five(tab, start_i + 1, start_j, end_i, end_j));
	  return (check_win_five(tab, start_i - 1, start_j, end_i, end_j));
	}
    }
  return (0);
}

int	Arbitre::check_five()
{
  int	i = 0;
  int	j = 0;
  int	tmp = 0;

  while (i < 19)
    {
      while (j < 19)
	{
	  if (_map[i][j] != 0)
	    {
	      if (tmp_d_h_g(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i - 5, j - 5);
	      if (tmp_d_h_d(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i - 5, j + 5);
	      if (tmp_d_b_g(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i + 5, j - 5);
	      if (tmp_d_b_d(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i + 5, j + 5);
	      if (tmp_h(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i, j - 5);
	      if (tmp_b(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i, j + 5);
	      if (tmp_g(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i - 5, j);
	      if (tmp_d(_map, i, j, _map[i][j], 0) == 1)
		tmp += check_win_five(_map, i, j, i + 5, j);
	      if (tmp >= 1)
		return (1);
	    }
	  j++;
	}
      i++;
      j = 0;
    }
  return (0);
}

void	Arbitre::add_prise(int player)
{
  if (player == 1)
    _player_1++;
  else
    _player_2++;
}

int	Arbitre::fill_d_h_g(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_d_h_g(i - 1, j - 1, player));
}

int	Arbitre::fill_d_h_d(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_d_h_d(i - 1, j + 1, player));
}

int	Arbitre::fill_d_b_g(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_d_b_g(i + 1, j - 1, player));
}

int	Arbitre::fill_d_b_d(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_d_b_d(i + 1, j + 1, player));
}

int	Arbitre::fill_h(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_h(i - 1, j, player));
}

int	Arbitre::fill_b(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_b(i + 1, j, player));
}

int	Arbitre::fill_g(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_g(i, j - 1, player));
}

int	Arbitre::fill_d(int i, int j, int player)
{
  if (_map[i][j] == player || _map[i][j] == 0)
    return (0);
  _map[i][j] == player;
  return (fill_d(i - 1, j + 1, player));
}

int	Arbitre::check_prise_d_h_g(int i, int j, int player, int nb)
{
  if (i < 0 || j < 0)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_d_b_d(i + 1, j + 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_d_h_g(i - 1, j - 1, player, nb));
}

int	Arbitre::check_prise_d_h_d(int i, int j, int player, int nb)
{
  if (i < 0 || j >= 19)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_d_b_g(i + 1, j - 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_d_h_d(i - 1, j + 1, player, nb));
}

int	Arbitre::check_prise_d_b_g(int i, int j, int player, int nb)
{
  if (i >= 19 || j < 0)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_d_h_d(i - 1, j + 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_d_b_g(i + 1, j - 1, player, nb));
}

int	Arbitre::check_prise_d_b_d(int i, int j, int player, int nb)
{
  if (i >= 19 || j >= 19)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_d_h_g(i - 1, j - 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_d_b_d(i + 1, j + 1, player, nb));
}

int	Arbitre::check_prise_h(int i, int j, int player, int nb)
{
  if (i < 0)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_b(i + 1, j, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_h(i - 1, j, player, nb));
}

int	Arbitre::check_prise_b(int i, int j, int player, int nb)
{
  if (i >= 19)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_h(i - 1, j, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_b(i + 1, j, player, nb));
}

int	Arbitre::check_prise_g(int i, int j, int player, int nb)
{
  if (j < 0)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_d(i, j + 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_g(i, j - 1, player, nb));
}

int	Arbitre::check_prise_d(int i, int j, int player, int nb)
{
  if (j >= 19)
    return (0);
  if (_map[i][j] != player)
    nb++;
  if (_map[i][j] == player)
    {
      fill_g(i, j - 1, player);
      while (nb != 0)
	{
	  add_prise(player);
	  nb--;
	}
      return (1);
    }
  return (check_prise_d(i, j + 1, player, nb));
}

int	Arbitre::check_prise(int i, int j)
{
  int	tmp = 0;

  tmp += check_prise_d_h_g(i - 1, j - 1, _map[i][j], 0);
  tmp += check_prise_d_h_d(i - 1, j + 1, _map[i][j], 0);
  tmp += check_prise_d_b_g(i + 1, j - 1, _map[i][j], 0);
  tmp += check_prise_d_b_d(i + 1, j + 1, _map[i][j], 0);
  tmp += check_prise_h(i - 1, j, _map[i][j], 0);
  tmp += check_prise_b(i + 1, j, _map[i][j], 0);
  tmp += check_prise_g(i, j - 1, _map[i][j], 0);
  tmp += check_prise_d(i, j + 1, _map[i][j], 0);
  if (tmp != 0)
    return (check_take());
  return (0);
}
