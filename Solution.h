#pragma once

#include <vector>
#include <map>
#include <stack>

#include "GestionFichier.h"
#include "Noeud.h"

/// <summary>
/// Classe qui s'occupe de générer la solution.
/// </summary>
class Solution
{
private:

	/// <summary>
	/// Fichier qui contient les données nécéssaires.
	/// </summary>
	GestionFichier& m_fichier;

	/// <summary>
	/// Vecteur contenant les Noeuds
	/// </summary>
	std::vector<Noeud> m_labyrithe;

	/// <summary>
	/// associe un les indexs à des cases 
	/// </summary>
	std::vector<int> m_liens;

	/// <summary>
	/// Ajoute les liens dans un vecteur chemin
	/// </summary>
	/// <param name="solution"> Vecteur provenant de gestion fichier qui doit contenir la solution </param>
	/// <param name="caseDebut"> case de début du labyrinthe </param>
	/// <param name="caseFin"> case de la fin du labyrinthe </param>
	/// <param name="visite"> vecteur contenant les cases visitées </param>
	/// <param name="chemin"> vecteur qui contien le chemin vers la solution </param>
	/// <returns> vrai si l'ajoute est effectué ou si la fin est trouvé</returns>
	bool verifierAjout(std::vector<uint16_t>& solution, int caseDebut, int caseFin, std::vector<bool>& visite);
public:

	/// <summary>
	/// Constucteur de la solution
	/// </summary>
	/// <param name="fichier"> Fichier qui contient les données nécéssaires</param>
	Solution(GestionFichier& fichier);

	/// <summary>
	/// Initialise m_labyrinthe et m_liens
	/// </summary>
	void InitialiserLiens();

	/// <summary>
	/// initialise tout les éléments néssécaire pour verifierAjout()
	/// </summary>
	void genererSolution();
};
