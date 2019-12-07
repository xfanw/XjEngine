#pragma once


#include "Core/Core.h"
#include "Events/ApplicationEvent.h"
#include "Core/Log.h"
namespace Xj {
	class  XJ_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

