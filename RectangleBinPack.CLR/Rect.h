#pragma once

#define nameof(x) (#x)

using namespace System;
using namespace Diagnostics;

namespace RectangleBinPack
{
	public value struct Rect final
	{
	private:
		[DebuggerBrowsableAttribute(DebuggerBrowsableState::Never)]
		initonly int _x;

		[DebuggerBrowsableAttribute(DebuggerBrowsableState::Never)]
		initonly int _y;

		[DebuggerBrowsableAttribute(DebuggerBrowsableState::Never)]
		initonly int _width;

		[DebuggerBrowsableAttribute(DebuggerBrowsableState::Never)]
		initonly int _height;

	public:
		Rect(const int x, const int y, const int width, const int height)
			: _x(x), _y(y), _width(width), _height(height)
		{
		}

		property int X
		{
			int get() { return _x; }
		}

		property int Y
		{
			int get() { return _y; }
		}

		property int Width
		{
			int get() { return _width; }
		}

		property int Height
		{
			int get() { return _height; }
		}

		String^ ToString() override
		{
			return String::Format("{0}: {1}, {2}: {3}, {4}: {5}, {6}: {7}",
			                      nameof(X), X, nameof(Y), Y, nameof(Width), Width, nameof(Height), Height);
		}
	};
}
