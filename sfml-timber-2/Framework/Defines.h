#pragma once

// Defines.h

enum class Origins
{
	TL, TC, TR,	// 0 1 2
	ML, MC, MR,	// 3 4 5
	BL, BC, BR, // 6 7 8
	Custom
};

enum class SceneIds
{
	None = -1,
	Title,
	mode,
	CharacterSelect,
	CharacterSelectVs,
	Game,
	GameVs,
	Dev1,
	Dev2,
	Count,

};

enum class Sides
{
	Left,
	Right,
	None,
	Up,
	Down
};

enum class PlayerType
{
	Player,
	Player1,
	Player2,
};


enum class PlayerType2
{
	Player3,
	Player4,
	Player5,
};