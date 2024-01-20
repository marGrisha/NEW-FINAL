#ifndef STUFF_H
#define STUFF_H
#include <QString>

class stuff
{
public:
    stuff();
    QString getname();
    void setname(QString nn);
    int getcena();
    void setcena(int a);
    int getcolvo();
    void setcolvo(int b);


private:
    int cena;
    int col_vo;
    QString name;
};

#endif // STUFF_H
