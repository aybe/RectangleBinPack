#pragma once

namespace RectangleBinPack
{
	/// <summary>
	/// Specifies the different choice heuristics that can be used when the packer needs to decide
	/// whether to subdivide the remaining free space in horizontal or vertical direction.
	/// </summary>
	public enum class GuillotineSplit
	{
		ShorterLeftoverAxis,
		LongerLeftoverAxis,
		MinimizeArea,
		MaximizeArea,
		ShorterAxis,
		LongerAxis
	};
}
