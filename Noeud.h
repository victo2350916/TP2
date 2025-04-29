#pragma once

#include <vector>

/// <summary>
/// Stucture qui contient une case ainsi que ses liens.
/// </summary>
struct Noeud
{
	/// <summary>
	/// case actuelle
	/// </summary>
	int caseActuelle{ 0 };

	/// <summary>
	/// vecteur des liens
	/// </summary>
	std::vector<int> suivants;
};