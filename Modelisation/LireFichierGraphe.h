#pragma once

//!
//! \file LireFichierGraphe.h
//!

#include <string>
#include "Graphe.h"

//!
//! \class LireFichierGraphe
//!
class LireFichierGraphe
{
public:
	LireFichierGraphe();
	virtual ~LireFichierGraphe();

	static Graphe chargerFichierGraphe(const string & nomFichier);
};
