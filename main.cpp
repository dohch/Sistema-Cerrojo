#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Para std::numeric_limits
#include "empresa.h"
#include "gerente.h"
#include "administrador.h"
#include "encargado.h"
#include "empleado.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Crear una instancia de la clase Empresa
    Empresa myEmpresa("UNSA", 7, 1000, 10, false);

    // Crear un gerente
    Gerente primero(1, 0, 1234, false, myEmpresa);

    // Crear un administrador
    Administrador admin(2, 0, 5678, false, myEmpresa);

    // Crear un encargado
    Encargado encargado(3, 0, 111, false, myEmpresa);
    std::string encargadoPassword = "000"; // Contraseña inicial predeterminada

    // Crear un empleado
    Empleado empleado(4, 1);  // Empleado con ID 4, del grupo 1

    int opcionPrincipal; // Opción para el primer menú (Encargado/Empleado)
    
    do {
        // Mostrar el primer menú
        std::cout << "\n--- Menú Principal ---" << std::endl;
        std::cout << "1. Encargado" << std::endl;
        std::cout << "2. Empleado" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";

        // Validar entrada para opción principal
        while (!(std::cin >> opcionPrincipal) || (opcionPrincipal < 1 || opcionPrincipal > 3)) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
            std::cout << "Entrada inválida. Por favor, seleccione una opción válida (1-3): ";
        }

        if (opcionPrincipal == 1) {
            // Menú de Encargado - Pedir combinación inicial
            std::string inputPassword;
            std::cout << "Ingrese la combinación para la empresa (predeterminada es '000'): ";
            std::cin >> inputPassword;

            // Validar la combinación inicial
            if (inputPassword == encargadoPassword) {
                // Si la combinación es correcta, mostrar que cree una nueva combinación
                int nuevaCombinacion;
                std::cout << "Combinación correcta. Ahora cree una nueva combinación para la empresa: ";
                
                // Validar entrada para nueva combinación
                while (true) {
                    std::cin >> nuevaCombinacion;
                    // Verificar si la entrada es un número y si tiene exactamente 3 dígitos
                    if (std::cin.fail() || nuevaCombinacion < 100 || nuevaCombinacion > 999) {
                        std::cin.clear(); // Limpiar el estado de error
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                        std::cout << "Entrada inválida. Por favor, ingrese una combinación válida (tres dígitos): ";
                    } else {
                        break; // Salir del bucle si la entrada es válida
                    }
                }
                
                // Establecer nueva combinación
                encargado.setCombinacion(nuevaCombinacion); // Actualizar la combinación con la nueva
                encargadoPassword = std::to_string(nuevaCombinacion); // Actualizar la contraseña guardada

                int opcionEncargado;
                do {
                    // Menú de opciones del encargado
                    std::cout << "\n--- Menú Encargado ---" << std::endl;
                    std::cout << "1. Aperturar Empresa" << std::endl;
                    std::cout << "2. Cerrar Empresa" << std::endl;
                    std::cout << "3. Cambiar combinación" << std::endl;
                    std::cout << "4. Salir" << std::endl;
                    std::cout << "Seleccione una opción: ";

                    // Validar entrada para opción del encargado
                    while (!(std::cin >> opcionEncargado) || (opcionEncargado < 1 || opcionEncargado > 4)) {
                        std::cin.clear(); // Limpiar el estado de error
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                        std::cout << "Entrada inválida. Por favor, seleccione una opción válida (1-4): ";
                    }

                    switch (opcionEncargado) {
                        case 1: {
                            int combinacion;
                            std::cout << "Ingrese la combinación para aperturar la empresa: ";

                            // Validar entrada para combinación de apertura
                            while (true) {
                                std::cin >> combinacion;
                                // Verificar si la entrada es un número y si tiene exactamente 3 dígitos
                                if (std::cin.fail() || combinacion < 100 || combinacion > 999) {
                                    std::cin.clear(); // Limpiar el estado de error
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                                    std::cout << "Entrada inválida. Por favor, ingrese una combinación válida (tres dígitos): ";
                                } else {
                                    break; // Salir del bucle si la entrada es válida
                                }
                            }
                            
                            // Verificar la combinación
                            if (combinacion == encargado.getCombinacion()) {
                                myEmpresa.setAbierto(true); // Cambiar el estado a abierto
                                std::cout << "Empresa '" << myEmpresa.getNombre() << "' ha sido aperturada.\n";
                            } else {
                                std::cout << "Combinación incorrecta. No se pudo aperturar la empresa.\n";
                            }
                            break;
                        }
                        case 2: {
                            int combinacion;
                            std::cout << "Ingrese la combinación para cerrar la empresa: ";

                            // Validar entrada para combinación de cierre
                            while (true) {
                                std::cin >> combinacion;
                                // Verificar si la entrada es un número y si tiene exactamente 3 dígitos
                                if (std::cin.fail() || combinacion < 100 || combinacion > 999) {
                                    std::cin.clear(); // Limpiar el estado de error
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                                    std::cout << "Entrada inválida. Por favor, ingrese una combinación válida (tres dígitos): ";
                                } else {
                                    break; // Salir del bucle si la entrada es válida
                                }
                            }

                            // Verificar la combinación
                            if (combinacion == encargado.getCombinacion()) {
                                myEmpresa.setAbierto(false); // Cambiar el estado a cerrado
                                std::cout << "Empresa '" << myEmpresa.getNombre() << "' ha sido cerrada.\n";
                            } else {
                                std::cout << "Combinación incorrecta. No se pudo cerrar la empresa.\n";
                            }
                            break;
                        }
                        case 3: {
                            int combinacionAnterior;
                            std::cout << "Ingrese la combinación actual para validar: ";

                            // Validar entrada para combinación anterior
                            while (true) {
                                std::cin >> combinacionAnterior;
                                // Verificar si la entrada es un número y si tiene exactamente 3 dígitos
                                if (std::cin.fail() || combinacionAnterior < 100 || combinacionAnterior > 999) {
                                    std::cin.clear(); // Limpiar el estado de error
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                                    std::cout << "Entrada inválida. Por favor, ingrese una combinación válida (tres dígitos): ";
                                } else {
                                    break; // Salir del bucle si la entrada es válida
                                }
                            }

                            // Verificar la combinación actual antes de cambiar
                            if (combinacionAnterior == encargado.getCombinacion()) {
                                int nuevaCombinacion;
                                std::cout << "Ingrese la nueva combinación (tres dígitos): ";

                                // Validar entrada para nueva combinación
                                while (true) {
                                    std::cin >> nuevaCombinacion;
                                    // Verificar si la entrada es un número y si tiene exactamente 3 dígitos
                                    if (std::cin.fail() || nuevaCombinacion < 100 || nuevaCombinacion > 999) {
                                        std::cin.clear(); // Limpiar el estado de error
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada inválida
                                        std::cout << "Entrada inválida. Por favor, ingrese una combinación válida (tres dígitos): ";
                                    } else {
                                        break; // Salir del bucle si la entrada es válida
                                    }
                                }
                                encargado.setCombinacion(nuevaCombinacion); // Actualizar la combinación con la nueva
                                encargadoPassword = std::to_string(nuevaCombinacion); // Actualizar la contraseña guardada
                                std::cout << "Combinación cambiada exitosamente.\n";
                            } else {
                                std::cout << "Combinación anterior incorrecta. No se puede cambiar.\n";
                            }
                            break;
                        }
                        case 4:
                            std::cout << "Saliendo del menú de encargado...\n";
                            break;
                        default:
                            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                            break;
                    }
                } while (opcionEncargado != 4);
            } else {
                std::cout << "Combinación incorrecta. Acceso denegado.\n";
            }
        } else if (opcionPrincipal == 2) {
            // Menú de Empleado - Solo verificar acceso
            empleado.verificarAcceso(myEmpresa);
        } else if (opcionPrincipal == 3) {
            std::cout << "Saliendo del programa...\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcionPrincipal != 3);

    return 0;
}
