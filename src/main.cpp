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

    string mainMenuAction = "";
    char* text = (char*)"test text";
    Menu mainMenu = Menu(text);   
    std::vector<ResistorGraphicsItem> ResistorGroup;
    
    //create grid
    Grid grid = Grid(width, height);
    bool mainMenuActive = false;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

	    switch (event.type) {
	      case sf::Event::Closed:
			window.close();
			break;
	      case sf::Event::MouseButtonPressed:
		 for (auto& resistor : ResistorGroup) {
		   if (event.mouseButton.button == sf::Mouse::Left) {
                     if (resistor.GetRectShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
		       resistor.SetGrabbed(true);
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

	ImVec2(0, 0);
	mainMenu.Show(mainMenuAction, mainMenuActive);
	
	if (mainMenuAction == RESISTOR) {
	  ResistorGraphicsItem r = ResistorGraphicsItem();
          ResistorGroup.push_back(r);
	}

	if (mainMenuAction == WIRE) {
          WireGraphicsItem w = WireGraphicsItem(50, 100, 150);
	  //window.draw(w.GetWire(), 2, sf::Lines);
	}

	mainMenuAction = "";

        window.clear(backgroundColor);

	for (auto& g : grid.GetGrid()) {
	  window.draw(g);
	}

    for (auto& resistor : ResistorGroup) { 
	  window.draw(resistor.GetRectShape());
    }
	
//	window.draw(vertex);
 
	ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
