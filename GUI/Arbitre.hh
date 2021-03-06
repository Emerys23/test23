//
// Arbitre.hh for Arbitre in /home/lalin_r/rendu/gommoku/lalin_r
// 
// Made by lalin_r
// Login   <lalin_r@epitech.net>
// 
// Started on  Sun Oct 30 11:30:14 2016 lalin_r
// Last update Tue Nov  1 22:59:42 2016 lalin_r
//

#ifndef		ARBITRE_HH_
# define	ARBITRE_HH_

#include	<cstdlib>
#include	<vector>
#include	<iostream>

class		Modif
{
private:
  int	posX;
  int	posY;
  int	player;
public:
  Modif();
  ~Modif();
  int	get_posX();
  int	get_posY();
  void	set_posX(int);
  void	set_posY(int);
  int	get_player();
  void	set_player(int);
};

class		Arbitre
{
private:
  int		_player_1;
  int		_player_2;
  int		**_map;
  std::vector<Modif>	*_modif;

public:
  Arbitre();
  ~Arbitre();
  Arbitre(int **);
  int	check_take();
  int	check_exist(int);
  int	check_five();
  int	check_prise(int, int);
  int	check_rules(int, int, int);
  std::vector<Modif>	*get_modif();
  void	set_map(int **tab);
  void	add_prise(int);
  int	check_win_five(int **, int, int, int, int);
  int	tmp_d_h_g(int **, int, int, int, int);
  int	tmp_d_h_d(int **, int, int, int, int);
  int	tmp_d_b_g(int **, int, int, int, int);
  int	tmp_d_b_d(int **, int, int, int, int);
  int	tmp_h(int **, int, int, int, int);
  int	tmp_b(int **, int, int, int, int);
  int	tmp_g(int **, int, int, int, int);
  int	tmp_d(int **, int, int, int, int);
  int	check_unassaillable_d_h_g(int **, int, int, int);
  int	check_unassaillable_d_h_d(int **, int, int, int);
  int	check_unassaillable_d_b_g(int **, int, int, int);
  int	check_unassaillable_d_b_d(int **, int, int, int);
  int	check_unassaillable_h(int **, int, int, int);
  int	check_unassaillable_b(int **, int, int, int);
  int	check_unassaillable_g(int **, int, int, int);
  int	check_unassaillable_d(int **, int, int, int);
  int	check_prise_d_h_g(int, int, int, int);
  int	check_prise_d_h_d(int, int, int, int);
  int	check_prise_d_b_g(int, int, int, int);
  int	check_prise_d_b_d(int, int, int, int);
  int	check_prise_h(int, int, int, int);
  int	check_prise_b(int, int, int, int);
  int	check_prise_g(int, int, int, int);
  int	check_prise_d(int, int, int, int);
  int	fill_d_h_g(int, int, int);
  int	fill_d_h_d(int, int, int);
  int	fill_d_b_g(int, int, int);
  int	fill_d_b_d(int, int, int);
  int	fill_h(int, int, int);
  int	fill_b(int, int, int);
  int	fill_g(int, int, int);
  int	fill_d(int, int, int);
};

#endif
