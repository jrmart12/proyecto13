#include "fold.h"

fold::fold(string n, string d) : arch(n,d,1)
{
    l = new lista();
    cant = 0;
    itm2= new QTreeWidgetItem();
    ant = NULL;
    sig = NULL;
}

int fold::tip()
{
    return arch::t();
}

string fold::dir()
{
    return arch::d();
}


string fold::nom()
{
    return arch::n();
}
