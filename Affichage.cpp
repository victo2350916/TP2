#include <iostream>

#include "Affichage.h"
#include "GestionFichier.h"

Affichage::Affichage(const GestionFichier& fichier) : m_fichier{ fichier } {}

void Affichage::afficherLiens()
{
	for (const Piece piece : m_fichier.retournerPieces())
	{
		std::cout << piece.numCaseActuelle << "-" << piece.numCaseSuivante << std::endl;
	}
}

void Affichage::afficherSolution()
{
	const std::vector<uint16_t> etapes = m_fichier.retournerEtapes();
	for (int i = 0; i < etapes.size(); i++)
	{
		std::cout << etapes[i];
		if (i != etapes.size() - 1)
		{
			std::cout << " - ";
		}
	}
}
