#include <SFML/Graphics.hpp>

class WireGraphicsItem {
  public:
    WireGraphicsItem(float begin = 100, float mid = 100, float end = 300) 
      : begin_(begin), mid_(mid), end_(end), grabbed_(false) {      
      sf::VertexArray wire_(sf::LineStrip, 2);

      wire_[0] = sf::Vector2f(begin_, mid_);
      wire_[1] = sf::Vector2f(mid_, end_);
      wire_[0].color = sf::Color::Red;
      text_ = "Wire";
      Draw();
    };

    sf::VertexArray& GetWire();

    void SetCoordinates(float begin, float mid, float end);

    void SetGrabbed(bool grabbed);
    bool IsGrabbed();

    void Draw();
  protected:
    sf::VertexArray wire_;
    sf::Color color_;

  private:
    float begin_;
    float mid_;
    float end_;
    const char* text_;
    bool grabbed_;
};
