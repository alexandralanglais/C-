/**
 * \file validationFormat.cpp
 * \brief Programme qui valide les numéros de téléphone, de RAMQ et le nom de la personne
 * \author Alexandra Langlais
 * \version 1.0
 * \date 20/01/2020
 */

#include "validationFormat.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

namespace util
{

/*
 * \brief Fonction qui vérifie si un numéro de téléphone entré est valide selon son indicatif régional,
 * 		  s'il comporte que des chiffres et possède un espace et un tiret aux bons endroits.
 * \param[in] p_telephone un string qui représente un numéro de téléphone que l'on veut vérifier
 * \return un booléen qui indique si le numéro de téléphone entré est valide
 */
bool validerTelephone(const std::string& p_telephone)
{
	if (p_telephone.length() != 12)
	{
		return false;
	}
	else
	{
		// string pour y entrer les paramètres fournis
		std::ostringstream numTel;

		string indicatifsRegionaux[58] = {"403", "780", "604", "236", "250", "778", "902", "204", "506", "431",
			"905", "519", "289", "705", "613", "807", "416", "647", "438", "514", "450", "579", "418", "581",
			"819", "873", "306", "709", "867", "800", "866", "877", "888", "855", "900", "976", "822", "833",
			"844", "880", "881", "882", "883", "884", "885", "886", "887", "889", "587", "825", "672", "226",
			"249", "343", "365", "437", "367", "966"};

		for (int i = 0; i < 58; i++)
		{
			if (indicatifsRegionaux[i] == p_telephone.substr(0, 3))
			{
				numTel << indicatifsRegionaux[i];
			}
		}

		// Vérification que le numéro de téléphone est composé de chiffres seulement
		if (not isdigit(p_telephone[4]))
		{
			return false;
		}
		if (not isdigit(p_telephone[5]))
		{
			return false;
		}
		if (not isdigit(p_telephone[6]))
		{
			return false;
		}
		if (not isdigit(p_telephone[8]))
		{
			return false;
		}
		if (not isdigit(p_telephone[9]))
		{
			return false;
		}
		if (not isdigit(p_telephone[10]))
		{
			return false;
		}
		if (not isdigit(p_telephone[11]))
		{
			return false;
		}

		// Espace au 4e caractère
		numTel << " ";


		// Insertion des chiffres du numéro de téléphone
		numTel << p_telephone[4];
		numTel << p_telephone[5];
		numTel << p_telephone[6];

		// Tiret au 8e caractère
		numTel << "-";

		// Insertion des chiffres du numéro de téléphone
		numTel << p_telephone[8];
		numTel << p_telephone[9];
		numTel << p_telephone[10];
		numTel << p_telephone[11];

		// Conversion du streamstring en string
		string verificationNumTel = numTel.str();

		// Vérifier que verificationNumRAMQ est équivalent à p_numero
		for (int y = 0; y <= 11; y++)
		{
			if (verificationNumTel[y] != p_telephone[y])
			{
					return false;
			}
		}
		return true;
	}
	return true;
}

/*
 * \brief Fonction qui vérifie que les paramètres entrés du numéro RAMQ sont valides
 * \param[in] p_numero un string qui représente le numéro de RAMQ que le programme doit valider
 * \param[in] p_nom un string qui représente le nom de la personne
 * \param[in] p_prenom un string qui représente le prénom de la personne
 * \param[in] p_jourNaissance un entier qui représente le jour de la date de naissance de la personne
 * \param[in] p_moisNaissance un entier qui représente le mois de la date de naissance de la personne
 * \param[in] p_anneeNaissance un entier qui représente l'année de la date de naissance de la personne
 * \param[in] p_sex un caractère qui représente si la personne est de sex masculin ou féminin
 * \return un booléen qui indique si le numéro RAMQ entré est valide
 */
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom,
		const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex)
{
	if (p_numero.length() != 14)
	{
		return false;
	}
	else
	{
		// string pour y entrer les paramètres fournis
		std::ostringstream numRAMQ_ss;


		// 3 premières lettres du nom
		for (int x = 0; x < 3; ++x)
		{
		    // Création d'un string pour le convertir en char
            std::string stringToChar;
            stringToChar = toupper(p_nom[x]);
            const char * c_nom = stringToChar.c_str();
            numRAMQ_ss << c_nom;
		}

		// Première lettre du prénom
		// Création d'un string pour le convertir en char,
        std::string stringToChar;
        stringToChar = toupper(p_prenom[0]);
        const char * c_prenom = stringToChar.c_str();
        numRAMQ_ss << c_prenom;

        // Espace au 4e caractère
		numRAMQ_ss << " ";

		// 2 derniers chiffres de l'année de naissance
		if ((p_anneeNaissance % 100) < 10)
		{
			numRAMQ_ss << 0 << (p_anneeNaissance % 100);
		}
		else
		{
			numRAMQ_ss << (p_anneeNaissance % 100);
		}

		// Mois de naissance homme
		if (toupper(p_sex) == 'M')
		{
			if (p_moisNaissance < 10)
			{
				numRAMQ_ss << 0 << p_moisNaissance;
			}
			else
			{
				numRAMQ_ss << p_moisNaissance;
			}
		}

		// Mois de naissance femme
		if (toupper(p_sex) == 'F')
		{
			numRAMQ_ss << (p_moisNaissance + 50);
		}

		// Espace au 9e caractère
		numRAMQ_ss << " ";

		// Jour de naissance
		if (p_jourNaissance < 10)
		{
			numRAMQ_ss << 0 << p_jourNaissance;
		}
		else
		{
			numRAMQ_ss << p_jourNaissance;
		}

		// Conversion du streamstring en string
		string verificationNumRAMQ = numRAMQ_ss.str();

		// Vérifier que verificationNumRAMQ est équivalent à p_numero
		for (int y = 0; y < 12; ++y)
		{
			if (verificationNumRAMQ[y] != p_numero[y])
			{
				return false;
			}
		}
		return true;
	}
	return true;
}

/*
 * \brief Fonction qui vérifie si un nom entré est valide,
 *        c'est-à-dire que tous ses caractères soient des lettres.
 * \param[in] p_nom un string qui représente le nom d'une personne
 * \return un booléen qui indique si le format du nom entré est valide
 */
bool validerFormatNom(const std::string& p_nom)
{
	if (p_nom.length() == 0)
	{
		return false;
	}
	else
	{
		// Utilisation de regex pour accepter un '-' dans un prénom/nom
		regex regex_str("^[a-zA-Z-]*$");
		smatch match;

		// Je ne comprends pas pourquoi mon regex_search a des arguments invalides alors qu'il fonctionne bien
		if (regex_search(p_nom, match, regex_str) == false)
		{
			return false;
		}
	}
	return true;
	}
}

