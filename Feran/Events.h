#pragma once

#include "Utilities.h"

namespace fr
{
	class FERAN_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class FERAN_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class FERAN_API WindowClosed
	{
		
	};
}