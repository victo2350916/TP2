#pragma once

#include <string>
#include <vector>

#include "Headers.h"
#include "Piece.h"
#include "ILectureEcriture.h"

/// <summary>
/// Gère le fichier demandé.
/// </summary>
class GestionFichier : public ILectureEcriture
{
private:

	/// <summary>
	/// Entête du fichier.
	/// </summary>
	EnteteFichier m_enteteFichier;

	/// <summary>
	/// Entête de la solution
	/// </summary>
	EnteteSolution m_enteteSolution;

	/// <summary>
	/// Vecteur des pièces du labyrinthe.
	/// </summary>
	std::vector<Piece> m_pieces;

	/// <summary>
	/// Vecteur des étapes pour se rendre à la fin du labyrithe.
	/// </summary>
	std::vector<uint16_t> m_etapes;
public:

	/// <summary>
	/// Constructeur le la gestion du fichier.
	/// </summary>
	/// <param name="filePath"> Chemin vers le fichier. </param>
	GestionFichier(const std::string filePath);

	/// <summary>
	/// Charge les information d'un fichier en mémoire.
	/// </summary>
	/// <param name="filePath"> Chemin vers le fichier. </param>
	void lireLabyrinthe(const std::string filePath) override;

	/// <summary>
	/// Enregistre les informations du fichier en mémoire sur le disque dur de l'ordinateur.
	/// </summary>
	/// <param name="filePath"> Chemin vers l'emplacement de sauvegarde. </param>
	void ecrireSolution(const std::string filePath) override;

	/// <summary>
	/// Retourne les pièces du labyrinthe.
	/// </summary>
	/// <returns> Les pièce du labyrinthe. </returns>
	const std::vector<Piece>& retournerPieces();

	/// <summary>
	/// Retourne les étapes vers la fin du labyrithe.
	/// </summary>
	/// <returns> Les étapes vers la fin du labyrithe. </returns>
	std::vector<uint16_t>& retournerEtapes();

	/// <summary>
	/// Retourne la case de départ du labyrithe.
	/// </summary>
	/// <returns> La case de départ du labyrithe. </returns>
	const uint16_t& retournerCaseDepart();

	/// <summary>
	/// Retourne la case d'arrivée du labyrithe.
	/// </summary>
	/// <returns> La case de d'arrivée du labyrithe. </returns>
	const uint16_t& retournerCaseFin();
};

