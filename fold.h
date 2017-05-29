#ifndef FOLDER_H
#define FOLDER_H
#include "arch.h"
#include "lista.h"
#include <QtWidgets>
class fold: public arch
{
public:
    fold(string n, string d);
    lista *l;
    int cant;
    string nom();
    string dir();
    int tip();
    fold * ant;
    fold * sig;
    QTreeWidgetItem *itm2;
};

#endif // FOLDER_H
