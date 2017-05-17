#ifndef NODE_H
#define NODE_H

#include "Entity3D.h"
#include <vector>


class Node : public Entity3D{
public:
	DLLexport Node();
	DLLexport void AddChild(Entity3D* child);
	DLLexport void draw(Renderer& rkRenderer, CollisionResult eParentResult, Frustum& rkFrustum);
	DLLexport void draw(Renderer& rkRenderer, CollisionResult eParentResult, Frustum& rkFrustum, Text& _text);
	DLLexport void updateWordTransformation();
	DLLexport void removeChild(Entity3D* pkChild);
	DLLexport void updateBV();
	DLLexport void getChild(std::string name, Entity3D& child);
	DLLexport void checkBSP(BSPPlane* node, Camera* mainCamera);
	DLLexport void Node::setDraw(Entity3D& node, bool state);



//private:
	std::vector<Entity3D*> _childs;
	bool drawBV = true;
};


#endif