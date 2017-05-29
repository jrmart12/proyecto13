#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H


class MasterBlock
{
public:
    MasterBlock(int tamanoBloques,int CantidadBloques);
    void Cargar();
    MasterBlock *charToMasterBlock(char *data);
    char *MasterBlockToChar();
    void Guardar();
    void Initfromchar(char *data);
    int TamanoBloque;
    int CantidadBloques;
    int PrimerBloqueArchivo;
    int SiguienteBloqueDisponible;
};

#endif // MASTERBLOCK_H
