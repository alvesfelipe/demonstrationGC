#ifndef _Texture_hpp
#define _Texture_hpp

#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Texture{
	private:
		GLuint id;
		std::string type;

	public:
		Texture();
		Texture(GLuint id, std::string type);
		GLuint getID();
		void setID(GLuint id);
		std::string getType();
		void setType(std::string type);
};

#endif