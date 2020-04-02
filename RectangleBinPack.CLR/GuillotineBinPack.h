#pragma once

#include <GuillotineBinPack.h>

#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class Guillotine sealed : public Disposable
	{
		rbp::GuillotineBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		/// <summary>
		/// Specifies the different choice heuristics that can be used when deciding
		/// which of the free sub rectangles to place the to-be-packed rectangle into.
		/// </summary>
		enum class FreeRectChoiceHeuristic
		{
			RectBestAreaFit,
			RectBestShortSideFit,
			RectBestLongSideFit,
			RectWorstAreaFit,
			RectWorstShortSideFit,
			RectWorstLongSideFit
		};

		/// <summary>
		/// Specifies the different choice heuristics that can be used when the packer needs to decide
		/// whether to subdivide the remaining free space in horizontal or vertical direction.
		/// </summary>
		enum class GuillotineSplitHeuristic
		{
			SplitShorterLeftoverAxis,
			SplitLongerLeftoverAxis,
			SplitMinimizeArea,
			SplitMaximizeArea,
			SplitShorterAxis,
			SplitLongerAxis
		};

		explicit Guillotine(const int width, const int height)
			: _instance(new rbp::GuillotineBinPack(width, height))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();

			return occupancy;
		}

		Rect Insert(const int width, const int height, const bool merge,
		            const FreeRectChoiceHeuristic choiceHeuristic, const GuillotineSplitHeuristic splitHeuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				merge,
				static_cast<rbp::GuillotineBinPack::FreeRectChoiceHeuristic>(choiceHeuristic),
				static_cast<rbp::GuillotineBinPack::GuillotineSplitHeuristic>(splitHeuristic)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
