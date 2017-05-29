#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <iostream>
#include <string>
using namespace std;


class FileEntry
{
public:
    FileEntry(string nombre, int empieza, int termina, int folder, int tamano);
    string nombre;
    int empieza;
    int termina;
    //MasterBlock BloqueActual;
     bool EsONoFolder;
     int TamanoArchivo;
     string getnombre();
     int getinicio();
     int getfinal();
     int EsFolder();
     int gettamano();

};

#endif // FILEENTRY_H
