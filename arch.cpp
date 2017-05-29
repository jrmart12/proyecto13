#include "arch.h"

arch::arch(string n, string d,int t)
{
    nom = n;
    dir = d;
    tip = t;
    sig = NULL;
    ant = NULL;

}




string arch::d()
{
    return dir;
}




int arch::t()
{
    return tip;
}




string arch::n()
{
    return nom;
}
