
/**
 * \file validationFormat.h
 * \brief Programme qui contient les fonctions de validations
 * \author Alexandra Langlais
 * \version 1.0
 * \date 20/01/2020
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util
{

bool validerTelephone(const std::string& p_telephone);

bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom,
		const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);

bool validerFormatNom(const std::string& p_nom);
}

#endif /* VALIDATIONFORMAT_H_ */
