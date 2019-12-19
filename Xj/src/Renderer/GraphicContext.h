#pragma once


namespace Xj {
	class GraphicContext {
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	private:

	};
}