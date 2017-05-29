#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include "archivo.h"


class BloqueArchivo
{
public:
    BloqueArchivo(string nombre,int tamano, int primerbloque,int ultimobloque);
    int nombre;
    int tamano;
    int primerbloque;
    int ultimobloque;
    archivo *arch;
    void InitFromChar(char * info);
    char * BloqueArchtoChar();
    void Guardar();

};

#endif // BLOQUEARCHIVO_H
