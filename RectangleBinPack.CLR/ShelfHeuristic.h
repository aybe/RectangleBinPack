#pragma once

namespace RectangleBinPack
{
	/// <summary>
	/// Defines different heuristic rules that can be used in the packing process.
	/// </summary>
	public enum class ShelfHeuristic
	{
		NextFit,
		FirstFit,
		BestAreaFit,
		WorstAreaFit,
		BestHeightFit,
		BestWidthFit,
		WorstWidthFit,
	};
}
