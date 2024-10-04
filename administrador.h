#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "encargado.h"

class Administrador : public Encargado {
public:
    Administrador();
    Administrador(int, int, int, bool, Empresa&);
    int DesignarEncargado(int);
};

#endif
