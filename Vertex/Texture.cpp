#include "Texture.hpp"


Texture::Texture(){}

Texture::Texture(GLuint id, std::string type){
	this->id = id;
	this->type = type;
}

GLuint Texture::getID(){
	return this->id;
}

void Texture::setID(GLuint id){
	this->id = id;
}

std::string Texture::getType(){
	return this->type;
}

void Texture::setType(std::string type){
	this->type = type;
}