#include "Etiquette.h"
Etiquette::Etiquette()
{
}

Etiquette::Etiquette(int c, int d)
{
	cout = c;
	duree = d;
}

int Etiquette::getCout(){
	return cout;
}

int Etiquette::getDuree(){
	return duree;
}

void Etiquette::setCout(int c){
	cout = c;
}

void Etiquette::setDuree(int d){
	cout = d;
}

void Etiquette::Set(int c, int d){
	cout = c;
	duree = d;
}

bool Etiquette::existe(){
	if (cout == -1 && duree == -1){
		return false;
	}
	else{
		return true;
	}
}

void Etiquette::afficher(ostream &flux)
{
	flux << "cout : " << this->cout << " durée : " << this->duree << "\n";
}

ostream& operator<<(ostream &flux, Etiquette e)
{
	e.afficher(flux);
	return flux;
}

Etiquette::~Etiquette()
{
}

Etiquette::Etiquette(Etiquette & e){
	this->cout = e.getCout();
	this->duree = e.getDuree();
}