#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>

// Declaración anticipada de Empresa
class Empresa;

class Empleado {
private:
    int id;
    int grupo;
    bool acceso;

public:
    Empleado(int _id, int _grupo, bool _acceso = false);

    void setId(int _id);
    void setGrupo(int _grupo);
    void setAcceso(bool _acceso);
    int getId() const;
    int getGrupo() const;
    bool getAcceso() const;

    // Método para verificar el acceso
    void verificarAcceso(const Empresa& empresa) const;
};

#endif
