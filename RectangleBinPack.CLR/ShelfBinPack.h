#pragma once

#include <ShelfBinPack.h>

#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class ShelfBinPack sealed : public Disposable
	{
		rbp::ShelfBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		/// <summary>
		/// Defines different heuristic rules that can be used in the packing process.
		/// </summary>
		enum class ShelfChoiceHeuristic
		{
			ShelfNextFit,
			ShelfFirstFit,
			ShelfBestAreaFit,
			ShelfWorstAreaFit,
			ShelfBestHeightFit,
			ShelfBestWidthFit,
			ShelfWorstWidthFit,
		};

		explicit ShelfBinPack(const int width, const int height, const bool useWasteMap)
			: _instance(new rbp::ShelfBinPack(width, height, useWasteMap))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();
			
			return occupancy;
		}

		Rect^ Insert(const int width, const int height, const bool merge, const ShelfChoiceHeuristic choiceHeuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				static_cast<rbp::ShelfBinPack::ShelfChoiceHeuristic>(choiceHeuristic)
			);

			return gcnew Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
