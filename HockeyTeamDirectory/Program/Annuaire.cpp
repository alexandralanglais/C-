/**
 * \file Annuaire.cpp
 * \brief Implémentation de la classe Annuaire
 * \author Alexandra Langlais
 * \version 1.0
 * \date 02/03/2020
 */

#include "Annuaire.h"
#include <sstream>

using namespace std;

namespace hockey
{
/**
 * \brief Constructeur d'un nouvel objet de la classe Annuaire
 * \param[in] p_nomClub Nom du club
 * \pre p_nomClub est un nom de club valide
 * \post m_nomClub prend la valeur de p_nomClub
 */
Annuaire::Annuaire(const std::string p_nomClub):
		m_nomClub(p_nomClub)
{
	PRECONDITION(!(p_nomClub.empty()));

	POSTCONDITION(m_nomClub == p_nomClub);
}
// Destructeur de la classe
Annuaire::~Annuaire()
{
	vector<Personne*>::iterator iter;
	for (iter = m_vMembres.begin(); iter < m_vMembres.end(); iter++)
	{
		delete *iter;
	}
	m_vMembres.clear();
}

/**
 * \brief Retourne le nom du club de la personne
 * \return Le nom du club de la personne
 */
std::string Annuaire::reqNomClub() const
{
	return m_nomClub;
}

/**
 * \brief Retourne les informations dans l'anuaire sous forme de string
 * \return Les informations dans l'annuaire
 */
std::string Annuaire::reqAnnuaireFormate() const
{
	ostringstream os;

	os << "Club : " << reqNomClub() << endl;
	os << "---------------------" << endl;

	for (size_t i = 0; i < m_vMembres.size(); ++i)
	{
		os << (*m_vMembres[i]).reqPersonneFormate();
	}

	return os.str();
}

/**
 * \brief Permet d'ajouter une nouvelle personne dans l'Annuaire
 * \param[in] p_personne Objet de type personne
 */
void Annuaire::ajouterPersonne(const Personne& p_personne)
{
	if (PersonneEstDejaPresente(p_personne) == false)
	{
		m_vMembres.push_back(p_personne.clone());
	}
	else
	{
		throw PersonneDejaPresenteException(p_personne.reqPersonneFormate());
	}

	INVARIANTS();
}

/**
 * \brief Retourne un unsigned int qui indique le nombre de personne présent dans l'annuaire
 * \return le nombre de personnes dans l'annuaire
 */
unsigned int Annuaire::reqNombrePersonne() const
{
	return (m_vMembres.size());
}

/**
 * \brief Vérifier si une personne est déja enregistrée dans l'annuaire
 * \param[in] p_personne Personne que l'on souhaite vérifier si elle est presente dans le vecteur
 * \return vrai ou faux si la personne est dans l'annuaire
 */
bool Annuaire::PersonneEstDejaPresente(const Personne& p_personne) const
{
	vector<Personne*>::const_iterator iter;
	for (iter = m_vMembres.begin(); iter != m_vMembres.end(); iter++)
	{
		if (*(*iter) == p_personne)
		{
			return true;
		}
	}
	return false;
}

/**
 * \brief Vérifier les invariants de la classe Annuaire
 */
void Annuaire::verifieInvariant() const
{
	INVARIANT(!(m_nomClub.empty()));
}

}



