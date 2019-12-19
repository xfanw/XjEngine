#include "xjpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include "Core/Log.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
// Frank (27)
namespace Xj {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandler)
		:m_WindowHandler(windowHandler)
	{		
		XJ_CORE_ASSERT(windowHandler, "Windows Handler is null!")
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandler);

		// GLAD
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		XJ_CORE_ASSERT(status, "Failed to initialize Glad!");
		(void)status;
	}
	void OpenGLContext::SwapBuffers()
	{
		

		glfwSwapBuffers(m_WindowHandler);
	}
}