#pragma once

namespace RectangleBinPack
{
	/// <summary>
	/// Defines the different heuristic rules that can be used to decide how to make the rectangle placements.
	/// </summary>
	public enum class SkylineHeuristic
	{
		BottomLeft,
		MinWasteFit
	};
}
