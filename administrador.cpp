#include <iostream>
#include <cstdlib>
#include "administrador.h"

Administrador::Administrador(int _id, int _grupo, int _combinacion, bool _indispuesto, Empresa& _emp)
    : Encargado(_id, _grupo, _combinacion, _indispuesto, _emp) {}

int Administrador::DesignarEncargado(int grupo) {
    int agrupar = emp.getNempleados() / emp.getNgrupos();
    int max = grupo * agrupar;
    int min = (grupo - 1) * agrupar;
    int empleadoDesignado = rand() % (max - min) + min;

    return empleadoDesignado; 
}
