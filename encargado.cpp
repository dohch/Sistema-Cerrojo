#include "encargado.h"

Encargado::Encargado(int _id, int _grupo, int _combinacion, bool _indispuesto, Empresa& _emp)
    : Empleado(_id, _grupo, false), Cerrojo(_combinacion), emp(_emp), 
      indispuesto(_indispuesto), totalCombinaciones(0), totalCombinacionesUsadas(0) {
    // Almacenar la combinación inicial
    combinaciones[totalCombinaciones++] = _combinacion; // Almacena la combinación válida
}

void Encargado::setIndispuesto(bool estado) {
    indispuesto = estado;
}

bool Encargado::getIndispuesto() const {
    return indispuesto;
}

void Encargado::crearCombinacion() {
    int combinacionNueva;

    do {
        std::cout << "Ingrese una combinación de 3 dígitos (ej. 123): ";
        std::cin >> combinacionNueva;
    } while (combinacionNueva < 100 || combinacionNueva > 999); // Verifica que sea de 3 dígitos

    setCombinacion(combinacionNueva); // Establece la nueva combinación
    combinaciones[totalCombinaciones++] = combinacionNueva; // Almacena en el arreglo
    std::cout << "Combinación creada con éxito: " << getCombinacion() << std::endl;
}

void Encargado::cambiarCombinacion() {
    int combinacionAnterior;
    
    std::cout << "Ingrese la combinación anterior para validar: ";
    std::cin >> combinacionAnterior;

    // Validar la combinación anterior
    if (!validarCombinacion(combinacionAnterior)) {
        std::cout << "Combinación anterior incorrecta. No se puede cambiar." << std::endl;
        return;
    }

    // Mover la combinación anterior a combinaciones usadas
    combinacionesUsadas[totalCombinacionesUsadas++] = combinacionAnterior; // Almacena en el arreglo de usadas

    int combinacionNueva;

    do {
        std::cout << "Ingrese la nueva combinación de 3 dígitos (ej. 123): ";
        std::cin >> combinacionNueva;
    } while (combinacionNueva < 100 || combinacionNueva > 999); // Verifica que sea de 3 dígitos

    // Eliminar la combinación anterior de las válidas
    for (int i = 0; i < totalCombinaciones; ++i) {
        if (combinaciones[i] == combinacionAnterior) {
            combinaciones[i] = combinaciones[--totalCombinaciones]; // Reemplaza con la última combinación
            break; // Salimos del bucle
        }
    }

    setCombinacion(combinacionNueva); // Establece la nueva combinación
    combinaciones[totalCombinaciones++] = combinacionNueva; // Almacena en el arreglo de válidas
    std::cout << "Combinación cambiada con éxito: " << getCombinacion() << std::endl;
}

bool Encargado::validarCombinacion(int combinacion) {
    // Verificar si la combinación está en el arreglo de combinaciones válidas
    for (int i = 0; i < totalCombinaciones; ++i) {
        if (combinaciones[i] == combinacion) {
            return true; // La combinación existe
        }
    }
    
    // Verificar si la combinación está en el arreglo de combinaciones usadas
    for (int i = 0; i < totalCombinacionesUsadas; ++i) {
        if (combinacionesUsadas[i] == combinacion) {
            return false; // La combinación fue usada y no es válida
        }
    }
    
    return false; // La combinación no existe
}
