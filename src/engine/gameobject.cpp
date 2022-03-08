#include "gameobject.h"

GameObject::GameObject(glm::vec3 position)
{
	_position = position;
	_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	_scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

void GameObject::setMesh(Mesh *mesh)
{
	_mesh = mesh;
}

Mesh *GameObject::getMesh()
{
	return _mesh;
}

void GameObject::setPosition(glm::vec3 position)
{
	_position = position;
}

void GameObject::setRotation(glm::vec3 rotation)
{
	_rotation = rotation;
}

void GameObject::setScale(glm::vec3 scale)
{
	_scale = scale;
}

glm::vec3 GameObject::getPosition()
{
	return _position;
}

glm::vec3 GameObject::getRotation()
{
	return _rotation;
}

glm::vec3 GameObject::getScale()
{
	return _scale;
}

void GameObject::render()
{

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->getVertexBuffer());
	glVertexAttribPointer(
		0,		  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,		  // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0,		  // stride
		(void *)0 // array buffer offset
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->getUvBuffer());
	glVertexAttribPointer(
		1,		  // attribute. No particular reason for 1, but must match the layout in the shader.
		2,		  // size : U+V => 2
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0,		  // stride
		(void *)0 // array buffer offset
	);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->getNormalBuffer());
	glVertexAttribPointer(
		2,		  // attribute
		3,		  // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0,		  // stride
		(void *)0 // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, _mesh->getVertexCount()); // 3 indices starting at 0 -> 1 triangle

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}
