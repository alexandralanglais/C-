/**
 * \file PersonneDejaPresenteException.cpp
 * \brief Implémentation de la classe PersonneDejaPresenteException
 * \author Alexandra Langlais
 * \version 1.0
 * \date 21/04/2020
 */

#include "PersonneDejaPresenteException.h"

using namespace std;

PersonneDejaPresenteException::PersonneDejaPresenteException(const std::string& raison) :
		PersonneException(raison)
{
}
