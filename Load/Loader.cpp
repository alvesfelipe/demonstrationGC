#include "Loader.hpp"
#include <stdio.h>


Loader::Loader(){
	this->vertex = new Vertex();
}


bool Loader::ImportSceneFromFile(const std::string pFile){
	Assimp::Importer importer;
	
	this->pScene = importer.ReadFile(pFile.c_str(),
		aiProcess_Triangulate | 
		aiProcess_GenSmoothNormals | 
		aiProcess_FlipUVs);

	if(pScene){
		return InitScene(pScene, pFile);
	}

	else{
		printf("Error to open file: %s, error: %s", pFile.c_str(), importer.GetErrorString());
	}

}

bool Loader::InitScene(const aiScene* pScene, const std::string pFile){
	for(unsigned int count = 0; count < pScene->mNumMeshes; count++){
		const aiMesh* paiMesh = pScene->mMeshes[count];
		InitMesh(count, paiMesh);
	}
	
	return true;
}

void Loader::InitMesh(unsigned int index, const aiMesh* paiMesh){
 	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	for(unsigned int count = 0; count < paiMesh->mNumVertices; count++){
		const aiVector3D* pPos = &(paiMesh->mVertices[count]);
		const aiVector3D* pNormal = &(paiMesh->mNormals[count]);
		const aiVector3D* texture_cords = paiMesh->HasTextureCoords(0) ? 
			&(paiMesh->mTextureCoords[0][count]) : &Zero3D;
		
		glm::vec3 glm_vertex(pPos->x, pPos->y, pPos->z);
		glm::vec3 glm_normals(pNormal->x, pNormal->y, pNormal->z);
		glm::vec2 glm_textureCoordinate(texture_cords->x, texture_cords->y);
		this->vertex->addVertexCoordinate(glm_vertex);
		this->vertex->addNormal(glm_normals);
		this->vertex->addTextureCoordinate(glm_textureCoordinate);
	}

	for(unsigned int count = 0; count < paiMesh->mNumFaces; count++){
		const aiFace& Face = paiMesh->mFaces[count];
		assert(Face.mNumIndices == 3);
		vertex->addIndice(Face.mIndices[0]);
		vertex->addIndice(Face.mIndices[1]);
		vertex->addIndice(Face.mIndices[2]);
	}
}


Vertex* Loader::getVertex(){
	return this->vertex;
}
