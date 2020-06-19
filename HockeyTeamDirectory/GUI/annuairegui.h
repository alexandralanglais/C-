#ifndef ANNUAIREGUI_H
#define ANNUAIREGUI_H

#include <QtGui/QWidget>
#include "ui_annuairegui.h"
#include "Annuaire.h"

class AnnuaireGUI : public QWidget
{
    Q_OBJECT

public:
    AnnuaireGUI(QWidget *parent = 0);
    ~AnnuaireGUI();
    void ajouterJoueur(const std::string p_nom, const std::string p_prenom, const util::Date p_dateNaissance,
			const std::string& p_telephone, const std::string p_position);

private:
    Ui::AnnuaireGUIClass ui;
    std::vector<hockey::Personne*> m_vMembres;
    // ou l'autre???
    //hockey::Annuaire annuaire;
};

#endif // ANNUAIREGUI_H
