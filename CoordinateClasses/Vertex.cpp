#include "Vertex.hpp"
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>


std::vector<glm::vec3> Vertex::getVertexCoordinate(){
	return this->vertex;
}

void Vertex::setVertexCoordinate(std::vector<glm::vec3> vertex){
	this->vertex = vertex;
}

std::vector<glm::vec2> Vertex::getTextureCoordinate(){
	return this->texture_coordinate;
}

void Vertex::setTextureCoordinate(std::vector<glm::vec2> texture){
	this->texture_coordinate = texture;
}

std::vector<glm::vec3> Vertex::getNormal(){
	return this->normal;
}

void Vertex::setNormal(std::vector<glm::vec3> normal){
	this->normal = normal;
}

std::vector<unsigned int> Vertex::getIndices(){
	return this->indice;
}

void Vertex::setIndices(std::vector<unsigned int> indices_vector){
	this->indice = indices_vector;
}

void Vertex::addVertexCoordinate(glm::vec3 aVertex){
	this->vertex.push_back(aVertex);
}

void Vertex::addTextureCoordinate(glm::vec2 aTexture){
	this->texture_coordinate.push_back(aTexture);
}

void Vertex::addNormal(glm::vec3 aNormal){
	this->normal.push_back(aNormal);
}

void Vertex::addIndice(unsigned int value){
	this->indice.push_back(value);
}

glm::vec3 Vertex::getZero3D(){
	glm::vec3 vertex_zero_3D(0.0f, 0.0f, 0.0f);
	return vertex_zero_3D;
}

glm::vec2 Vertex::getZero2D(){
	glm::vec2 vertex_zero_2D(0.0f, 0.0f);
	return vertex_zero_2D;
}