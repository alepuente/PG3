#ifndef ENTITY3D_H
#define ENTITY3D_H

#include "pg1_timer.h"
#include "Frustum.h"
#include "Text.h"
#include "BSPPlane.h"

class Node;
class Mesh;
class Camera;
class BSPPlane;

#define DLLexport __declspec(dllexport)

class Entity3D{
public:
	DLLexport Entity3D();
	DLLexport virtual ~Entity3D();
	DLLexport void setPos(float fPosX, float fPosY, float fPosZ);
	DLLexport void setRotation(float fRotation);
	DLLexport void setRotation(float fRotationX, float fRotationY, float fRotationZ);
	DLLexport void setScale(float scaleX, float scaleY, float scaleZ);

	DLLexport float posX();
	DLLexport float posY();
	DLLexport float posZ();
	DLLexport float rotationZ();
	DLLexport float rotationY();
	DLLexport float rotationX();
	DLLexport float scaleX();
	DLLexport float scaleY();
	DLLexport float scaleZ();

	DLLexport virtual void draw(Renderer& rkRenderer, CollisionResult eParentResult, Frustum& rkFrustum) = 0;
	DLLexport virtual void draw(Renderer& rkRenderer, CollisionResult eParentResult, Frustum& rkFrustum, Text& _text) = 0;

	DLLexport virtual void getChild(std::string name, Entity3D& child) = 0;
	DLLexport virtual void checkBSP(BSPPlane* node, Camera* mainCamera) = 0;

	DLLexport void setParent(Node& parent);
	DLLexport virtual void updateWordTransformation();

	DLLexport void setName(std::string name);
	DLLexport std::string getName();

	DLLexport void setPolCount(int polCount);
	DLLexport int getPolCount();

	Node* _parent;
	AABB BV;

	DLLexport const AABB& getAABB() const;
	DLLexport virtual void updateBV() = 0;

	bool canDraw = true;


private:

	float _posX, _posY, _posZ;
	float _rotationX, _rotationY, _rotationZ;
	float _scaleX, _scaleY, _scaleZ;
	bool _flipX;
	void updateLocalTransformation();
	
	std::string _name;
	int _polCount;

protected:	
	float getParentScaleX();
	Matrix _WordtransformationMatrix;
	Matrix _LocaltransformationMatrix;
};
#endif