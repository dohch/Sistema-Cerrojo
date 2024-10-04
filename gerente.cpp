#include <iostream>
#include <cstdlib>
#include "gerente.h"

Gerente::Gerente(int _id, int _grupo, int _combinacion, bool _indispuesto, Empresa& _emp)
    : Encargado(_id, _grupo, _combinacion, _indispuesto, _emp) {}

int Gerente::DesignarGrupo() {
    int totalGrupos = emp.getNgrupos(); 
    if (totalGrupos <= 0) {
        std::cerr << "Error: No hay grupos disponibles." << std::endl;
        return -1; 
    }

    int grupoDesignado = rand() % totalGrupos; 
    return grupoDesignado; 
}
