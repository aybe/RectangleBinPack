#pragma once

#include <GuillotineBinPack.h>

#include "GuillotineHeuristic.h"
#include "GuillotineSplit.h"
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

		Rect Insert(const int width, const int height, const bool merge, const GuillotineHeuristic heuristic, const GuillotineSplit split)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				merge,
				static_cast<rbp::GuillotineBinPack::FreeRectChoiceHeuristic>(heuristic),
				static_cast<rbp::GuillotineBinPack::GuillotineSplitHeuristic>(split)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
