#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
#include "encargado.h"

class Gerente : public Encargado {
public:
    Gerente();
    Gerente(int, int, int, bool, Empresa&);
    int DesignarGrupo();
};

#endif
