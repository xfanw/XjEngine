#pragma once

#include "Core/Input.h"

namespace Xj {

	class WindowsInput : public Input {
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;



		// Inherited via Input
		virtual bool IsMouseButtonPressedImpl(int button) override;

		virtual std::pair<float, float> GetMousePositionImpl() override;

		virtual float GetMouseXImpl() override;

		virtual float GetMouseYImpl() override;

	};
}