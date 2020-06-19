/**
 * \file PersonneTesteur.cpp
 * \brief Testeur de la classe Personne
 * \author Alexandra Langlais
 * \version 1.0
 * \date 23/03/2020
 */

#include "Personne.h"
#include <gtest/gtest.h>

using namespace hockey;
using namespace util;
using namespace std;

/**
 * \brief Création d'une fixture à utiliser pour les méthodes publiques de la classe de Personne virtuelle pure
 */
class unePersonne: public Personne
{
public:
	unePersonne(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
			const string& p_telephone) :
			Personne(p_nom, p_prenom, p_dateNaissance, p_telephone)
	{
	};
	virtual unePersonne* clone() const
	{
		return unePersonne::clone();
	}
};

/**
 * \brief Test du constructeur Personne
 *  Cas valide:
 *  	Création d'un objet Personne et vérification de tous les attributs
 *  Cas invalides:
 *  	Nom invalide
 *  	Prénom invalide
 *  	Numéro de téléphone invalide
 *  	Date de naissance invalide
 */
// Cas valide
TEST(Personne, Constructeur)
{
	unePersonne personne("Langlais", "Alexandra", util::Date(14, 4, 1994), "418 123-4567");

	ASSERT_EQ("Langlais", personne.reqNom());
	ASSERT_EQ("Alexandra", personne.reqPrenom());
	ASSERT_EQ(util::Date(14, 4, 1994), personne.reqDateNaissance());
	ASSERT_EQ("418 123-4567", personne.reqTelephone());
}
// Cas invalides
TEST(Personne,ConstructeurInvalideNom)
{
	ASSERT_THROW(unePersonne personne("123", "Alexandra", util::Date(14, 4, 1994), "418 123-4567"),
			PreconditionException);
}
TEST(Personne,ConstructeurInvalidePrenom)
{
	ASSERT_THROW(unePersonne personne("Langlais", "123", util::Date(14, 4, 1994), "418 123-4567"),
			PreconditionException);
}
TEST(Personne,ConstructeurInvalideDate)
{
	ASSERT_THROW(unePersonne personne("Langlais", "Alexandra", util::Date(14, 4, 1800), "418 123-4567"),
			PreconditionException);
}
TEST(Personne,ConstructeurInvalideTelephone)
{
	ASSERT_THROW(unePersonne personne("Langlais", "Alexandra", util::Date(14, 4, 1994), "418234567"),
			PreconditionException);
}

/**
 * \brief Test de la surcharge operator==
 *  Cas valide:
 *  	Création de deux objets Personne et vérification de la surcharge ==
 *  Cas invalide:
 *  	Les objets ne sont pas égaux
 */
// Cas valide
TEST(Personne, Operator)
{
	unePersonne personne("Langlais", "Alexandra", util::Date(14, 4, 1994), "418 123-4567");
	unePersonne personne2("Langlais", "Alexandra", util::Date(14, 4, 1994), "418 123-4567");

	ASSERT_EQ(true, personne==personne2);
}
// Cas invalide
TEST(Personne, OperatorInvalide)
{
	unePersonne personne("Langlais", "Alexandra", util::Date(14, 4, 1994), "418 123-4567");
	unePersonne personne2("Langlois", "Alexandra", util::Date(14, 4, 1994), "418 123-4567");

	ASSERT_EQ(false, personne==personne2);
}

/**
 * \brief Test fixture pour les méthodes de la classe Personne
 */
class PersonneValide: public ::testing::Test
{
public:
	PersonneValide() :
			personneTest("Langlais", "Marie", Date(12, 9, 1997), "418 211-1166")
	{
	};

protected:
	string nomPersonne;
	string prenomPersonne;
	Date dateNaissancePersonne;
	string telephonePersonne;

	unePersonne personneTest;

	virtual void SetUp()
	{
		nomPersonne = "Langlais";
		prenomPersonne = "Alexandra";
		dateNaissancePersonne = Date(14, 4, 1994);
		telephonePersonne = "418 123-4567";
		personneTest = unePersonne(nomPersonne, prenomPersonne, dateNaissancePersonne, telephonePersonne);
	}

	virtual void TearDown()
	{
	}
};

/**
 * \brief Test de la méthode reqPersonneFormate()
 *  Cas valide:
 *  	Vérifier le retour des informations de la personne
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(PersonneValide, reqPersonneFormate)
{
	ostringstream os;

	os << "Nom :               Langlais" << endl;
	os << "Prenom :            Alexandra" << endl;
	os << "Date de naissance : " << personneTest.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone :         418 123-4567" << endl;

	ASSERT_EQ(os.str(), personneTest.reqPersonneFormate());
}

