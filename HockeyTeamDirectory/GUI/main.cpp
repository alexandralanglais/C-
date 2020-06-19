#include "annuairegui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnnuaireGUI w;
    w.show();
    return a.exec();
}
