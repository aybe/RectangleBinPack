#pragma once

#include <SkylineBinPack.h>

#include "SkylineHeuristic.h"
#include "Disposable.h"
#include "Rect.h"

using namespace System;

namespace RectangleBinPack
{
	public ref class Skyline sealed : public Disposable
	{
		rbp::SkylineBinPack* _instance;

	protected:
		void DisposeNative() override
		{
			delete _instance;
		}

	public:

		explicit Skyline(const int width, const int height, const bool useWasteMap)
			: _instance(new rbp::SkylineBinPack(width, height, useWasteMap))
		{
		}

		float Occupancy()
		{
			ThrowIfDisposed();

			const auto occupancy = _instance->Occupancy();

			return occupancy;
		}

		Rect Insert(const int width, const int height, const bool merge, const SkylineHeuristic heuristic)
		{
			ThrowIfDisposed();

			const auto rect = _instance->Insert(
				width,
				height,
				static_cast<rbp::SkylineBinPack::LevelChoiceHeuristic>(heuristic)
			);

			return Rect(rect.x, rect.y, rect.width, rect.height);
		}
	};
}
