#include "stuff.h"

stuff::stuff() {}

QString stuff::getname(){
    return name;
}
void stuff::setname(QString nn)
{
    name = nn;
}
int stuff::getcena()
{
    return cena;
}
void stuff::setcena(int a){
    cena = a;
}
int stuff::getcolvo(){
    return col_vo;
}
void stuff::setcolvo(int b){
    col_vo = b;
}
