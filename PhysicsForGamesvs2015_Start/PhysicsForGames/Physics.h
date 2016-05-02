#ifndef SOUND_PROGRAMMING_H_
#define SOUND_PROGRAMMING_H_

#include "Application.h"
#include "Camera.h"
#include "Render.h"

#include <PxPhysicsAPI.h>
#include <PxScene.h>
#include <pvd/PxVisualDebugger.h>

using namespace physx;

class myAllocator : public PxAllocatorCallback
{
public:
	virtual ~myAllocator() {}
	virtual void* allocate(size_t size, const char* typeName, const char* filename, int line)
	{
		void* pointer = _aligned_malloc(size, 16);
		return pointer;
	}
	virtual void deallocate(void* ptr)
	{
		_aligned_free(ptr);
	}
};


class Physics : public Application
{
public:
	virtual bool startup();
	virtual void shutdown();
    virtual bool update();
    virtual void draw();

	void SetUpPhysX();
	void SetupVisualDebugger();
	void UpdatePhysX(float deltaTime);

	void SetupTutorial1();

	void renderGizmos(PxScene* physics_scene);

    Renderer* m_renderer;
    FlyCamera m_camera;
    float m_delta_time;

private:
	PxFoundation* m_PhysicsFoundation;
	PxPhysics* m_Physics;
	PxScene* m_PhysicsScene;
	PxDefaultErrorCallback mDefaultErrorCallback;
	PxDefaultAllocator mDefaultAllocatorCallback;
	PxSimulationFilterShader mDefaultFilterShader = PxDefaultSimulationFilterShader;
	PxMaterial* m_PhysicsMaterial;
	PxMaterial* m_BoxMaterial;
	PxCooking* m_PhysicsCooker;

	float counter = 0;
};



#endif //CAM_PROJ_H_
