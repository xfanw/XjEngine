#include "xjpch.h"
#include "Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGlRendererAPI.h"
// Frank (33)
namespace Xj {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;


}