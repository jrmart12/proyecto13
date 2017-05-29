#include "txt.h"

txt::txt(string n, string d,string t) : arch(n,d,0)
{
    tx = t;
}




void txt::setTxt(string v)
{
    tx = tx + v;
}




string txt::nom()
{
    return arch::n();
}



int txt::t()
{
    return arch::t();
}



string txt::dir()
{
    return arch::d();
}



string txt::Txt()
{
    return tx;
}
