/**
 * \file AnnuaireTesteur.cpp
 * \brief Testeur de la classe Annuaire
 * \author Alexandra Langlais
 * \version 1.0
 * \date 23/03/2020
 */

#include "Annuaire.h"
#include "ContratException.h"
#include "PersonneDejaPresenteException.h"
#include <string>
#include <gtest/gtest.h>

using namespace std;
using namespace hockey;
using namespace util;

/**
 * \brief Test du constructeur Annuaire
 * 	Cas valide:
 * 		Création d'un objet Annuaire avec un nom de club valide
 * 	Cas invalde:
 * 		Nom du club invalide
 */
// Cas valide
TEST(Annuaire, Constructeur)
{
	string nomClub = "Club";
	Annuaire annuaire(nomClub);
	ASSERT_EQ(nomClub, annuaire.reqNomClub());
}
// Cas invalide
TEST(Annuaire, ConstructeurInvalide)
{
	string nomClub = "";
	ASSERT_THROW(Annuaire annuaire(nomClub), PreconditionException);
}

/**
 * \brief Test de la méthode ajouterPersonne()
 * Cas valides:
 * 		Création d'un objet Annuaire avec un nom de club valide et ajout d'une personne
 */
TEST(Annuaire, ajouterPersonne)
{
	string nomClub = "Club";
	string nomJoueur = "Langlais";
	string prenomJoueur = "Alexandra";
	Date dateNaissanceJoueur = Date(5, 5, 2004);
	string telephoneJoueur = "418 456-4567";
	string positionJoueur = "CENTRE";

	Joueur unJoueur(nomJoueur,prenomJoueur, dateNaissanceJoueur, telephoneJoueur, positionJoueur);

	Annuaire annuaire(nomClub);

	annuaire.ajouterPersonne(unJoueur);

	ASSERT_EQ(1, annuaire.reqNombrePersonne());
};

/**
 * \brief Test fixture pour les méthodes de la classe Annuaire
 */
class AnnuaireValide: public ::testing::Test
{
public:
    string nomClub = "Canadiens de Montréal";

	// Joueur
	string nomJoueur = "Price";
	string prenomJoueur = "Carey";
	Date dateNaissanceJoueur = Date(16, 8, 2004);
	string telephoneJoueur = "514 654-8765";
	string positionJoueur = "DEFENSEUR";

	// Entraineur
	string nomEntraineur = "Julien";
	string prenomEntraineur = "Claude";
	Date dateNaissanceEntraineur = Date(23, 4, 1970);
	string telephoneEntraineur = "514 526-8362";
	char sexeEntraineur = 'M';
	string RAMQEntraineur = "JULC 7004 2322";


	AnnuaireValide() :
			annuaire("Canadiens de Montréal")
	{
		annuaire.ajouterPersonne(
				Joueur(nomJoueur, prenomJoueur, dateNaissanceJoueur, telephoneJoueur, positionJoueur));
		annuaire.ajouterPersonne(
				Entraineur(nomEntraineur, prenomEntraineur, dateNaissanceEntraineur,
						telephoneEntraineur, RAMQEntraineur, sexeEntraineur));
	};

	Annuaire annuaire;
};

/**
 * \brief Test de la méthode reqNomClub()
 *  Cas valide:
 * 		Vérifier le retour du nom du club
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(AnnuaireValide, reqNomClub)
{
	ASSERT_EQ(nomClub, annuaire.reqNomClub());
};

/**
 * \brief Test de la méthode reqAnnuaireFormate()
 * 	Cas valide:
 * 		Vérifier le retour des informations sur l'objet Annuaire
 * 	Cas invalide:
 * 		Aucun
 */
TEST_F(AnnuaireValide, reqAnnuaireFormate)
{
	ostringstream os;
	os << "Club : " << annuaire.reqNomClub() << endl;
	os << "---------------------" << endl;
	os << Joueur(nomJoueur, prenomJoueur, dateNaissanceJoueur, telephoneJoueur, positionJoueur).reqPersonneFormate();
	os << Entraineur(nomEntraineur, prenomEntraineur, dateNaissanceEntraineur, telephoneEntraineur, RAMQEntraineur, sexeEntraineur).reqPersonneFormate();

	ASSERT_EQ(os.str(), annuaire.reqAnnuaireFormate());
}

/**
 * \brief Test de la méthode PersonneEstDejaPresente()
 * Cas invalide:
 * 		Une personne est deja dans le vecteur
 */
TEST_F(AnnuaireValide, personneEstDejaPresente)
{
	EXPECT_THROW(annuaire.ajouterPersonne(
					Joueur(nomJoueur, prenomJoueur, dateNaissanceJoueur, telephoneJoueur, positionJoueur)), PersonneDejaPresenteException);
};
