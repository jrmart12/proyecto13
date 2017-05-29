#include "bloquefolder.h"

BloqueFolder::BloqueFolder(string nombre, int capacidad, int tamano, int siguientebloque, int numero)
{
    this->nombre=nombre;
    this->capacidad=capacidad;
    this->tamano=tamano;
    this->siguientebloque=siguientebloque;
    this->numero=numero;

}

char* BloqueFolder::bloquetochar()
{

    int tam=20+strlen(nombre);
    int pos=0;
    for(list<FileEntry>::iterator l=FE.begin();l!=FE.end();l++)
    {
        FileEntry temp=*l;
        tam += (strlen(temp.getnombre())+20);
    }
    char *datos=new char[tam];
    memcpy(&datos[pos],strlen(this->nombre.c_str()),4);
    pos+=4;
    memcpy(&datos[pos], nombre.c_str(), strlen(nombre.c_str()));
    pos+=strlen(this->nombre);
    memcpy(&datos[pos],&capacidad,4);
    pos+=4;
    memcpy(&datos[pos],&tamano,4);
    pos+=4;
    memcpy(&datos[pos],&siguientebloque,4);
    pos+=4;
    memcpy(&datos[pos],&numero,4);
    pos+=4;

    for(list<FileEntry>::iterator l=FE.begin();l!=FE.end();l++)
    {
        FileEntry temp=*l;
        memcpy(&datos[pos],strlen(temp.getnombre().c_str()),4);
        pos+=4;
        memcpy(&datos[pos], temp.nombre.c_str(), strlen(temp.nombre.c_str()));
        pos+=strlen(temp.nombre.c_str());
        memcpy(&datos[pos], temp.empieza,4);
        pos+=4;
        memcpy(&datos[pos], temp.termina,4);
        pos+=4;
        memcpy(&datos[pos], temp.EsONoFolder,4);
        pos+=4;
        memcpy(&datos[pos], temp.TamanoArchivo,4);
        pos+=4;

    }
}

void BloqueFolder::InitFromChar(char * datos)
{  int pos=0;
    int tamNombre = 0;
    memcpy(this->nombre.c_str(),&datos[pos],4);
    pos+=4;
    memcpy(&datos[pos], nombre.c_str(), strlen(nombre.c_str()));
    pos+=strlen(this->nombre.c_str());
    memcpy(&datos[pos],&capacidad,4);
    pos+=4;
    memcpy(&datos[pos],&tamano,4);
    pos+=4;
    memcpy(&datos[pos],&siguientebloque,4);
    pos+=4;
    memcpy(&datos[pos],&numero,4);
    pos+=4;
}
