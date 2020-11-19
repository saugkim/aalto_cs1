#ifndef RESISTOR_GRAPHICS_ITEM_H
#define RESISTOR_GRAPHICS_ITEM_H

#include <iostream>
#include "imgui.h"
#include "ResistorGraphicsItem.hpp"

using namespace std;

sf::RectangleShape& ResistorGraphicsItem::GetRectShape() {
  return rect_;
}

int ResistorGraphicsItem::GetHeight() {
  return height_;
}

int ResistorGraphicsItem::GetWidth() {
  return width_;
}

void ResistorGraphicsItem::SetCoordinates(float x, float y) {
	x_ = x;
	y_ = y;
	rect_.setPosition(x, y);
}

std::string ResistorGraphicsItem::GetCoordinates() {
	return std::to_string(x_) + ", " + std::to_string(y_);
}

void ResistorGraphicsItem::SetGrabbed(bool grabbed) {
  grabbed_ = grabbed;
}

bool ResistorGraphicsItem::IsGrabbed() {
  return grabbed_;
}

void ResistorGraphicsItem::Draw() {
  rect_.setFillColor(color_);
  rect_.setSize(sf::Vector2f(width_, height_)); 
  rect_.setPosition(x_, y_);
}

void ResistorGraphicsItem::Menu() {
  ImGui::SetNextWindowPos(ImVec2(x_ + 2, y_ + 2));
  ImGui::Begin(text_);
  ImGui::Text("resistor text");
  ImGui::End();
}
#endif //RESISTOR_GRAPHICS_ITEM_H
