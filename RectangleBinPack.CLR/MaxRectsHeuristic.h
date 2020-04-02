#pragma once

namespace RectangleBinPack
{
	/// <summary>
	/// Specifies the different heuristic rules that can be used when deciding
	/// where to place a new rectangle.
	/// </summary>
	public enum class MaxRectsHeuristic
	{
		BestShortSideFit,
		BestLongSideFit,
		BestAreaFit,
		BottomLeftRule,
		ContactPointRule
	};
}
