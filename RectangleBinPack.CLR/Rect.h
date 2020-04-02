#pragma once

namespace RectangleBinPack
{
	public value struct Rect final
	{
	private:
		initonly int _x, _y, _width, _height;

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
	};
}
