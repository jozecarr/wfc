#ifndef RANDNUM_H
#define RANDNUM_H

#include <stdlib.h>
#include <ctime>

class randnum {
public:
    randnum();
    int gen(int a);
    int gen(int a, int b);
};

randnum::randnum() {
    srand(time(0));
}


int randnum::gen(int a) {
    return rand() % a;
}

int randnum::gen(int a, int b){
    return a + (rand() % (b - a));
}

#endif