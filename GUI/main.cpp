#include "SFML/Graphics.hpp"

#include "Graphic.hpp"

int		main()
{
  sf::RenderWindow	window(sf::VideoMode(1024, 768), "Gomoku");
  Graphic		*graphic = new Graphic(window);

  graphic->run();
  return 0;
}
