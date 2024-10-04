
#ifndef CERROJO_H
#define CERROJO_H

#include <iostream>

class Cerrojo {
private:
    int combinacion;

public:
    Cerrojo(int);
    void setCombinacion(int);
    int getCombinacion() const;
};

#endif
