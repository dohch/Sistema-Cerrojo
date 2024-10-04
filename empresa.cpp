#include "empresa.h"

Empresa::Empresa(const std::string& _nombre, int _horarioApertura, int _nEmpleados, int _nGrupos, bool _abierto)
    : nombre(_nombre), horarioApertura(_horarioApertura), nEmpleados(_nEmpleados), nGrupos(_nGrupos), abierto(_abierto) {}

void Empresa::setNombre(const std::string& _nombre) {
    nombre = _nombre;
}

void Empresa::setHorarioApertura(int _horarioApertura) {
    horarioApertura = _horarioApertura;
}

void Empresa::setNempleados(int _nEmpleados) {
    nEmpleados = _nEmpleados;
}

void Empresa::setNgrupos(int _nGrupos) {
    nGrupos = _nGrupos;
}

void Empresa::setAbierto(bool _abierto) {
    abierto = _abierto;
}

std::string Empresa::getNombre() const {
    return nombre;
}

int Empresa::getHorarioApertura() const {
    return horarioApertura;
}

int Empresa::getNempleados() const {
    return nEmpleados;
}

int Empresa::getNgrupos() const {
    return nGrupos;
}

bool Empresa::getAbierto() const {
    return abierto;
}
