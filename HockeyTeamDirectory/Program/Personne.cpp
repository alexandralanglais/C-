/**
 * \file Personne.cpp
 * \brief Programme d'implémentation de la classe Personne
 * \author Alexandra Langlais
 * \version 1.0
 * \date 12/02/2020
 */

#include "Personne.h"
#include <sstream>
#include <string>

using namespace std;

namespace hockey
{

/**
 * \brief Constructeur d'un objet de la classe Personne
 * \param[in] p_nom string qui représente le nom du joueur
 * \param[in] p_prenom string qui représente le prénom du joueur
 * \param[in] p_dateNaissance string qui représente la date de naissance du joueur
 * \param[in] p_telephone string qui représente le numéro de téléphone du joueur
 * \pre p_nom, p_prenom, p_dateNaissance et p_telephone doivent correspondre à un format valide
 * \post m_nom, m_prenom, m_dateNaissance, m_telephone prennent les valeurs respectives de
 * 			p_nom, p_prenom, p_dateNaissance, p_telephone
 */
Personne::Personne(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
		const std::string& p_telephone):
		m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerFormatNom(p_nom));
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));
	PRECONDITION(util::Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);
	POSTCONDITION(m_telephone == p_telephone);

	INVARIANTS();
}

/**
 * \brief Retourne le nom du joueur
 * \return Le nom du joueur
 */
const std::string Personne::reqNom() const
{
	return m_nom;
}

/**
 * \brief Retourne le prénom du joueur
 * \return Le prénom du joueur
 */
const std::string Personne::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Retourne la date de naissance du joueur
 * \return la date de naissance du joueur
 */
const util::Date Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

/**
 * \brief Retourne le numéro de téléphone du joueur
 * \return Le numéro de téléphone du joueur
 */
const std::string Personne::reqTelephone() const
{
	return m_telephone;
}

/**
 * \brief Assigne un numéro de téléphone à l'objet courant
 * \param[in] p_telephone est un string qui représente le numéro de téléphone du joueur
 * \pre p_telephone doit correspondre à un format valide
 * \post l'objet courant a été correctement assigné
 */
void Personne::asgTelephone(const string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * \brief Surchage de l'opérateur == qui permet de vérifier si deux joueurs sont identiques
 * \param[in] p_personne l'objet personne à comparer
 * \return valeur booléene résultant de la comparaison entre les deux joueurs
 */
bool Personne::operator ==(Personne& p_personne) const
{
	if (m_nom == p_personne.m_nom &&
		m_prenom == p_personne.m_prenom &&
		m_dateNaissance == p_personne.m_dateNaissance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * \brief Renvoie les informations du joueur selon un formatage spécifié
 * \return Les informations du joueur sous un format texte dans la console
 */
std::string Personne::reqPersonneFormate() const
{
	stringstream os;

	os << "Nom :               " << Personne::reqNom() << endl;
	os << "Prenom :            " << Personne::reqPrenom() << endl;
	os << "Date de naissance : " << Personne::reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone :         " << Personne::reqTelephone() << endl;

	return os.str();
}

/**
 * \brief Vérifier les invariants de la classe Personne
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
	INVARIANT(util::validerTelephone(m_telephone));
}

}
