#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "LireFichierGraphe.h"
using namespace std;

LireFichierGraphe::LireFichierGraphe()
{
}


LireFichierGraphe::~LireFichierGraphe()
{
}

vector<std::string> explode(std::string const & s, char delim)
{
	vector<std::string> result;
	istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim);)
	{
		result.push_back(std::move(token));
	}

	return result;
}

void replaceAll(string & str, const string & from, const string & to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}


/*static*/ Graphe LireFichierGraphe::chargerFichierGraphe(const string & nomFichier)
{
	bool sommets = false; bool arcs = false;
	Graphe graphe;
	ifstream fichier("Instances/" + nomFichier, ios::in); // lecture

	if (fichier)
	{
		string ligne;
		int it = 0;
		vector<Sommet> lsommet;
		vector<vector<Etiquette>> larrete;

		while (getline(fichier, ligne))
		{
			if (sommets && (ligne.substr(0, 1) == "i" || ligne.substr(0, 1) == "p" || ligne.substr(0, 2) == "s0"))
			{
				
				replaceAll(ligne, "  ", " ");
				vector<string> exp = explode(ligne, ' ');
				lsommet.push_back(Sommet(stoi(exp[0].erase(0,1))));
				//lsommet.push_back(it);
				it++;
			}

			else if (arcs && (ligne.substr(0, 3) == "arc"))
			{
				replaceAll(ligne, "  ", " ");
				vector<Etiquette> e;
				vector<string> exp = explode(ligne, ' ');
				e.push_back(Etiquette(stoi(exp[3]), stoi(exp[4])));
				larrete.push_back(e);
			}
			

			//-------------- partie où l'on est ------------------
			if (ligne == "sectionSommets")
				sommets = true;
			else if (ligne == "sources")
				sommets = false;
			else if (ligne == "sectionArcs")
				arcs = true;
		}

		graphe.setSommets(lsommet);
		graphe.setAretes(larrete);
		fichier.close();
		return graphe;
	}
	else
	{
		//cerr << "Impossible d'ouvrir le fichier !" << endl;
		return graphe;
	}
}
