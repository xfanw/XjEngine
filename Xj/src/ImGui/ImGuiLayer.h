#pragma once

#include "Layer/Layer.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

namespace Xj {

	class XJ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

			
		void virtual OnAttach() override;
		void virtual OnDetach() override;
		// Frank (22) ++
		virtual void OnImGuiRender() override;

		void Begin();
		void End();


		// Frank (22) --
	//	 void virtual OnEvent(Event& event) override;
	//	 void virtual OnUpdate() override;
	//private:
	//	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
	//	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
	//	bool OnMouseMovedEvent(MouseMovedEvent& e);
	//	bool OnMouseScrolledEvent(MouseScrolledEvent& e);
	//	
	//	bool OnKeyPressedEvent(KeyPressedEvent& e);
	//	bool OnKeyReleasedEvent(KeyReleasedEvent& e);
	//	bool OnKeyTypedEvent(KeyTypedEvent& e);
	//	bool OnWindowResizeEvent(WindowResizeEvent& e);



	private:
		float m_Time = 0.0f;
	};

}
