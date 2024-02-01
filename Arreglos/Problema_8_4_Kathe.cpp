//se desea registrar una estructura PersonaEmpleado que sontenga como miembros los datos de una persona, el salario y el numero de horas trabajadas por semana. una persona, a su vez es otra estructura que tiene como miembros el nombre, la edad, la altura, el peso y la fecha de nacimiento es otra estructura que contiene el dia, mes y añi. Escribir funciones para leer y escribir un empleado de tipo 'PersonaEmpleado'
#include <iostream>
#include <string>

// Estructura para representar la fecha
struct Fecha {
    int dia;
    int mes;
    int anno;
};

// Estructura para representar una persona
struct Persona {
    std::string nombre;
    int edad;
    double altura;
    double peso;
    Fecha fechaNacimiento;
};

// Estructura para representar un empleado
struct PersonaEmpleado {
    Persona datosPersonales;
    double salario;
    int horasTrabajadasPorSemana;
};

// Función para leer los datos de una persona
Persona leerPersona() {
    Persona persona;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, persona.nombre);

    std::cout << "Ingrese la edad: ";
    std::cin >> persona.edad;

    std::cout << "Ingrese la altura: ";
    std::cin >> persona.altura;

    std::cout << "Ingrese el peso: ";
    std::cin >> persona.peso;

    std::cout << "Ingrese la fecha de nacimiento (Día Mes Año): ";
    std::cin >> persona.fechaNacimiento.dia >> persona.fechaNacimiento.mes >> persona.fechaNacimiento.anno;

    return persona;
}

// Función para leer los datos de un empleado
PersonaEmpleado leerEmpleado() {
    PersonaEmpleado empleado;

    std::cout << "Ingrese los datos del empleado:" << std::endl;

    // Leer datos de la persona
    empleado.datosPersonales = leerPersona();

    std::cout << "Ingrese el salario: ";
    std::cin >> empleado.salario;

    std::cout << "Ingrese el número de horas trabajadas por semana: ";
    std::cin >> empleado.horasTrabajadasPorSemana;

    return empleado;
}

// Función para mostrar los datos de una persona
void mostrarPersona(const Persona& persona) {
    std::cout << "Nombre: " << persona.nombre << std::endl;
    std::cout << "Edad: " << persona.edad << " años" << std::endl;
    std::cout << "Altura: " << persona.altura << " metros" << std::endl;
    std::cout << "Peso: " << persona.peso << " kg" << std::endl;
    std::cout << "Fecha de Nacimiento: " << persona.fechaNacimiento.dia << "/" 
              << persona.fechaNacimiento.mes << "/" << persona.fechaNacimiento.anno << std::endl;
}

// Función para mostrar los datos de un empleado
void mostrarEmpleado(const PersonaEmpleado& empleado) {
    std::cout << "Datos del empleado:" << std::endl;

    // Mostrar datos de la persona
    mostrarPersona(empleado.datosPersonales);

    std::cout << "Salario: $" << empleado.salario << std::endl;
    std::cout << "Horas trabajadas por semana: " << empleado.horasTrabajadasPorSemana << " horas" << std::endl;
}

int main() {
    // Ejemplo de uso de las funciones
    PersonaEmpleado empleado = leerEmpleado();
    mostrarEmpleado(empleado);

    return 0;
}
