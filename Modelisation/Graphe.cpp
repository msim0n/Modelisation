#include "Graphe.h"

Graphe::Graphe()
{
}

Graphe::Graphe(vector<Sommet> s, vector<vector<Etiquette>> e){
	sommets = s;
	aretes = e;
}

Graphe::~Graphe()
{
}

vector <Sommet> Graphe::getSommets(){
	return sommets;
}

vector<vector<Etiquette>> Graphe::getAretes(){
	return aretes;
}

void Graphe::setSommets(vector<Sommet> s){
	sommets = s;
}

void Graphe::setAretes(vector<vector<Etiquette>> e){
	aretes = e;
}

Sommet Graphe::getSommet(int i){
	return sommets.at(i);
}

//Cette fonction va forcement faire des fuites de mémoires tel quel. A changer. Si tu veux.
Etiquette Graphe::getArete(int x, int y){
	Etiquette e = Etiquette(aretes.at(x).at(y).getCout(), aretes.at(x).at(y).getDuree());
	return e;
}

void Graphe::afficher(ostream &flux)
{
	flux << "Composition du graphe :\n";
	cout << "Sommet :\n";
	vector<Sommet>::iterator it;
	for (it = sommets.begin(); it != sommets.end(); it++)
	{
		it->afficher(flux);
	}
	cout << "Aretes :\n";
	/*
	vector<vector<Etiquette>>::iterator it2;
	vector<Etiquette>::iterator it3;
	for (it2 = aretes.begin(); it2 != aretes.end(); it2++)
	{
		
		for (it3 = it2.begin(); it3 != it2.end(); it3++){

		}
	}
	*/
	for (auto &i : aretes){
		for (auto &j : i){
			cout << j;
		}
	}
}

ostream& operator<<(ostream &flux, Graphe g)
{
	g.afficher(flux);
	return flux;
}

Graphe::Graphe(Graphe & g){
	this->sommets = g.getSommets();
	this->aretes = g.getAretes();
}