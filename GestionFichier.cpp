#include "GestionFichier.h"
#include <fstream>

GestionFichier::GestionFichier(const std::string filePath)
{
	this->lireLabyrinthe(filePath);
}

void GestionFichier::lireLabyrinthe(const std::string filePath)
{
	std::ifstream ouverture{ filePath, std::ios::in | std::ios::binary };
	if (ouverture.is_open())
	{
		ouverture.read((char*)&m_enteteFichier, sizeof(m_enteteFichier));
		ouverture.read((char*)&m_enteteSolution, sizeof(m_enteteSolution));

		m_pieces.resize(m_enteteFichier.tailleDonnees / sizeof(Piece));

		ouverture.seekg(m_enteteFichier.offset, ouverture.beg);
		ouverture.read((char*)m_pieces.data(), m_pieces.size() * sizeof(Piece));

		m_etapes.resize(m_enteteSolution.tailleCheminSolution / sizeof(uint16_t));

		ouverture.seekg(m_enteteSolution.offset, ouverture.beg);
		ouverture.read((char*)m_etapes.data(), m_etapes.size() * sizeof(uint16_t));

		ouverture.close();
	}
}

void GestionFichier::ecrireSolution(const std::string filePath)
{
	std::ofstream fichierSortie{ filePath, std::ios_base::binary };
	if (fichierSortie)
	{
		m_enteteSolution.tailleCheminSolution = m_etapes.size() * sizeof(uint16_t);

		fichierSortie.write((char*)&m_enteteFichier, sizeof(m_enteteFichier));
		fichierSortie.write((char*)&m_enteteSolution, sizeof(m_enteteSolution));

		int sizePiece = m_pieces.size();

		fichierSortie.write((char*)m_pieces.data(), sizePiece * sizeof(Piece));

		int sizeEtape = m_etapes.size();

		fichierSortie.write((char*)m_etapes.data(), sizeEtape * sizeof(uint16_t));	
	}
}

const std::vector<Piece>& GestionFichier::retournerPieces()
{
	return m_pieces;
}

std::vector<uint16_t>& GestionFichier::retournerEtapes()
{
	return m_etapes;
}

const uint16_t& GestionFichier::retournerCaseDepart()
{
	return m_enteteFichier.caseDepart;
}

const uint16_t& GestionFichier::retournerCaseFin()
{
	return m_enteteFichier.caseArrivee;
}
