#pragma once

#include <stdint.h>

#pragma pack(push, 1)
struct EnteteFichier
{
	/// <summary>
	/// type du fichier, toujours 0x6969
	/// </summary>
	uint16_t typeFichier{ 0x6969 };

	/// <summary>
	/// taille du fichier en octets				
	/// </summary>
	uint32_t tailleFichier{ 0 };

	/// <summary>
	/// décalage des données du labyrinthe par rapport au début du fichier, en octets				
	/// </summary>
	uint32_t offset{ 0 };
	
	/// <summary>
	/// taille des données du labyrinthe en octets (entêtes exclus)
	/// </summary>
	uint32_t tailleDonnees{ 0 };

	/// <summary>
	/// nombre de cases dans le labyrinthe
	/// </summary>
	uint16_t nombreCase{ 0 };

	/// <summary>
	/// numéro de la case de depart
	/// </summary>
	uint16_t caseDepart{ 0 };

	/// <summary>
	/// numéro de la case d'arrivée
	/// </summary>
	uint16_t caseArrivee{ 0 };
};

struct EnteteSolution
{
	/// <summary>
	/// taille du chemin de solution (nb de cases à traverser)
	/// </summary>
	uint32_t tailleCheminSolution{ 0 };

	/// <summary>
	/// décalage des données de la solution par rapport au début du fichier, en octets
	/// </summary>
	uint32_t offset{ 0 };
};
#pragma pack(pop)
