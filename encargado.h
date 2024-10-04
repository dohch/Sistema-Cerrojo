#ifndef ENCARGADO_H
#define ENCARGADO_H

#include <iostream>
#include "empleado.h"
#include "cerrojo.h"
#include "empresa.h"

class Encargado : public Empleado, public Cerrojo {
protected:
    bool indispuesto; 
    Empresa& emp;
    static const int maxCombinaciones = 10; // Tamaño máximo del arreglo
    int combinaciones[maxCombinaciones]; // Arreglo para almacenar combinaciones válidas
    int combinacionesUsadas[maxCombinaciones]; // Arreglo para combinaciones que ya no son válidas
    int totalCombinaciones; // Contador de combinaciones válidas
    int totalCombinacionesUsadas; // Contador de combinaciones usadas

public:
    Encargado(int, int, int, bool, Empresa&);
    void setIndispuesto(bool);
    bool getIndispuesto() const;
    
    void crearCombinacion();
    void cambiarCombinacion();
    bool validarCombinacion(int combinacion); // Nuevo método
};

#endif
