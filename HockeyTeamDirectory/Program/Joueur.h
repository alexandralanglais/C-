/*
 * Joueur.h
 *
 *  Created on: 2020-03-02
 *      Author: etudiant
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Personne.h"

namespace hockey
{

class Joueur: public Personne
{
public:
	Joueur(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
			const std::string& p_telephone, const std::string p_position);

	virtual std::string reqPersonneFormate() const;
	const std::string reqPosition() const;
	virtual Personne* clone() const;



private:
	std::string m_position;

	void verifieInvariant() const;



};

}




#endif /* JOUEUR_H_ */
