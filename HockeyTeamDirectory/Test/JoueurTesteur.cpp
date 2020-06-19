/**
 * \file JoueurTesteur.cpp
 * \brief Testeur de la classe Joueur
 * \author Alexandra Langlais
 * \version 1.0
 * \date 25/03/2020
 */

#include "Joueur.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace hockey;
using namespace std;
using namespace util;

/**
 * \brief Test du constructeur Joueur avec paramètres
 *  Cas valide:
 *  	Création d'un objet Joueur et vérification de l'assignation de tous les attributs
 *  Cas invalides:
 *  	Prénom vide et avec chiffre
 *  	Nom vide et avec chiffre
 *  	Date invalide (joueur pas entre 15 et 17 ans)
 *  	Numéro de téléphone invalide
 *  	Position invalide
 */
// Cas valide
TEST(Joueur, Constructeur)
{
	Joueur unJoueur("Price", "Carey", util::Date(16, 8, 2004), "514 654-8765", "DEFENSEUR");

	ASSERT_EQ("Price", unJoueur.reqNom());
	ASSERT_EQ("Carey", unJoueur.reqPrenom());
	ASSERT_EQ(util::Date(16, 8, 2004), unJoueur.reqDateNaissance());
	ASSERT_EQ("514 654-8765", unJoueur.reqTelephone());
	ASSERT_EQ("DEFENSEUR", unJoueur.reqPosition());
}
// Cas invalides
TEST(Joueur, ConstructeurInvalideNom)
{
	ASSERT_THROW(Joueur unJoueur("", "Carey", util::Date(16, 8, 2004), "514 654-8765", "DEFENSEUR"),
			PreconditionException);
}
TEST(Joueur, ConstructeurInvalidePrenom)
{
	ASSERT_THROW(Joueur unJoueur("Price", "", util::Date(16, 8, 2004), "514 654-8765", "DEFENSEUR"),
			PreconditionException);
}
TEST(Joueur, ConstructeurInvalideDate)
{
	ASSERT_THROW(Joueur unJoueur("Price", "Carey", util::Date(16, 8, 1900), "514 654-8765", "DEFENSEUR"),
			PreconditionException);
}
TEST(Joueur, ConstructeurInvalideTelephone)
{
	ASSERT_THROW(Joueur unJoueur("Price", "Carey", util::Date(16, 8, 2004), "51454-8765", "DEFENSEUR"),
			PreconditionException);
}
TEST(Joueur, ConstructeurInvalidePosition)
{
	ASSERT_THROW(Joueur unJoueur("Price", "Carey", util::Date(16, 8, 2004), "514 654-8765", "attack"),
			PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Joueur
 */
class JoueurValide: public ::testing::Test
{
public:
	JoueurValide():
		joueur("Price", "Carey", util::Date(16, 8, 2004), "514 654-8765", "DEFENSEUR")
	{
	};

	Joueur joueur;
};

/**
 * \brief Test de la méthode reqNom()
 *  Cas valide:
 *  	Vérifier le retour du nom du joueur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(JoueurValide, reqNom)
{
	ASSERT_EQ("Price", joueur.reqNom());
}

/**
 * \brief Test de la méthode reqPrenom()
 *  Cas valide:
 *  	Vérifier le retour du prénom du joueur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(JoueurValide, reqPrenom)
{
	ASSERT_EQ("Carey", joueur.reqPrenom());
}

/**
 * \brief Test de la méthode reqDateNaissance()
 *  Cas valide:
 *  	Vérifier le retour de la date de naissance du joueur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(JoueurValide, reqDateNaissance)
{
	ASSERT_EQ(util::Date(16, 8, 2004),joueur.reqDateNaissance());
}

/**
 * \brief Test de la méthode reqTelephone()
 *  Cas valide:
 *  	Vérifier le retour du numéro de téléphone du joueur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(JoueurValide, reqTelephone)
{
	ASSERT_EQ("514 654-8765", joueur.reqTelephone());
}

/**
 * \brief Test de la méthode reqPosition()
 *  Cas valide:
 *  	Vérifier le retour de la position du joueur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(JoueurValide, reqPosition)
{
	ASSERT_EQ("DEFENSEUR", joueur.reqPosition());
}

/**
 * \brief Test de la méthode reqPersonneFormate()
 * 	Cas valide:
 * 		Vérifier le retour des informations sur l'objet Joueur
 * 	Cas invalide:
 * 		Aucun
 */
TEST_F(JoueurValide, reqPersonneFormate)
{
	ostringstream os;

	os << "Nom :               Price" << endl;
	os << "Prenom :            Carey" << endl;
	os << "Date de naissance : " << joueur.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone :         514 654-8765" << endl;
	os << "Position :          DEFENSEUR" << endl;
	os << "---------------------" << endl;

	ASSERT_EQ(os.str(), joueur.reqPersonneFormate());
}

/**
 * \brief Test de la méthode clone()
 *  Cas valides:
 *  	Vérifier la copie d'un objet avec la méthode clone()
 *  Cas invalides:
 *  	Aucun
 */
TEST_F(JoueurValide, clone)
{
	Personne* clone = joueur.clone();
	ASSERT_EQ(joueur.reqPersonneFormate(), clone->reqPersonneFormate());
}
