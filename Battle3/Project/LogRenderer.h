#pragma once
#include <iostream>
#include "Renderer.h"

/*
 * Outputs filename "drawn" to console
 */
class LogRenderer : public Renderer
{
public:
	void Render(const char* filename)
	{
		std::cout << "Drawing image " << filename << std::endl;
	}
};