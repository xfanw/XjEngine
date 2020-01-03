#pragma once

#include "Renderer/RendererAPI.h"
#include "Renderer/RenderCommand.h"
namespace Xj {
// Frank (33)--
	//enum class RendererAPI {
	//	NONE = 0,
	//	OpenGL = 1
	//};

	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();
		
		static void Submit(const std::shared_ptr<VertexArray>& vertexeArray);
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
// Frank (33)--
	//private:
	//	static RendererAPI::API s_RendererAPI;
	};

}
