#include "Camera.h"

Camera::Camera()
{
	m_projection = glm::mat4(1.0f);
	m_view = glm::mat4(1.0f);

	float aspectRatio = 1024.0f / 768.0f;
	m_projection = glm::ortho(-aspectRatio * 5, aspectRatio * 5, 5.0f, -5.0f, 1.0f, -1.0f);
	CalculateViewMatrix();
}

void Camera::CalculateViewMatrix() 
{
	glm::mat4 transform =
		glm::translate(glm::mat4(1.0f), m_position)
		* glm::toMat4(glm::quat(m_rotation));

	m_view = glm::inverse(transform);
}

glm::mat4 Camera::GetViewProjectionMatrix() 
{
	return m_projection * m_view;
}

void Camera::SetProjection(float width, float height)
{
	float aspectRatio = width / height;
	m_projection = glm::ortho(-aspectRatio * 5, aspectRatio * 5, -5.0f, 5.0f, -1.0f, 1.0f);
}

void Camera::SetPosition(glm::vec3 p) 
{
	m_position = p;
	CalculateViewMatrix();
}

void Camera::SetRotation(glm::vec3 r) 
{
	m_rotation = r;
	CalculateViewMatrix();
}

void Camera::Move(glm::vec3 p) 
{
	glm::vec4 pos = glm::vec4(p, 1);
	m_position = m_position * glm::vec3(glm::toMat4(glm::quat(m_rotation))* pos);
	CalculateViewMatrix();
}

void Camera::Rotate(glm::vec3 r) 
{
	m_rotation += r;
	CalculateViewMatrix();
}


