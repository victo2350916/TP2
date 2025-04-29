#pragma once

/// <summary>
/// Interface pour l'affichage
/// </summary>
class IAffichable
{
	/// <summary>
	/// Afficher les liens
	/// </summary>
	virtual void afficherLiens() = 0;

	/// <summary>
	/// Afficher la solution
	/// </summary>
	virtual void afficherSolution() = 0;
};

