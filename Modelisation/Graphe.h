#pragma once
#include "Etiquette.h"
#include "Sommet.h"
#include <iostream>
using namespace std;
class Graphe
{
public:
	Graphe();
	Graphe(Graphe & g);
	Graphe(vector<Sommet> s,vector<vector<Etiquette>> a);
	~Graphe();
	vector<Sommet> getSommets();
	vector<vector<Etiquette>> getAretes();
	void setSommets(vector<Sommet> v);
	void setAretes(vector<vector<Etiquette>> e);
	Etiquette getArete(int x, int y);
	Sommet getSommet(int i);
	void afficher(std::ostream &flux);
	friend ostream& operator<<(ostream &flux, Graphe g);


private:
	vector<Sommet> sommets;
	vector<vector<Etiquette>> aretes;
};

