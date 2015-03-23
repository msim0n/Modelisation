#include <iostream>
#include "Etiquette.h"
#include "Graphe.h"
#include "Sommet.h"
#include "Algo.h"
using namespace std;
int main(int argc, char const *argv[])
{
	/*
	On tente de faire un petit graphe
	Trois sommets A(1) B(2) C(3)
	deux arêtes 1-2 (2;5) et 1-3 (6;3)
	Les sommets ont des étiquettes vides
	*/

	Sommet A = Sommet(1);
	Sommet B = Sommet(2);
	Sommet C = Sommet(3);

	

	

	Etiquette AB = Etiquette(2, 5);
	Etiquette AC = Etiquette(6, 3);
	//On est obligé de créer des etiquettes vides parce que vector ne semble pas aimer les NULL.
	//J'ai créé une fonction Etiquette::existe pour savoir si l'etiquette représente une arète ou non.
	Etiquette AA = Etiquette(-1, -1);
	Etiquette BA = Etiquette(-1, -1);
	Etiquette BB = Etiquette(-1, -1);
	Etiquette BC = Etiquette(-1, -1);
	Etiquette CA = Etiquette(-1, -1);
	Etiquette CB = Etiquette(-1, -1);
	Etiquette CC = Etiquette(-1, -1);

	//cout << AB;
	A.ajouterEtiquette(AA); //Je lui met des etiquettes parce qu'il faut bien tester
	A.ajouterEtiquette(AB);
	A.domination();
	//cout << A;

	vector<Sommet> sommetsDeG1 = vector<Sommet>();
	sommetsDeG1.push_back(A);
	sommetsDeG1.push_back(B);
	sommetsDeG1.push_back(C);

	//On crée la matrice
	vector<Etiquette> aretePartantdeA = vector<Etiquette>();
	aretePartantdeA.push_back(AA);
	aretePartantdeA.push_back(AB);
	aretePartantdeA.push_back(AC);
	vector<Etiquette> aretePartantdeB = vector<Etiquette>();
	aretePartantdeB.push_back(BA);
	aretePartantdeB.push_back(BB);
	aretePartantdeB.push_back(BC);
	vector<Etiquette> aretePartantdeC = vector<Etiquette>();
	aretePartantdeC.push_back(CA);
	aretePartantdeC.push_back(CB);
	aretePartantdeC.push_back(CC);
	vector<vector<Etiquette>> aretesDeG1 = vector<vector<Etiquette>>();
	aretesDeG1.push_back(aretePartantdeA);
	aretesDeG1.push_back(aretePartantdeB);
	aretesDeG1.push_back(aretePartantdeB);
	/*
	Heuresement de le C/C existe...
	DONC ! La matrice ressemble à ça
	(Null, AB, AC;
	Null, null, null;
	null, null, null)
	*/



	

	Graphe G1 = Graphe(sommetsDeG1, aretesDeG1);
	cout << "cool\n";
	cout << G1;
	//G1 = Algo::algo(G1);
	return 0;
}