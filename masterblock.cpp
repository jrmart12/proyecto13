#include "masterblock.h"

MasterBlock::MasterBlock(int tamanoBloques,int CantidadBloques)
{
    this->TamanoBloque=tamanoBloques;
    this->CantidadBloques=12;
    this->PrimerBloqueArchivo=2;
    this->SiguienteBloqueDisponible=2;
}

void MasterBlock::Cargar()
{
    /*this->Archivo->Abrir();
    char *data = Archivo->leer(0,BlockSize);
    Initfromchar(data);*/
}

void MasterBlock::Initfromchar(char * data)
{
    /*int pos=0;
    memcpy(this->TamanoBloque,&data[pos],4);
    pos+=4;
    memcpy(this->CantidadBloque,&data[pos],4);
    pos+=4;
    memcpy(this->PrimerBloqueArchivo,&data[pos],4);
    pos+=4;
    memcpy(this->SiguienteBloqueDisp,&data[pos],4);
    pos+=4;*/
}

