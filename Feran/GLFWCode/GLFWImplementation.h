#pragma once

#include "GLFW/glfw3.h"
#include "../WindowImplementation.h"

namespace fr
{
	class GLFWImplementation : public WindowImplementation
	{
	public:
		GLFWImplementation();
		virtual void Create(const std::string& name, int width, int height) override;
		virtual int GetHeight()const override;
		virtual int GetWidth()const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

	private:
		GLFWwindow* mWindow;
	};
}