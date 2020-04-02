#pragma once

#include <ShelfBinPack.h>

#include "ShelfHeuristic.h"
#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class Shelf sealed : public Disposable
	{
		rbp::ShelfBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		explicit Shelf(const int width, const int height, const bool useWasteMap)
			: _instance(new rbp::ShelfBinPack(width, height, useWasteMap))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();
			
			return occupancy;
		}

		Rect Insert(const int width, const int height, const bool merge, const ShelfHeuristic heuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				static_cast<rbp::ShelfBinPack::ShelfChoiceHeuristic>(heuristic)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
