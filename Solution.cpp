#include "Solution.h"

#include <map>
#include <vector>
#include <set>

Solution::Solution(GestionFichier& fichier) : m_fichier{fichier}
{
	InitialiserLiens();
}

void Solution::InitialiserLiens()
{
	std::vector<Piece> pieces = m_fichier.retournerPieces();

	std::set<int> uniques;
	for (Piece piece : pieces)
	{
		uniques.insert(piece.numCaseActuelle);
		uniques.insert(piece.numCaseSuivante);
	}

	int idx = 0;

	for (int unique : uniques)
	{
		Noeud nouveau;
		nouveau.caseActuelle = unique;
		m_labyrithe.push_back(nouveau);
		m_liens.push_back(idx++);
	}

	for (Piece piece : pieces)
	{
		int actuelle = m_liens[piece.numCaseActuelle];
		int suivant = m_liens[piece.numCaseSuivante];
		m_labyrithe[actuelle].suivants.push_back(suivant);
	}
}

void Solution::genererSolution()
{
	std::vector<uint16_t>& solution = m_fichier.retournerEtapes();
	solution.clear();

	int caseDebut = m_fichier.retournerCaseDepart();
	int caseFin = m_fichier.retournerCaseFin();

	std::vector<bool> visite(m_labyrithe.size(), false);

	verifierAjout(solution, caseDebut, caseFin, visite);
}

bool Solution::verifierAjout(std::vector<uint16_t>& solution, int index, int caseFin, std::vector<bool>& visite)
{
	visite[index] = true;
	solution.push_back(index);

	if (index == caseFin)
	{
		return true;
	}

	for (int suivant : m_labyrithe[index].suivants)
	{
		if (!visite[suivant] && verifierAjout(solution, suivant, caseFin, visite))
		{
			return true;
		}
	}

	solution.pop_back();
	return false;
}
