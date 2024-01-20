#include "output.h"

output::output() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;

}

void output::setTech(int f){
    if(f == 0)
         a++;
    if(f == 1)
        b++;
    if(f == 2)
         c++;
    if(f == 3)
         d++;
}

int output::getTech(int f){
    if(f == 0)
        return a;
    if(f == 1)
        return b;
    if(f == 2)
        return c;
    if(f == 3)
        return d;

}
