/**
 * @author     { Claudio Djohnnatha }
 */

#ifndef _Loader_hpp
#define _Loader_hpp


#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>
#include <assimp/cimport.h>   
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include "../CoordinateClasses/Vertex.hpp"
class Loader{
	private:
		const aiScene* pScene;
		Vertex *vertex;

  public:
  	Loader();
		/**
		 * @brief      { Will geting the file place and call the functions InitScene and Init mesh }
		 *
		 * @param[in]  pFile  { pointer which contain the file (scene place) }
		 *
		 * @return     { true if everything gonna be okay }
		 */
		bool ImportSceneFromFile(const std::string pFile);

		/**
		 * @brief      { Separe each mesh and call the InitMesh }
		 *
		 * @param[in]  pScene  { aiScene is a function to assimp here load the file
		 *                     }
		 * @param[in]  pFile   { the file place }
		 *
		 * @return     { true if everything gonna be okay }
		 */
		bool InitScene(const aiScene* pScene, const std::string pFile);
		/**
		 * @brief      { Will separete the vertex, normals, texture coordinate and
		 *             the faces indices }
		 *
		 * @param[in]  <unnamed>  { index of mesh loaded in InitScene }
		 * @param[in]  paiMesh    { Array whitch contain the meshes }
		 */
		void InitMesh(unsigned int index, const aiMesh* paiMesh);
		Vertex* getVertex();
};


#endif