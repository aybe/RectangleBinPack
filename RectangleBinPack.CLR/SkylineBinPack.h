#pragma once

#include <SkylineBinPack.h>

#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class SkylineBinPack sealed : public Disposable
	{
		rbp::SkylineBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		/// <summary>
		/// Defines the different heuristic rules that can be used to decide how to make the rectangle placements.
		/// </summary>
		enum class LevelChoiceHeuristic
		{
			LevelBottomLeft,
			LevelMinWasteFit
		};

		explicit SkylineBinPack(const int width, const int height, const bool useWasteMap)
			: _instance(new rbp::SkylineBinPack(width, height, useWasteMap))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();
			
			return occupancy;
		}

		Rect Insert(const int width, const int height, const bool merge, const LevelChoiceHeuristic choiceHeuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				static_cast<rbp::SkylineBinPack::LevelChoiceHeuristic>(choiceHeuristic)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
