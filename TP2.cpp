#include <iostream>

#include "Affichage.h"
#include "GestionFichier.h"
#include "Solution.h"

int main()
{
	GestionFichier gf("TestMaze.tp2");
	Solution sol(gf);
	sol.genererSolution();
	Affichage a(gf);
	a.afficherLiens();
	a.afficherSolution();

}