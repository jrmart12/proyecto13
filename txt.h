#ifndef TEXTFILE_H
#define TEXTFILE_H
#include "arch.h"

class txt: public arch
{
public:
    txt(string n, string d,string t);
    int t();
    string tx;
    string dir();
    string nom();
    string Txt();
    void setTxt(string v);
};

#endif // TEXTFILE_H
