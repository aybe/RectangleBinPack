#pragma once

namespace RectangleBinPack
{
	/// <summary>
	/// Specifies the different choice heuristics that can be used when deciding
	/// which of the free sub rectangles to place the to-be-packed rectangle into.
	/// </summary>
	public enum class GuillotineHeuristic
	{
		BestAreaFit,
		BestShortSideFit,
		BestLongSideFit,
		WorstAreaFit,
		WorstShortSideFit,
		WorstLongSideFit
	};
}
