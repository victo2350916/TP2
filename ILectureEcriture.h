#pragma once

#include <string>

/// <summary>
/// Interface pour la lecture et l'écriture d'un fichier
/// </summary>
class ILectureEcriture
{
	/// <summary>
	/// Lecture du fichier
	/// </summary>
	/// <param name="filePath"> chemin du fichier </param>
	virtual void lireLabyrinthe(const std::string filePath) = 0;

	/// <summary>
	/// écriture sur le fichier
	/// </summary>
	/// <param name="filePath"> chemin d'écriture </param>
	virtual void ecrireSolution(const std::string filePath) = 0;
};

