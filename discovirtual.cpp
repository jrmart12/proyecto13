#include "discovirtual.h"

DiscoVirtual::DiscoVirtual()
{
    dv= new archivo("C:",5040);
    tamano=5040;
}

void DiscoVirtual::FileEntrytoChar(FileEntry f){

}
void DiscoVirtual::BloquetoChar(BloqueArchivo *b, int posi){
    char *data = new char[420];
    int pos = 0;

    memcpy(&data[pos], &b->primerbloque, 4);
    pos+=4;
    memcpy(&data[pos], b->BloqueArchtoChar(), 416);
    pos+=416;

    dv->Write(posi*420,data,420);
}
void DiscoVirtual::MasterBlocktoChar(MasterBlock *mb)
{
    char * data = new char[420];
    int pos = 0;

    memcpy(&data[pos], &mb->CantidadBloques, 4);
    pos+=4;
    memcpy(&data[pos], &mb->SiguienteBloqueDisponible,4);
    pos+=4;
    memcpy(&data[pos],&mb->PrimerBloqueArchivo, 4);
    pos+=4;

    dv->Write(0,data,420);

}
BloqueArchivo* DiscoVirtual::charToBloque(string nombre,int tamano,int primerbloque,int ultimobloque,int pos){
    BloqueArchivo * b = new BloqueArchivo(nombre,tamano,primerbloque,ultimobloque);
    memcpy(&b->primerbloque, dv->Read(pos*420,4), 4);
    pos+=4;
    memcpy(b->BloqueArchtoChar(),dv->Read(pos,416), 416);
    pos+=416;
    return b;
}
MasterBlock * DiscoVirtual::charToMasterBlock()
{
    MasterBlock *mb=new MasterBlock(420,12);
    int pos=0;
    memcpy(&mb->CantidadBloques,dv->Read(pos,4),4);
    pos+=4;
    memcpy(&mb->PrimerBloqueArchivo,dv->Read(pos,4),4);
    pos+=4;
    memcpy(&mb->SiguienteBloqueDisponible,dv->Read(pos,4),4);
    pos+=4;
    memcpy(&mb->TamanoBloque,dv->Read(pos,4),4);
    return mb;


}

FileEntry * DiscoVirtual::charToFileEntry()
{
    FileEntry *fe= new FileEntry("temp,",2,2,false,2);
    int pos=420;
      memcpy(&fe->nombre,dv->Read(pos,15),15);
      pos+=15;
      memcpy(&fe->EsONoFolder,dv->Read(pos,1),1);
      pos+=1;
      memcpy(&fe->TamanoArchivo,dv->Read(pos,4),4);
      return fe;


}

void DiscoVirtual::Formatear()
{
    MasterBlock *mb= new MasterBlock(420,12);
    BloqueArchivo *temp;
    for(int x=2;x<=12;x++){
        temp = new BloqueArchivo("",0,0,0);
        BloquetoChar(temp,x);
    }
    /*MasterBlock *mb = new MasterBlock(Bloque->tamaño,12,archivo *a);
    mb->Guardar();
    this->MasterBlock=mb;
    for(i=0;i<mb->CantidadBloque;i++){
        BloqueArchivo *ba=this->AsignarSiguienteBloque();
        ba->Guardar();
    }
    mb->SiguienteBloqueDisponible=1;
    mb->Guardar();*/
}

void DiscoVirtual::cargar()
{
    /*this->Archivo->abrir();
    this->MasterBlock = new MasterBlock(this->Archivo,TBloque);
    this->MasterBlock->Cargar();*/
}

void DiscoVirtual::ListarArchivosEnRaiz()
{
    /*List<FileEntry *> archivos = new List<FileEntry *>();
    if(MasterBlock->SiguienteBloqueDisponible==1){
        return archivos;
    }
    int BloqueArchivos=MasterBlock->PrimerBloqueArchivos;
    BloqueFolder *bf = new BloqueFolder("Raiz",numeroBloque,this->Archivo);
    bf->Cargar();
    return bf->ArchivoEntry();*/
}
