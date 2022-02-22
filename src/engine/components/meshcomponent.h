#pragma once

#include <GL/glew.h>

#include "../component.h"
#include "../mesh.h"

class MeshComponent : public Component {
	public:
		MeshComponent(Mesh mesh);
		
		void execute() override;

		Mesh getMesh();
		void setMesh(Mesh mesh);
	private:
		Mesh _mesh;
};
