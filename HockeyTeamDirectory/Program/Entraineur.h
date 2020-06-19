/*
 * \file Entraineur.h
 * \brief Programme qui declare la classe Entraineur
 * \author Alexandra Langlais
 * \version 1.0
 * \date 02/03/2020
 */

#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Personne.h"

namespace hockey
{
/**
 * \class Entraineur
 * \param  Classe dérivée de la classe Personne
 */
class Entraineur: public Personne
{
public:
	Entraineur(std::string p_nom, std::string p_prenom, util::Date p_dateNaissance, const std::string& p_telephone,
			const std::string& p_numRAMQ, char p_sexe);
	virtual ~Entraineur();

	const std::string reqNumRAMQ() const;
	virtual std::string reqPersonneFormate() const;

	virtual Personne* clone() const;

private:
	std::string m_numRAMQ;
	char m_sexe;

	void verifieInvariant() const;
};
}

#endif /* ENTRAINEUR_H_ */
