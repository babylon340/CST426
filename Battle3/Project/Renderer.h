#pragma once

/*
 * Basic renderer interface for use with service locator.
 */
class Renderer
{
public:
	virtual ~Renderer() {}

	virtual void Render(const char* filename) = 0;
};