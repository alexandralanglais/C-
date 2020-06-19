#include "annuairegui.h"
#include "Joueur.h"

AnnuaireGUI::AnnuaireGUI(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
}

AnnuaireGUI::~AnnuaireGUI()
{

}

void AnnuaireGUI::ajouterJoueur(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
		const std::string& p_telephone, const std::string p_position){
	hockey::Joueur joueur(p_nom, p_prenom, p_dateNaissance, p_telephone, p_position);
	m_vMembres.push_back(new hockey::Joueur(joueur));
}
