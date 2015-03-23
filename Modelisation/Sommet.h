#pragma once
#include "Etiquette.h"
#include <vector>
#include <iostream>

using namespace std;
class Sommet
{
public:
	Sommet();
	Sommet(int i, vector<Etiquette> v);
	Sommet(int i);
	Sommet(Sommet & s);
	~Sommet();
	void setId(int i);
	void setEtiquettes(vector<Etiquette>);
	int getId();
	vector<Etiquette> getEtiquettes();
	void ajouterEtiquette(Etiquette e);
	void domination();
	void afficher(std::ostream &flux);
	friend ostream& operator<<(ostream &flux, Sommet e);

private:
	int id;
	vector<Etiquette> etiquettes;
};

