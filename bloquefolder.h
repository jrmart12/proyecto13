#ifndef BLOQUEFOLDER_H
#define BLOQUEFOLDER_H
#include <list>
#include "fileentry.h"
#include <stdio.h>
#include "archivo.h"



class BloqueFolder
{
public:
    BloqueFolder(string nombre, int capacidad, int tamano, int siguientebloque, int pos);
    string nombre;
    int capacidad;
    int tamano;
    int numero;
    int siguientebloque;
    list <FileEntry> FE;
    char * bloquetochar();
    void InitFromChar(char * info);
    archivo *arch;
};

#endif // BLOQUEFOLDER_H
