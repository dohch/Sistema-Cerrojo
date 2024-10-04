#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>

class Empresa {
private:
    std::string nombre;
    int horarioApertura;
    int nEmpleados;
    int nGrupos;

protected:
    bool abierto;

public:
    Empresa(const std::string&, int, int, int, bool);

    void setNombre(const std::string& _nombre);
    void setHorarioApertura(int _horarioApertura);
    void setNempleados(int _nEmpleados);
    void setNgrupos(int _nGrupos);
    void setAbierto(bool _abierto);

    std::string getNombre() const;
    int getHorarioApertura() const;
    int getNempleados() const;
    int getNgrupos() const;
    bool getAbierto() const;
};

#endif
