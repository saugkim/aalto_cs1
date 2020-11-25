
#include <iostream>
#include <string>
#include <vector>

#include "imgui-SFML.h"
#include "imgui.h"

// template<typename T, typename A>
// void some_func( std::vector<T,A> const& vec ) {}

template<class T>
void ShowWindowRightClickEvent(bool &showWindow, std::vector<T> &vector, int &index) {
		
	ImGui::SetNextWindowPos(ImVec2(450, 10));
	if (showWindow) {
		
		if(!ImGui::Begin("Control Window", &showWindow)) {
			ImGui::End();
		} 
		else {
			float fvalue;
			//fvalue = vector[index].getValue();
			
			if (ImGui::DragFloat("value", &fvalue, 5.0f, 0.0f, 100.0f, "%.2f")){
				//vector.setValue(fvalue);
				std::cout << fvalue << std::endl;
			}
			
			if (ImGui::Button("Remove")) {
				//remove this-> vector[index]
				//vector.erase(vector.begin() + index);
				std::cout << "removed" <<std::endl;
				showWindow=false;
			}
			
			if (ImGui::Button("Close")) {
				showWindow=false;
			}
			
            ImGui::End();
		}
	} 
	else {
		//reset value
		index = -1;
	}
}