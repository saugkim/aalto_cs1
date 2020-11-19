#include <SFML/Graphics.hpp>

class WireGraphicsItem {
  public:
  
    WireGraphicsItem(float begin = 100, float mid = 200, float end = 300) 
      : begin_(begin), mid_(mid), end_(end), grabbed_(false) {
      
	      
        sf::Vertex wire_[] = {
	      sf::Vertex(sf::Vector2f(begin_, begin_)),
		  sf::Vertex(sf::Vector2f(mid_, mid_)),
	      sf::Vertex(sf::Vector2f(end_, end_))
      };

      color_ = sf::Color::Red;
      wire_[0].color = color_;
      wire_[1].color = color_;
      wire_[2].color = color_;
      text_ = "Wire";
      Draw();
    };

    //sf::Vertex& GetWire();

    void SetCoordinates(float begin, float mid, float end);

    void SetGrabbed(bool grabbed);
    bool IsGrabbed();

    void Draw();
 
  private:
    float begin_;
    float mid_;
    float end_;
    const char* text_;
    bool grabbed_;
 protected:
    sf::Color color_;
	sf::Vertex wire_[];

};
