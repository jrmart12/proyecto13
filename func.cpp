#include "func.h"

func::func()
{
    r = new fold("Raiz","Raiz");
    disco = new DiscoVirtual();
    disco->Formatear();

}

int func::eliminar(int p,fold *d)
{
    arch *algo = buscar(p,d);
    if(algo == NULL)
        return -1;
    if(d->l->i== algo){
        d->l->i = algo->sig;
        d->cant--;
    }
    else if(algo->sig== NULL){
        arch * algo2 = algo->ant;
        algo2->sig =NULL;
        d->cant--;
    }
    else{
        arch *temporal = algo->sig;
        arch *temporal2 = algo->ant;
        temporal2->sig = temporal;
        temporal->ant = temporal2;
        d->cant--;
    }
    return 0;


}

arch *func::Cargar( int p,fold * d)
{
    arch *algo = d->l->i;
    for(int x = 0;x<p;x++)
    {
        algo = algo->sig;
    }

    //char *data=disco->MasterBlocktoChar();

    //this->disco->dv->leer();
    return algo;
}


arch * func::buscar(int p, fold *d)
{
    arch * algo = d->l->i;
    for(int x = 0;x<p;x++)
    {
        algo = algo->sig;
    }
    return algo;
}

arch * func::Crear(fold *d,string nom,string t)
{
    arch *n;
    string dir;

    if(t == "archivo"){
        dir = d->dir() +nom + ".txt"+"/";
        n = new txt(nom,dir,"");
    }

    else if(t == "folder"){
        dir = d->dir() + nom+ "/" ;
        n = new fold(nom,dir);
    }

    agregar(n,d);
    return n;
}

void func::agregar(arch *n,fold *d)
{
    if(d->l->i == NULL){
        d->l->i = n;
        d->cant++;
    }
    else
    {
        arch * t = d->l->i;
        while(t->sig != NULL)
            t = t->sig;
        t->sig = n;
        n->ant = t;
        d->cant++;
    }
    MasterBlock *mb=disco->charToMasterBlock();
    char* guardar = static_cast<char*>(static_cast<void*>(&n));

    //this->disco->dv->Write(mb->SiguienteBloqueDisponible*420, guardar,strlen(guardar);
    //FileEntry fe=new FileEntry(n->nom,0,0,n->tipo);

}

QList<arch*>func::Listar(fold *d)
{
   QList<arch*> l;
   arch *t = d->l->i;
   for(int x = 0;x<d->cant;x++)
   {
       l.append(t);
       t = t->sig;
   }
   return l;
}

void func::pegar(arch *n,fold *d)
{
    agregar(n,d);
}

void func::CrearDiscoVirtual()
{

    disco->Formatear();
}
