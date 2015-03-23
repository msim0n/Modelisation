#pragma once
#include <iostream>

using namespace std;
class Etiquette
{
public:
	Etiquette();
	Etiquette(int c, int d);
	Etiquette(Etiquette & e);
	~Etiquette();
	int getCout();
	int getDuree();
	void setCout(int c);
	void setDuree(int d);
	void Set(int c, int d);
	bool existe();
	void afficher(std::ostream &flux);
	friend ostream& operator<<(ostream &flux, Etiquette e);

private:
	int cout;
	int duree;
};

