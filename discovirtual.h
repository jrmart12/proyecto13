#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include <iostream>
#include <string>
#include "archivo.h"
#include "fileentry.h"
#include "masterblock.h"
#include "bloquearchivo.h"
using namespace std;
class archivo;



class DiscoVirtual
{
    public:
        DiscoVirtual();
        void Formatear();
        void cargar();
        void ListarArchivosEnRaiz();
        void FileEntrytoChar(FileEntry f);
        void BloquetoChar(BloqueArchivo *b, int posi);
        void MasterBlocktoChar(MasterBlock *mb);
        MasterBlock * charToMasterBlock();
        FileEntry * charToFileEntry();
        BloqueArchivo * charToBloque(string nombre,int tamano,int primerbloque,int ultimobloque,int pos);
        int tamano;
        archivo *dv;
        int tamanoBloques;
    protected:

    private:

};

#endif // DISCOVIRTUAL_H
