//#include "Etiquette.h"
#include "Sommet.h"

Sommet::Sommet()
{
}

Sommet::Sommet(int i, vector<Etiquette> e){
	this->id = i;
	this->etiquettes = e;
}

Sommet::Sommet(int i){
	this->id = i;
	etiquettes = vector<Etiquette>();
}

void Sommet::setId(int i){
	this->id = i;
}

void Sommet::setEtiquettes(vector<Etiquette> e){
	this->etiquettes = e;
}

int Sommet::getId(){
	return id;
}

vector<Etiquette> Sommet::getEtiquettes(){
	return etiquettes;
}

void Sommet::ajouterEtiquette(Etiquette e){
	etiquettes.push_back(e);
}

void Sommet::domination(){
	int coutMax = 0;
	int dureeMax = 0;
	bool coutDomine;
	bool dureeDomine;
	int tab [10];
	int n = 0;
	vector<Etiquette>::iterator it;
	for (it = etiquettes.begin(); it != etiquettes.end(); it++)
	//for (Etiquette &e : etiquettes)
	{

		coutDomine, dureeDomine = false;
		if (it->getCout() > coutMax){
			coutMax = it->getCout();
		}
		else{
			coutDomine = true;
		}
		if (it->getDuree() > dureeMax){
			dureeMax = it->getDuree();
		}
		else{
			dureeDomine = true;
		}
		if (coutDomine && dureeDomine)
		{
			tab[n] = 1;

		}
		n++;
	}
	for (int i = 10; i >= 0; i--)
	{
		if (tab[i]==1)
		{
			etiquettes.erase(etiquettes.begin() + i);
		}
	}
}



void Sommet::afficher(ostream &flux)
{
	flux << "id : " << this->id << " \n";
	vector<Etiquette>::iterator it;
	for (it = etiquettes.begin(); it != etiquettes.end(); it++)
	{
		it->afficher(flux);
	}
}

ostream& operator<<(ostream &flux, Sommet e)
{
	e.afficher(flux);
	return flux;
}

Sommet::~Sommet()
{
}

Sommet::Sommet(Sommet & s){
	this->id = s.getId();
	this->etiquettes = s.getEtiquettes();
}