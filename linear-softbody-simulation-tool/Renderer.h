#pragma once

#include "Shader.h"

class Renderer
{
public:
	Renderer(Shader&, std::vector<float>& vertices);
	~Renderer();

	void Draw(glm::vec3, glm::vec3, float, glm::vec3);

private:
	Shader m_shader;
	uint32_t m_vao;
	std::vector<float> vertex_data{};
	
	void InitRenderData();
};