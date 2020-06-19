/**
 * \file Entraineur.cpp
 * \brief Implémentation de la classe Entraineur
 * \author Alexandra Langlais
 * \version 1.0
 * \date 02/03/2020
 */

#include "Entraineur.h"
#include <sstream>

using namespace std;

namespace hockey
{
/**
 * \brief Constructeur d'un objet de la classe Entraineur
 * \param[in] p_nom Nom de l'entraineur
 * \param[in] p_prenom Prénom de l'entraineur
 * \param[in] p_dateNaissance Date de naissance de l'entraineur
 * \param[in] p_telephone Numéro de téléphone de l'entraineur
 * \param[in] p_numRAMQ Numéro de RAMQ de l'entraineur
 * \param[in] p_sexe Sexe de l'entraineur
 * \pre p_nom, p_prenom, p_dateNaissance, p_telephone, p_numRAMQ et p_sexe doivent correspondre à un format valide
 * \post m_numRAMQ, m_sexe prennent les valeurs de p_numRAMQ, p_sexe
 */
Entraineur::Entraineur(std::string p_nom, std::string p_prenom, util::Date p_dateNaissance, const std::string& p_telephone,
			const std::string& p_numRAMQ, char p_sexe):
			Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
{
	PRECONDITION(p_sexe == 'M' || p_sexe == 'F' || p_sexe == 'm' || p_sexe == 'f');
	util::Date dateNaissanceAdulte;
	dateNaissanceAdulte.ajouteNbJour(-6570); //Il y a 6570 jours dans 18 années
	PRECONDITION(p_dateNaissance < dateNaissanceAdulte);
	PRECONDITION(util::validerNumRAMQ(p_numRAMQ, p_nom, p_prenom, p_dateNaissance.reqJour(),
		p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee(), p_sexe));

	POSTCONDITION(m_numRAMQ == p_numRAMQ);
	POSTCONDITION(m_sexe == p_sexe);

	INVARIANTS();
}
Entraineur::~Entraineur()
{
}

/**
 * \brief Retourne le numéro de RAMQ de l'entraineur
 * \return Le numéro de RAMQ de l'entraineur
 */
const string Entraineur::reqNumRAMQ() const
{
	return m_numRAMQ;
}

/**
 * \brief Retourne les informations de l'entraineur sous forme d'un string
 * \return Les informations de l'entraineur
 */
std::string Entraineur::reqPersonneFormate() const
{
	ostringstream os;

	os << Personne::reqPersonneFormate();
	os << "Numero de RAMQ :    " << Entraineur::reqNumRAMQ() << endl;
	os << "---------------------" << endl;

	return os.str();
}

/**
 * \brief Retourne un clone de l'objet entraineur
 * \return Une copie de l'entraineur
 */
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}

/**
 * \brief Vérifier les invariants de la classe Entraineur
 */
void Entraineur::verifieInvariant() const
{
	INVARIANT(m_sexe == 'M' || m_sexe == 'F' || m_sexe == 'm' || m_sexe == 'f');
	INVARIANT(util::validerNumRAMQ(m_numRAMQ, m_nom, m_prenom, m_dateNaissance.reqJour(),
			m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee(), m_sexe));
}

}



