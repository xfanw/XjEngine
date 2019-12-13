#pragma once
// Frank (15)
#include "Layer/Layer.h"
#include "Platform/OpenGL/ImGuiOpenGLRender.h"


namespace Xj {

	class XJ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnEvent(Event& event) override;
		void OnAttach() override;
		void OnDetach() override;

	private:
		float m_Time = 0.0f;
	};

}
