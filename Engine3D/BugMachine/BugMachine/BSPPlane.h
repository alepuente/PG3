#ifndef BSPPLANE_H
#define BSPPLANE_H

#include "Camera.h"
#include "Renderer.h"

class Mesh;
class Entity3D;

#define DLLexport __declspec(dllexport)

class BSPPlane {
public:
	DLLexport BSPPlane(Renderer& rkRenderer);
	DLLexport void setPlane(float _a1, float _a2, float _a3, float _b1, float _b2, float _b3, float _c1, float _c2, float _c3);
	DLLexport void doBSP(Entity3D& node, Camera* mainCamera);
	Mesh* planeMesh;
	Plane plane;

private:
	Renderer rendi;


};

#endif
