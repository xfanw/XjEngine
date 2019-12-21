#include "xjpch.h"
#include "Buffer.h"

// Frank (30)
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
namespace Xj {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
			case RendererAPI::NONE:
				XJ_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!");
				return nullptr;
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
		}

		XJ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
			case RendererAPI::NONE:
				XJ_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!");
				return nullptr;
			case RendererAPI::OpenGL:
				return new OpenGLIndexBuffer(indices, size);
		}

		XJ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}