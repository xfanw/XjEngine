#pragma once
// Frank (33)
#include "Renderer/RendererAPI.h"

namespace Xj {
	class OpenGLRendererAPI : public RendererAPI {
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
		//inline static API GetAPI() { return s_API; }
	};
}