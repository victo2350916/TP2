#pragma once

#include <stdint.h>

#pragma pack(1)

/// <summary>
/// Piece du labyrithe qui contient les liens.
/// </summary>
struct Piece
{
	/// <summary>
	/// Case actuelle
	/// </summary>
	uint16_t numCaseActuelle{ 0 };

	/// <summary>
	/// lien vers une autre case.
	/// </summary>
	uint16_t numCaseSuivante{ 0 };
};
#pragma pack(pop)
