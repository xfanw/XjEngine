#include "xjpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace Xj {
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::NONE:
			XJ_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		}

		XJ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}