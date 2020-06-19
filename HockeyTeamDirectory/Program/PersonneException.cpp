/**
 * \file PersonneException.cpp
 * \brief Implémentation de la classe PersonneException
 * \author Alexandra Langlais
 * \version 1.0
 * \date 21/04/2020
 */

#include "PersonneException.h"

using namespace std;

PersonneException::PersonneException(const std::string& raison) :
		runtime_error(raison)
{
}

