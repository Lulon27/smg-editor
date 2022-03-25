#pragma once

#include <cstdint>
#include <string>

namespace RedStar
{
	using KeyCode = int32_t;
	using MouseButtonCode = int32_t;

	struct KeyData
	{
		KeyData(KeyCode code, const std::string& name)
			: code(code), name(name) {}

		const KeyCode code;
		const std::string name;

		friend bool operator==(const KeyData& l, const KeyData& r);
		friend bool operator!=(const KeyData& l, const KeyData& r);
	};

	struct MouseButtonData
	{
		MouseButtonData(MouseButtonCode code, const std::string& name)
			: code(code), name(name) {}

		const MouseButtonCode code;
		const std::string name;

		friend bool operator==(const MouseButtonData& l, const MouseButtonData& r);
		friend bool operator!=(const MouseButtonData& l, const MouseButtonData& r);
	};

	/*
	 *	These key codes were taken from glfw3.h
	 *	and thus match the GLFW key codes.
	 */

	namespace Keys
	{
		/* The unknown key */
		const KeyData Unknown		(-1, "Unknown");

		/* Printable keys */
		const KeyData Space			(32, "Space");
		const KeyData Apostrophe	(39, "'");  /* ' */
		const KeyData Comma			(44, ",");  /* , */
		const KeyData Minus			(45, "-");  /* - */
		const KeyData Period		(46, ".");  /* . */
		const KeyData Slash			(47, "/");  /* / */
		const KeyData Zero			(48, "0");
		const KeyData One			(49, "1");
		const KeyData Two			(50, "2");
		const KeyData Three			(51, "3");
		const KeyData Four			(52, "4");
		const KeyData Five			(53, "5");
		const KeyData Six			(54, "6");
		const KeyData Seven			(55, "7");
		const KeyData Eight			(56, "8");
		const KeyData Nine			(57, "9");
		const KeyData Semicolon		(59, ";");  /* ; */
		const KeyData Equal			(61, "=");  /* = */
		const KeyData A				(65, "A");
		const KeyData B				(66, "B");
		const KeyData C				(67, "C");
		const KeyData D				(68, "D");
		const KeyData E				(69, "E");
		const KeyData F				(70, "F");
		const KeyData G				(71, "G");
		const KeyData H				(72, "H");
		const KeyData I				(73, "I");
		const KeyData J				(74, "J");
		const KeyData K				(75, "K");
		const KeyData L				(76, "L");
		const KeyData M				(77, "M");
		const KeyData N				(78, "N");
		const KeyData O				(79, "O");
		const KeyData P				(80, "P");
		const KeyData Q				(81, "Q");
		const KeyData R				(82, "R");
		const KeyData S				(83, "S");
		const KeyData T				(84, "T");
		const KeyData U				(85, "U");
		const KeyData V				(86, "V");
		const KeyData W				(87, "W");
		const KeyData X				(88, "X");
		const KeyData Y				(89, "Y");
		const KeyData Z				(90, "Z");
		const KeyData LeftBracket	(91, "[");  /* [ */
		const KeyData Backslash		(92, "\\");  /* \ */
		const KeyData RightBracket	(93, "]");  /* ] */
		const KeyData GraveAccent	(96, "`");  /* ` */
		const KeyData World1		(161, "World 1"); /* non-US #1 */
		const KeyData World2		(162, "World 2"); /* non-US #2 */

		/* Function keys */
		const KeyData Escape		(256, "ESC");
		const KeyData Enter			(257, "Enter");
		const KeyData Tab			(258, "Tab");
		const KeyData Backspace		(259, "Backspace");
		const KeyData Insert		(260, "Insert");
		const KeyData Delete		(261, "Delete");
		const KeyData Right			(262, "Right");
		const KeyData Left			(263, "Left");
		const KeyData Down			(264, "Down");
		const KeyData Up			(265, "Up");
		const KeyData PageUp		(266, "PageUp");
		const KeyData PageDown		(267, "PageDown");
		const KeyData Home			(268, "Home");
		const KeyData End			(269, "End");
		const KeyData CapsLock		(280, "CapsLock");
		const KeyData ScrollLock	(281, "ScrollLock");
		const KeyData NumLock		(282, "NumLock");
		const KeyData PrintScreen	(283, "PrintScreen");
		const KeyData Pause			(284, "Pause");
		const KeyData F1			(290, "F1");
		const KeyData F2			(291, "F2");
		const KeyData F3			(292, "F3");
		const KeyData F4			(293, "F4");
		const KeyData F5			(294, "F5");
		const KeyData F6			(295, "F6");
		const KeyData F7			(296, "F7");
		const KeyData F8			(297, "F8");
		const KeyData F9			(298, "F9");
		const KeyData F10			(299, "F0");
		const KeyData F11			(300, "F11");
		const KeyData F12			(301, "F12");
		const KeyData F13			(302, "F13");
		const KeyData F14			(303, "F14");
		const KeyData F15			(304, "F15");
		const KeyData F16			(305, "F16");
		const KeyData F17			(306, "F17");
		const KeyData F18			(307, "F18");
		const KeyData F19			(308, "F19");
		const KeyData F20			(309, "F20");
		const KeyData F21			(310, "F21");
		const KeyData F22			(311, "F22");
		const KeyData F23			(312, "F23");
		const KeyData F24			(313, "F24");
		const KeyData F25			(314, "F25");
		const KeyData Kp0			(320, "Numpad 0");
		const KeyData Kp1			(321, "Numpad 1");
		const KeyData Kp2			(322, "Numpad 2");
		const KeyData Kp3			(323, "Numpad 3");
		const KeyData Kp4			(324, "Numpad 4");
		const KeyData Kp5			(325, "Numpad 5");
		const KeyData Kp6			(326, "Numpad 6");
		const KeyData Kp7			(327, "Numpad 7");
		const KeyData Kp8			(328, "Numpad 8");
		const KeyData Kp9			(329, "Numpad 9");
		const KeyData KpDecimal		(330, "Numpad ,");
		const KeyData KpDivide		(331, "Numpad /");
		const KeyData KpMultiply	(332, "Numpad *");
		const KeyData KpSubtract	(333, "Numpad -");
		const KeyData KpAdd			(334, "Numpad +");
		const KeyData KpEnter		(335, "Numpad Enter");
		const KeyData KpEqual		(336, "Numpad =");
		const KeyData LeftShift		(340, "Left Shift");
		const KeyData LeftControl	(341, "Left Control");
		const KeyData LeftAlt		(342, "Left Alt");
		const KeyData LeftSuper		(343, "Left Super");
		const KeyData RightShift	(344, "Right Shift");
		const KeyData RightControl	(345, "Right Control");
		const KeyData RightAlt		(346, "Right Alt");
		const KeyData RightSuper	(347, "Right Super");
		const KeyData Menu			(348, "Menu");
	}

	namespace MouseButtons
	{
		const MouseButtonData Button1	(0, "Button 1");
		const MouseButtonData Button2	(1, "Button 2");
		const MouseButtonData Button3	(2, "Button 3");
		const MouseButtonData Button4	(3, "Button 4");
		const MouseButtonData Button5	(4, "Button 5");
		const MouseButtonData Button6	(5, "Button 6");
		const MouseButtonData Button7	(6, "Button 7");
		const MouseButtonData Button8	(7, "Button 8");

		static const MouseButtonData* Left		= &MouseButtons::Button1;
		static const MouseButtonData* Right		= &MouseButtons::Button2;
		static const MouseButtonData* Middle	= &MouseButtons::Button3;

	};

	namespace Input
	{
		/*
		 *	These codes are from glfw3.h
		 */

		namespace Mods
		{
			const int Shift = 0x0001;
			const int Control = 0x0002;
			const int Alt = 0x0004;
			const int Super = 0x0008;
			const int CapsLock = 0x0010;
			const int NumLock = 0x0020;

			class ModsField
			{
			public:
				ModsField(uint8_t mods) : m_mods(mods) {};

			public:
				uint8_t getMods() const
				{
					return m_mods;
				}

				bool getShift() const
				{
					return m_mods & Input::Mods::Shift;
				}

				bool getControl() const
				{
					return m_mods & Input::Mods::Control;
				}

				bool getAlt() const
				{
					return m_mods & Input::Mods::Alt;
				}

				bool getSuper() const
				{
					return m_mods & Input::Mods::Super;
				}

				bool getCapsLock() const
				{
					return m_mods & Input::Mods::CapsLock;
				}

				bool getNumLock() const
				{
					return m_mods & Input::Mods::NumLock;
				}

			public:
				const uint8_t m_mods;
			};
		}

		const KeyData* keyFromGLFW(int glfwKey);
		const MouseButtonData* mouseButtonFromGLFW(int glfwButton);
		const Mods::ModsField modsFromGLFW(int glfwMods);
	}
}
