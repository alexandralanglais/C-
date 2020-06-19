/**
 * \file EntraineurTesteur.cpp
 * \brief Testeur de la classe Entraineur
 * \author Alexandra Langlais
 * \version 1.0
 * \date 23/03/2020
 */

#include "Entraineur.h"
#include <string>
#include <sstream>
#include <gtest/gtest.h>

using namespace std;
using namespace hockey;
using namespace util;


/**
 * \brief Test du constructeur Entraineur avec paramètres
 *  Cas valide:
 *  	Création d'un objet Entraineur et vérification de l'assignation de tous les attributs
 *  Cas invalides:
 *  	Prénom vide et avec chiffre
 *  	Nom vide et avec chiffre
 *  	Date invalide (entraineur mineur)
 *  	Numéro de téléphone invalide
 *  	Numéro de RAMQ invalide
 */
// Cas valide
TEST(Entraineur, Constructeur)
{
	Entraineur unEntraineur("Julien", "Claude", util::Date(23, 4, 1970), "514 526-8362", "JULC 7004 2322", 'M');

	ASSERT_EQ("Julien", unEntraineur.reqNom());
	ASSERT_EQ("Claude", unEntraineur.reqPrenom());
	ASSERT_EQ(util::Date(23, 4, 1970), unEntraineur.reqDateNaissance());
	ASSERT_EQ("514 526-8362", unEntraineur.reqTelephone());
	ASSERT_EQ("JULC 7004 2322", unEntraineur.reqNumRAMQ());
}
// Cas invalides
TEST(Entraineur, ConstructeurInvalideNom)
{
	ASSERT_THROW(Entraineur unEntraineur("123", "Claude", util::Date(23, 4, 1970), "514 526-8362", "JULC 7004 2322", 'M'),
			PreconditionException);
}
TEST(Entraineur, ConstructeurInvalidePrenom)
{
	ASSERT_THROW(Entraineur unEntraineur("Julien", "Cl234aude", util::Date(23, 4, 1970), "514 526-8362", "JULC 7004 2322", 'M'),
			PreconditionException);
}
TEST(Entraineur, ConstructeurInvalideDate)
{
	ASSERT_THROW(Entraineur unEntraineur("Julien", "Claude", util::Date(23, 4, 2018), "514 526-8362", "JULC 7004 2322", 'M'),
			PreconditionException);
}
TEST(Entraineur, ConstructeurInvalideTelephone)
{
	ASSERT_THROW(Entraineur unEntraineur("Julien", "Claude", util::Date(23, 4, 1970), "5145268362", "JULC 7004 2322", 'M'),
			PreconditionException);
}
TEST(Entraineur, ConstructeurInvalideRAMQ)
{
	ASSERT_THROW(Entraineur unEntraineur("Julien", "Claude", util::Date(23, 4, 1970), "514 526-8362", "JULC0042322", 'M'),
			PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Entraineur
 */
class EntraineurValide: public ::testing::Test
{
public:
	EntraineurValide():
		entraineur("Julien", "Claude", util::Date(23, 4, 1970), "514 526-8362", "JULC 7004 2322", 'M')
	{
	};

	Entraineur entraineur;
};

/**
 * \brief Test de la méthode reqNom()
 *  Cas valide:
 *  	Vérifier le retour du nom de l'entraineur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(EntraineurValide, reqNom)
{
	ASSERT_EQ("Julien", entraineur.reqNom());
}

/**
 * \brief Test de la méthode reqPrenom()
 *  Cas valide:
 *  	Vérifier le retour du prénom de l'entraineur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(EntraineurValide, reqPrenom)
{
	ASSERT_EQ("Claude", entraineur.reqPrenom());
}

/**
 * \brief Test de la méthode reqDateNaissance()
 *  Cas valide:
 *  	Vérifier le retour de la date de naissance de l'entraineur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(EntraineurValide, reqDateNaissance)
{
	ASSERT_EQ(util::Date(23, 4, 1970),entraineur.reqDateNaissance());
}

/**
 * \brief Test de la méthode reqTelephone()
 *  Cas valide:
 *  	Vérifier le retour du numéro de téléphone de l'entraineur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(EntraineurValide, reqTelephone)
{
	ASSERT_EQ("514 526-8362", entraineur.reqTelephone());
}

/**
 * \brief Test de la méthode reqNumRAMQ()
 *  Cas valide:
 *  	Vérifier le retour du numéro de RAMQ de l'entraineur
 *  Cas invalide:
 *  	Aucun
 */
TEST_F(EntraineurValide, reqNumRAMQ)
{
	ASSERT_EQ("JULC 7004 2322", entraineur.reqNumRAMQ());
}

/**
 * \brief Test de la méthode reqPersonneFormate()
 * 	Cas valide:
 * 		Vérifier le retour des informations sur l'objet Entraineur
 * 	Cas invalide:
 * 		Aucun
 */
TEST_F(EntraineurValide, reqPersonneFormate)
{
	ostringstream os;

	os << "Nom :               Julien" << endl;
	os << "Prenom :            Claude" << endl;
	os << "Date de naissance : " << entraineur.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone :         514 526-8362" << endl;
	os << "Numero de RAMQ :    JULC 7004 2322" << endl;
	os << "---------------------" << endl;

	ASSERT_EQ(os.str(), entraineur.reqPersonneFormate());
}

/**
 * \brief Test de la méthode clone()
 *  Cas valides:
 *  	Vérifier la copie d'un objet avec la méthode clone()
 *  Cas invalides:
 *  	Aucun
 */
TEST_F(EntraineurValide, clone)
{
	Personne* clone = entraineur.clone();
	ASSERT_EQ(entraineur.reqPersonneFormate(), clone->reqPersonneFormate());
}
