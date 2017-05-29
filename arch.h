#ifndef ARCH_H
#define ARCH_H
#include <iostream>
#include <string>
using namespace std;

class arch
{
public:
    arch(string n, string d, int t);
    string nom;
    string dir;
    int tip;
    virtual string n();
    virtual string d();
    virtual int t();
    arch * sig;
    arch * ant;
};

#endif // ARCHIVO_H
