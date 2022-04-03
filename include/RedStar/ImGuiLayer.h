#pragma once

#include "RedStar/Layer.h"

namespace RedStar
{
	class ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();

		virtual void onAttach() override;
		virtual void onUpdate() override;

	protected:

		virtual bool onKeyPressed(KeyPressedEvent& event) override;
		virtual bool onKeyReleased(KeyReleasedEvent& event) override;
		virtual bool onKeyTyped(KeyTypedEvent& event) override;
		virtual bool onCharTyped(CharTypedEvent& event) override;
		virtual bool onMouseButtonPressed(MouseButtonPressedEvent& event) override;
		virtual bool onMouseButtonReleased(MouseButtonReleasedEvent& event) override;
		virtual bool onMouseScrolled(MouseScrolledEvent& event) override;

		virtual const char* getDebugName() const override
		{
			return "ImGuiLayer";
		}
	};
}
