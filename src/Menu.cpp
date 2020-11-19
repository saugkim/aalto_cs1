#ifndef MENU_H
#define MENU_H
#include "imgui.h"
#include <string>
#include <iostream>

#include "Menu.hpp"
#include "menuConsts.cpp"

using namespace std;

void Menu::Show(string& action, bool menuActive) {
	ImGui::SetNextWindowPos(ImVec2(5, 5));
	ImGui::Begin("Menu", &menuActive, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar()) {
	  if (ImGui::BeginMenu("Items")) {
	    if (ImGui::MenuItem("Resistor")) {
	      action = RESISTOR;
	    }

	    if (ImGui::MenuItem("Wire")) {
	      action = WIRE;
	    }

	  ImGui::EndMenu();
	  }
	ImGui::EndMenuBar();
	}
	ImGui::End();
	/*ImGui::Begin("Main menu");

	if (ImGui::Button("Save")) {
	  action = "save";
	}
	if (ImGui::Button("Add")) {
	  action = "add";
	}
	//ImGui::Text(text_);
	ImGui::End();
	*/

}

#endif //MENU_H
