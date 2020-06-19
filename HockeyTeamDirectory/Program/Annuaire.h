/**
 * \file Annuaire.h
 * \brief Programme qui declare la classe Annuaire
 * \author Alexandra Langlais
 * \version 1.0
 * \date 02/03/2020
 */


#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_

#include "Joueur.h"
#include "Entraineur.h"
#include "ContratException.h"
#include "PersonneException.h"
#include "PersonneDejaPresenteException.h"
#include <vector>

namespace hockey
{

/**
 * \class Annuaire
 * \brief Classe qui contient les joueurs et les entraineurs d'une équipe.
 * 		  Elle contient le nom du club de hockey.
 *		  Elle contient une méthode qui permet d'afficher l'annuaire formaté.
 *		  Attributs: std::string m_nomClub: un string contenant le nom du club.
 *		  			 std::vector<Personne*> m_vMembres: un vecteur qui contient tous les membres (joueurs et entraineurs).
 */
class Annuaire
{
public:
	Annuaire(const std::string p_nomClub);
	~Annuaire();

	std::string reqNomClub() const;
	std::string reqAnnuaireFormate() const;

	void ajouterPersonne (const Personne& p_personne);
	unsigned int reqNombrePersonne() const;


private:
	Annuaire(const Annuaire&);
	Annuaire& operator=(const Annuaire&);
	std::string m_nomClub;
	std::vector<Personne*> m_vMembres;
	bool PersonneEstDejaPresente(const Personne& p_personne) const;

	void verifieInvariant() const;


};
}



#endif /* ANNUAIRE_H_ */
