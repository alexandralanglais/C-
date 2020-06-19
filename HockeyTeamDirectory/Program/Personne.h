/**
 * \file Personne.h
 * \brief Programme qui declare la classe Personne
 * \author Alexandra Langlais
 * \version 1.0
 * \date 12/02/2020
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include "Date.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;

namespace hockey
{

/**
 * \class Personne
 * \brief Classe implantant le concept de création d'un joueur dans un club de hockey.
 * 		  Elle contient le nom, le prenom, la date de naissance et le numero de telephone.
 * 		  Elle contient aussi une méthode qui permet d'afficher une personne formatée ainsi
 * 		  qu'un méthode qui permet de changer le numéro de téléphone d'une personne.
 * 		  Attributs: std::string m_nom: un string contenant le nom du joueur.
 * 		  			 std::string m_prenom: un string contenant le prenom du joueur
 * 		  			 util::Date m_dateNaissance: un string contenant la date de naissance du joueur
 * 		  			 std::string m_telephone: un string contenant le numero de telephone du joueur
 */
class Personne
{
public:
	Personne(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
			const std::string& p_telephone);

	virtual ~Personne()
	{
	};

	virtual Personne* clone() const = 0;

	const std::string reqNom() const;
	const std::string reqPrenom() const;
	const util::Date reqDateNaissance() const;
	const std::string reqTelephone() const;
	virtual std::string reqPersonneFormate() const;

	void asgTelephone(const std::string& p_telephone);

	bool operator ==(Personne& p_personne) const;

protected:

	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;

private:

	void verifieInvariant() const;
};
}

#endif /* PERSONNE_H_ */
