#pragma once


//	Frank (5.1) import/export;
//	Frank(5.2) i/e -> Core.h

#include "Core.h"
namespace Xj {
	class  XJ_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// To bedefined in client
	Application* CreateApplication();
}

