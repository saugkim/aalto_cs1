#include <SFML/Graphics.hpp>

class ResistorGraphicsItem {
  public:
    ResistorGraphicsItem(int width = 100, int height = 100, float xPos = 300, float yPos = 400) 
      : width_(width), height_(height), x_(xPos), y_(yPos), grabbed_(false) {
      sf::RectangleShape rect_;
      sf::Vector2f size_(100, 100);
      color_ = sf::Color::Black;  
      text_ = "Resistor";
      Draw();
    };

    sf::RectangleShape& GetRectShape();

    int GetHeight();
    int GetWidth();

    void SetCoordinates(float x, float y);
    std::string GetCoordinates();

    void SetGrabbed(bool grabbed);
    bool IsGrabbed();

    void Draw();
    void Menu();
  protected:
    sf::RectangleShape rect_;
    sf::Color color_;
    sf::Vector2f size_;

  private:
    float x_;
    float y_;
    int width_;
    int height_;
    const char* text_;
    bool grabbed_;
};
