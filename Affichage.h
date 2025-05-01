#pragma once

#include <vector>
#include <string>

#include "IAffichable.h"
#include "GestionFichier.h"

/// <summary>
/// Classe qui sert à afficher les éléments en console.
/// </summary>
class Affichage : public IAffichable
{
private:

	/// <summary>
	/// Fichier qui contient les données à afficher.
	/// </summary>
	GestionFichier m_fichier;
public:

	/// <summary>
	/// Constructeur de la classe affichage.
	/// </summary>
	/// <param name="fichier"> Fichier qui sera utilisé. </param>
	Affichage(const GestionFichier& fichier);

	/// <summary>
	/// Affiche les liens entre les piece du labyrithe.
	/// </summary>
	void afficherLiens();

	/// <summary>
	/// Affiche les étapes nécéssaire pour se rendre à la fin du labyrinthe.
	/// </summary>
	void afficherSolution();
};

