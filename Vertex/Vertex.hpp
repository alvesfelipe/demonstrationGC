#ifndef _Vertex_hpp
#define _Vertex_hpp

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

class Vertex{
	private:
		std::vector<glm::vec3> vertex;
		std::vector<glm::vec2> texture_coordinate;
		std::vector<glm::vec3> normal;
		std::vector<unsigned int> indice;

	public:
		std::vector<glm::vec3> getVertexCoordinate();
		void setVertexCoordinate(std::vector<glm::vec3> vertex);
		std::vector<glm::vec2> getTextureCoordinate();
		void setTextureCoordinate(std::vector<glm::vec2> texture);
		std::vector<glm::vec3> getNormal();
		void setNormal(std::vector<glm::vec3> normal);
		std::vector<unsigned int> getIndices();
		void setIndices(std::vector<unsigned int> indices_vector);
		void addVertexCoordinate(glm::vec3 aVertex);
		void addTextureCoordinate(glm::vec2 aTexture);
		void addNormal(glm::vec3 aNormal);
		void addIndice(unsigned int value);
		glm::vec3 getZero3D();
		glm::vec2 getZero2D();
};
#endif