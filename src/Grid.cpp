#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "Grid.hpp"

using namespace std;

Grid::Grid(int width, int height) {
    sf::Color black = sf::Color::Black;
    //std::vector<sf::CircleShape> grid_;
    for (int x = 50; x < width; x+=50) {
      for (int y = 50; y < height; y+=50) {
        sf::CircleShape c;
        c.setRadius(1);
        c.setFillColor(black);
        c.setPosition(x, y);
        grid_.push_back(c);
      }
    }

}

std::vector<sf::CircleShape>& Grid::GetGrid() {
  return grid_;
}
#endif //GRID_H
