#ifndef WIRE_GRAPHICS_ITEM_H
#define WIRE_GRAPHICS_ITEM_H

#include <iostream>
#include "imgui.h"
#include "WireGraphicsItem.hpp"

using namespace std;

//sf::Vertex& WireGraphicsItem::GetWire() {
	
//	return null;
//  return wire_;
//}

void WireGraphicsItem::SetCoordinates(float begin, float mid, float end) {
	begin_ = begin;
	mid_ = mid;
	end_ = end;
	
	//wire_ = {
	//	sf::Vertex(sf::Vector2f(begin_, begin_)), 
	//	sf::Vertex(sf::Vector2f(mid_, mid_)), 
	//	sf::Vertex(sf::Vector2f(end_, end_))
	//};
}

void WireGraphicsItem::SetGrabbed(bool grabbed) {
  grabbed_ = grabbed;
}

bool WireGraphicsItem::IsGrabbed() {
  return grabbed_;
}


void WireGraphicsItem::Draw() {
  wire_[0].color = color_;
  //wire_[1].setFillColor(color_);
  //wire_[2].setFillColor(color_);
  //wire_.setFillColor(color_);
}

#endif //WIRE_GRAPHICS_ITEM_H
