#include "fileentry.h"

FileEntry::FileEntry(string nombre, int empieza, int termina, int folder, int tamano)
{
    this->nombre=nombre;
    this->empieza=empieza;
    this->termina=termina,
    this->EsONoFolder=folder;
    this->TamanoArchivo=tamano;

}

string FileEntry::getnombre()
{
    return nombre;
}

int FileEntry::getinicio()
{
    return empieza;
}

int FileEntry::getfinal()
{
    return termina;
}

int FileEntry::EsFolder()
{
    return EsONoFolder;
}

int FileEntry::gettamano()
{
    return TamanoArchivo;
}
