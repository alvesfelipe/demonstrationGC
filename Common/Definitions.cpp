#include "Definitions.hpp"

Definitions::Definitions(){
	this->screen_width = 800;
	this->screen_height = 600;
}

Definitions::Definitions(unsigned int width, unsigned int height){
	this->screen_width = width;
	this->screen_height = height;
}
unsigned int Definitions::getHeightScreen(){
	return this->screen_height;
}

void Definitions::setHeightScreen(unsigned int height){
	this->screen_height = height;
}

unsigned int Definitions::getWidthScreen(){
	return this->screen_width;
}

void Definitions::setWidthScreen(unsigned int width){
	this->screen_width = width;
}