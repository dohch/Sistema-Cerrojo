#include "empleado.h"
#include "empresa.h"

Empleado::Empleado(int _id, int _grupo, bool _acceso) : id(_id), grupo(_grupo), acceso(_acceso) {}

void Empleado::setId(int _id) {
    id = _id;
}

void Empleado::setGrupo(int _grupo) {
    grupo = _grupo;
}

void Empleado::setAcceso(bool _acceso) {
    acceso = _acceso;
}

int Empleado::getId() const {
    return id;
}

int Empleado::getGrupo() const {
    return grupo;
}

bool Empleado::getAcceso() const {
    return acceso;
}

void Empleado::verificarAcceso(const Empresa& empresa) const {
    if (empresa.getAbierto()) {
        std::cout << "\033[1;32mACCESO PERMITIDO: Bienvenido a la empresa '" << empresa.getNombre() << "'\033[0m\n";  // Verde
    } else {
        std::cout << "\033[1;31mACCESO DENEGADO: La empresa '" << empresa.getNombre() << "' está cerrada\033[0m\n";  // Rojo
    }
}
