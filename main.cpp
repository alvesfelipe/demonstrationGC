#include "Load/Loader.hpp"
#include "CoordinateClasses/Vertex.hpp"
#include "CoordinateClasses/Texture.hpp"
#include "Common/Definitions.hpp"
#include <vector>

std::vector<glm::vec3> vertices;
Vertex *vertex;
void displayedGL(void);
Definitions *definitions;
float newAngle = 1.0;

int main(int argc, char **argv){

	Loader loader;
	std::string object_scene;
	definitions = new Definitions();
	object_scene = "/home/claudio/Documents/Workspaces/Cplusplus/FinalCG/SceneObjects/terrainC.obj";
	loader.ImportSceneFromFile(object_scene);
	vertex = loader.getVertex();
	vertices = vertex->getVertexCoordinate();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(definitions->getWidthScreen(), definitions->getHeightScreen());
	glutInitWindowPosition(255,100);
	glutCreateWindow("My Pipeline");
	
	glutDisplayFunc(displayedGL);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();


	return 0;
}


void displayedGL(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glViewport(0, 0, definitions->getWidthScreen(), definitions->getHeightScreen());
 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 55.0f, // angulo de abertura da camera
					(float)definitions->getWidthScreen()/definitions->getWidthScreen(), // aspecto da imagem
                      1.0f,  // near plane
                      50.0f); // far plane

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
        gluLookAt(0.0f, 5.0f, -15.0f,       // camera position
                    0.0f, 0.0f, 0.0f,       // looking at point
                	0.0f, 1.0f, 0.0f);      // up vector
     
     //Rotate object
     //glRotatef(newAngle+=-0.9, 0.0,0.05,0.0);
		
    glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(newAngle+=0.01, 0.0,0.0,0.0);
  
  //Draw the object Scene
	glBegin(GL_POINTS);
		for(unsigned int count = 0; count < vertices.size(); count+=3){
			glVertex3f(vertices[count].x, vertices[count].y, vertices[count].z);
			glVertex3f(vertices[count+1].x, vertices[count+1].y, vertices[count+1].z);
			glVertex3f(vertices[count+2].x, vertices[count+2].y, vertices[count+2].z);
		}	
	glEnd();
	glutSwapBuffers();
	glutPostRedisplay();

}