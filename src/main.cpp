#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#include <math.h>

//Include graphics items
#include "ResistorGraphicsItem.hpp"
#include "WireGraphicsItem.hpp"
#include "Menu.hpp"
#include "Grid.hpp"
#include "menuConsts.cpp"

//kim
#include "PopupMenu.h"
//https://pyimgui.readthedocs.io/en/latest/reference/imgui.core.html

int main()
{
    int width = 800;
    int height = 600;
    sf::Color backgroundColor(255, 255, 255);
    sf::RenderWindow window(sf::VideoMode(width, height), "Circuit sim");
    window.setFramerateLimit(60);
	
	//sf::Vertex vertex(sf::Vector2f(10.f, 50.f), sf::Color::Red, sf::Vector2f(100.f, 100.f));

    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    std::string mainMenuAction = "";
    char* text = (char*)"test text";
    Menu mainMenu = Menu(text);   
    std::vector<ResistorGraphicsItem> ResistorGroup;
	std::vector<WireGraphicsItem> WireGroup;
    
    //create grid
    Grid grid = Grid(width, height);
	
    bool mainMenuActive = false;
	
	//kim
	std::string componentGroupName = "NONE";
	int componentIndexAtGroup = -1;
	static bool showWindow = false;
	
	
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

	    switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
				
			case sf::Event::MouseButtonPressed:
				/*for (auto& resistor : ResistorGroup) {  // -> for loop with vector index
					if (event.mouseButton.button == sf::Mouse::Left) {
						if (resistor.GetRectShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							resistor.SetGrabbed(true);
						}
					}
				}*/
				int i;
				int groupLength; 
				groupLength = ResistorGroup.size();
				for (i = 0 ; i < groupLength ; i ++) {
					if (ResistorGroup[i].GetRectShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						
						if (event.mouseButton.button == sf::Mouse::Left) {
							ResistorGroup[i].SetGrabbed(true);
						}
						
						if (event.mouseButton.button == sf::Mouse::Right) {
							std::cout << "right click" << std::endl;
							
							showWindow = true;
							componentGroupName = "RESISTOR";
							componentIndexAtGroup = i;
						}
					}
				}
				break;	
				
			case sf::Event::MouseMoved:
				for (auto& resistor : ResistorGroup) { 
					if (resistor.IsGrabbed()) {
						resistor.SetCoordinates(event.mouseMove.x - (resistor.GetWidth() / 2.0), event.mouseMove.y - (resistor.GetHeight() / 2.0));
					}  
				}
                break;
				
			case sf::Event::MouseButtonReleased:
				for (auto& resistor : ResistorGroup) {
					if (resistor.IsGrabbed()) {
						float nearestTenX = nearbyintf(event.mouseButton.x - (resistor.GetWidth() / 2.0));
						int nTx = nearbyint(nearestTenX - fmod(nearestTenX, 50));
		    
						float nearestTenY = nearbyintf(event.mouseButton.y - (resistor.GetHeight() / 2.0));
						int nTy = nearbyint(nearestTenY - fmod(nearestTenY, 50));

						resistor.SetCoordinates(nTx, nTy);
						resistor.SetGrabbed(false);
					}
				}
                break;
				
			default:
				break;
		}	  
    }

	ImGui::SFML::Update(window, deltaClock.restart());
	
	
	if (showWindow && componentGroupName == "RESISTOR") {
		ShowWindowRightClickEvent(showWindow, ResistorGroup, componentIndexAtGroup);
	}	
	
	/*
	ImGui::SetNextWindowPos(ImVec2(450, 10));
	if (showWindow) {
		
		if(!ImGui::Begin("Control Window", &showWindow)) {
			ImGui::End();
		} 
		else {
			float fvalue;
			//fvalue = ResistorGroup[componentIndexAtGroup].getValue();
			
			if (ImGui::DragFloat("value", &fvalue, 1.0f, 0.0f, 100.0f, "%.2f")){
				//resistor.setValue(fvalue);
				std::cout << fvalue << std::endl;
			}
			
			if (ImGui::Button("Remove")) {
				//remove this-> ResistorGroup[componentIndexAtGroup]
				//ResistorGroup.erase(ResistorGroup.begin() + componentIndexAtGroup);
				std::cout << "removed" <<std::endl;
				showWindow=false;
			}
			
			if (ImGui::Button("Close")) {
				showWindow=false;
			}
			
            ImGui::End();
		}
	} else {
		//reset value
		componentIndexAtGroup = -1;
	}
	*/


	ImVec2(0, 0);
	mainMenu.Show(mainMenuAction, mainMenuActive);
	
	if (mainMenuAction == RESISTOR) {
		ResistorGraphicsItem r = ResistorGraphicsItem();
        ResistorGroup.push_back(r);
	}

	if (mainMenuAction == WIRE) {
        WireGraphicsItem w = WireGraphicsItem(50, 100, 150);
		WireGroup.push_back(w);
	}

	mainMenuAction = "";

    window.clear(backgroundColor);

	for (auto& g : grid.GetGrid()) {
		window.draw(g);
	}

    for (auto& resistor : ResistorGroup) { 
		window.draw(resistor.GetRectShape());
    }
	
	for (auto& wire : WireGroup) {
		window.draw(wire.GetWire());
	}
	
	ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
	
	return 0;
}
						/* ImGui::Begin("Control Window");
						
						if (ImGui::BeginPopupContextWindow())
						{
							float f1 = 1.00f;
							if (ImGui::DragFloat("value", &f1, 1.0f, 0.0f, 100.0f, "%.3f")){
								//resistor.setValue(f1);
								std::cout << f1 << std::endl;
							}
							//	bool DragFloat(
							//		const char* label,
							//		float* v,
							//		float v_speed = 1.0f,
							//		float v_min = 0.0f,
							//		float v_max = 0.0f,
							//		const char* format = "%.3f",
							//		float power = 1.0f
							//	)
						}
						//ImGui::End(); */
						