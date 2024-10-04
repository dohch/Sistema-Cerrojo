#include "cerrojo.h"

Cerrojo::Cerrojo(int _combinacion) : combinacion(_combinacion) {}

void Cerrojo::setCombinacion(int _combinacion) {
    combinacion = _combinacion;
}

int Cerrojo::getCombinacion() const {
    return combinacion;
}