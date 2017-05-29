#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "arch.h"
#include "txt.h"
#include "lista.h"
#include "fold.h"
#include "archivo.h"
#include "discovirtual.h"
#include "fileentry.h"
#include <qlist.h>

class archivo;
class func
{
public:
    func();
    fold *r;
    int eliminar(int p,fold *d);
    arch *Crear(fold * d, string n,string t);
    void Copiar(string o, string a,string d);
    arch * buscar(int p,fold * d);
    void agregar(arch * n, fold * d);
    arch * Cargar(int p,fold *d);
    QList<arch*> Listar(fold *d);
    void pegar(arch * n,fold *d);
    void CrearDiscoVirtual();

    DiscoVirtual *disco;
};

#endif // FUNCIONES_H
