#pragma once
#include "Renderer/GraphicContext.h"

struct GLFWwindow;

namespace Xj {
	class OpenGLContext : public GraphicContext {
	public:
		OpenGLContext(GLFWwindow* windowHandler);
		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandler;
	};
}