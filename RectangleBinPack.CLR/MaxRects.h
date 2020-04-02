#pragma once

#include <MaxRectsBinPack.h>

#include "MaxRectsHeuristic.h"
#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class MaxRects sealed : public Disposable
	{
		rbp::MaxRectsBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		explicit MaxRects(const int width, const int height, const bool allowFlip)
			: _instance(new rbp::MaxRectsBinPack(width, height, allowFlip))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();
			
			return	occupancy;
		}

		Rect Insert(const int width, const int height, const MaxRectsHeuristic heuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				static_cast<rbp::MaxRectsBinPack::FreeRectChoiceHeuristic>(heuristic)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
