#include <SFML/Graphics.hpp>

class Grid {
  public:
    Grid(int width, int height);
    std::vector<sf::CircleShape>& GetGrid();

    void CreateGrid();
  protected:
    std::vector<sf::CircleShape> grid_;
    int size_;
};
