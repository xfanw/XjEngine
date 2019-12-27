#pragma once
#include "Renderer/Buffer.h"

// Frank (30)
namespace Xj {

	class OpenGLVertexBuffer : public VertexBuffer {
	public :
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();
		// Inherited via VertexBuffer
		virtual void Bind() const override;
		virtual void Unbind() const override;
		// Frank (31)
		virtual void SetLayout(const BufferLayout& layout) override;
		virtual const BufferLayout& GetLayout() override;
		virtual const BufferLayout& GetLayout() const ;

	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;

	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();
		// Inherited via IndexBuffer
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual uint32_t GetCount() const override;


	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

		
	};

}