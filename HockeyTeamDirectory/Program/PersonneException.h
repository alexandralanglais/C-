/**
 * \file PersonneException.h
 * \brief Programme qui declare la classe PersonneException
 * \author Alexandra Langlais
 * \version 1.0
 * \date 21/04/2020
 */


#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_

#include <string>
#include <stdexcept>

/**
 * \class PersonneException
 * \brief Classe qui permet de gérer les exceptions liées aux personnes.
 */
class PersonneException: public std::runtime_error
{
public:
	PersonneException(const std::string& raison);
};



#endif /* PERSONNEEXCEPTION_H_ */
