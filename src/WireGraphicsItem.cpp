#ifndef WIRE_GRAPHICS_ITEM_H
#define WIRE_GRAPHICS_ITEM_H

#include <iostream>
#include "imgui.h"
#include "WireGraphicsItem.hpp"

using namespace std;

sf::VertexArray& WireGraphicsItem::GetWire() {
  return wire_;
}

void WireGraphicsItem::SetCoordinates(float begin, float mid, float end) {
	begin_ = begin;
	mid_ = mid;
	end_ = end;
	wire_[0].position = sf::Vector2f(begin_, begin_);
	wire_[1].position = sf::Vector2f(end_, end_);
}

void WireGraphicsItem::SetGrabbed(bool grabbed) {
  grabbed_ = grabbed;
}

bool WireGraphicsItem::IsGrabbed() {
  return grabbed_;
}


void WireGraphicsItem::Draw() {
  //wire_[0].position = sf::Vector2f(begin_, begin_);
  //wire_[1].position = sf::Vector2f(end_, end_);

  std::cout << wire_.getVertexCount() << std::endl;

  //wire_[0].color = color_;
  //wire_[1].color = color_;
}

#endif //WIRE_GRAPHICS_ITEM_H
