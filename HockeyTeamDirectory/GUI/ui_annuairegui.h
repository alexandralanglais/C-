/********************************************************************************
** Form generated from reading UI file 'annuairegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNUAIREGUI_H
#define UI_ANNUAIREGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnuaireGUIClass
{
public:

    void setupUi(QWidget *AnnuaireGUIClass)
    {
        if (AnnuaireGUIClass->objectName().isEmpty())
            AnnuaireGUIClass->setObjectName(QString::fromUtf8("AnnuaireGUIClass"));
        AnnuaireGUIClass->resize(400, 300);

        retranslateUi(AnnuaireGUIClass);

        QMetaObject::connectSlotsByName(AnnuaireGUIClass);
    } // setupUi

    void retranslateUi(QWidget *AnnuaireGUIClass)
    {
        AnnuaireGUIClass->setWindowTitle(QApplication::translate("AnnuaireGUIClass", "AnnuaireGUI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnnuaireGUIClass: public Ui_AnnuaireGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNUAIREGUI_H
