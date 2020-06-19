/**
 * \file PersonneDejaPresenteException.h
 * \brief Programme qui declare la classe PersonneDejaPresenteException
 * \author Alexandra Langlais
 * \version 1.0
 * \date 21/04/2020
 */

#ifndef PERSONNEDEJAPRESENTEEXCEPTION_H_
#define PERSONNEDEJAPRESENTEEXCEPTION_H_

#include "PersonneException.h"
#include <string>

/**
 * \class PersonneDejaPresenteException
 * \brief Classe pour la gestion de l'exception de l'ajout d'un doublon de personne dans la liste des inscrits.
 */

class PersonneDejaPresenteException: public PersonneException
{
public:
	PersonneDejaPresenteException(const std::string& raison);
};


#endif /* PERSONNEDEJAPRESENTEEXCEPTION_H_ */
