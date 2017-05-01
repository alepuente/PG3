#include "BSPPlane.h"
#include "Mesh.h" 

#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")

#include <d3dx9.h>
#pragma comment (lib, "d3dx9.lib")

BSPPlane::BSPPlane(Renderer& rkRenderer):
	rendi(rkRenderer),
	planeMesh(new Mesh(rkRenderer)),
	plane(new D3DXPLANE)
{}

void BSPPlane::setPlane(float _a1, float _a2, float _a3, float _b1, float _b2, float _b3, float _c1, float _c2, float _c3)
{
	//Setteo el plano que va a tener
	D3DXVECTOR3 _a;
	D3DXVECTOR3 _b;
	D3DXVECTOR3 _c;
	_a.x = _a1 + planeMesh->posX();
	_a.y = _a2 + planeMesh->posY();
	_a.z = _a3 + planeMesh->posZ();

	_b.x = _b1 + planeMesh->posX();
	_b.y = _b2 + planeMesh->posY();
	_b.z = _b3 + planeMesh->posZ();

	_c.x = _c1 + planeMesh->posX();
	_c.y = _c2 + planeMesh->posY();
	_c.z = _c3 + planeMesh->posZ();

	D3DXPlaneFromPoints(plane, &_a, &_b, &_c);
}

void BSPPlane::doBSP(Entity3D& node, Camera* mainCamera) {
	int resultCont = 0;
	int totalResult = 0;
	bool positive;

	D3DXVECTOR3 cameraPos = { mainCamera->posX,mainCamera->posY,mainCamera->posZ };

	D3DXVECTOR3 aabbVertices[8] =
	{
		D3DXVECTOR3(node.BV.ActualxMin, node.BV.ActualyMin, node.BV.ActualzMin),
		D3DXVECTOR3(node.BV.ActualxMax, node.BV.ActualyMax, node.BV.ActualzMax),
		D3DXVECTOR3(node.BV.ActualxMax, node.BV.ActualyMin, node.BV.ActualzMax),
		D3DXVECTOR3(node.BV.ActualxMax, node.BV.ActualyMax, node.BV.ActualzMin),
		D3DXVECTOR3(node.BV.ActualxMax, node.BV.ActualyMin, node.BV.ActualzMin),
		D3DXVECTOR3(node.BV.ActualxMin, node.BV.ActualyMin, node.BV.ActualzMax),
		D3DXVECTOR3(node.BV.ActualxMin, node.BV.ActualyMax, node.BV.ActualzMax),
		D3DXVECTOR3(node.BV.ActualxMin, node.BV.ActualyMax, node.BV.ActualzMin)
	};

	if (D3DXPlaneDotCoord(plane, &cameraPos) > 0.0f)
	{
		positive = true;
	}
	else
	{
		positive = false;
	}


	for (int i = 0; i < 8; i++)
	{

		if (D3DXPlaneDotCoord(plane, &aabbVertices[i]) > 0.0f)
		{
			if (positive)
			{
				totalResult++;
				break;
			}
		}
		else
		{
			if (!positive)
			{
				totalResult++;
				break;
			}
		}
	}

	if (totalResult == 1)
	{
		node.canDraw = true;
	}
	else 
	{
		node.canDraw = false;
	}
}