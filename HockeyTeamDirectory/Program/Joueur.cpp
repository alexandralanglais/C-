/*
 * Joueur.cpp
 *
 *  Created on: 2020-03-02
 *      Author: etudiant
 */
#include "Joueur.h"
#include <sstream>

using namespace std;

namespace hockey
{

Joueur::Joueur(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
		const std::string& p_telephone, const std::string p_position):
		Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_position(p_position)
{
	PRECONDITION(p_position == "AILIER" || p_position == "CENTRE" || p_position == "DEFENSEUR" || p_position == "GARDIEN");
	util::Date moinsDe18Ans;
	util::Date plusDe15Ans;
	moinsDe18Ans.ajouteNbJour(-6570); //6570 jours dans 18 années
	plusDe15Ans.ajouteNbJour(-5475);//5475 jours dans 15 années
	PRECONDITION(moinsDe18Ans < p_dateNaissance);
	PRECONDITION(p_dateNaissance < plusDe15Ans);

	POSTCONDITION(p_position == m_position);

	INVARIANTS();
}

const string Joueur::reqPosition() const
{
	return m_position;
}

std::string Joueur::reqPersonneFormate() const
{
	stringstream os;

	os << Personne::reqPersonneFormate();
	os << "Position :          " << Joueur::reqPosition() << endl;
	os << "---------------------" << endl;

	return os.str();
}

Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

void Joueur::verifieInvariant() const
{
	INVARIANT(m_position == "AILIER" || m_position == "CENTRE" || m_position == "DEFENSEUR" || m_position == "GARDIEN");
	util::Date moinsDe18Ans;
	util::Date plusDe15Ans;
	moinsDe18Ans.ajouteNbJour(-6570); //6570 jours dans 18 années
	plusDe15Ans.ajouteNbJour(-5475);//5475 jours dans 15 années
	INVARIANT(moinsDe18Ans < m_dateNaissance);
	INVARIANT(m_dateNaissance < plusDe15Ans);
}

}


