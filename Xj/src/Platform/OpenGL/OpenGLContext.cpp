#include "xjpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include "Core/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

		XJ_CORE_INFO("OpenGL Renderer: {0} \n\t\t {1} \n\t\t {2}", 
			glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION));
		
	}
	void OpenGLContext::SwapBuffers()
	{
		

		glfwSwapBuffers(m_WindowHandler);
	}
}