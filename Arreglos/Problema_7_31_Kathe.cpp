#include <iostream>  // Librería para entrada/salida estándar
#include <vector>    // Librería para utilizar vectores
#include <string>    // Librería para trabajar con cadenas de texto

// Estructura para representar un libro
struct Libro {
    std::string titulo;
    std::string fechaPublicacion;
    std::string autor;
    int librosEnPedidos;
    double precioVenta;
};

// Función para leer los datos de un libro desde el usuario
Libro leerLibro() {
    Libro libro;

    // Solicitar al usuario que ingrese los detalles del libro
    std::cout << "Ingrese el título del libro: ";
    std::getline(std::cin, libro.titulo);

    std::cout << "Ingrese la fecha de publicación del libro: ";
    std::getline(std::cin, libro.fechaPublicacion);

    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, libro.autor);

    std::cout << "Ingrese el número total de libros existentes en pedidos: ";
    std::cin >> libro.librosEnPedidos;

    std::cout << "Ingrese el precio de venta del libro: ";
    std::cin >> libro.precioVenta;

    std::cin.ignore(); // Limpiar el buffer del salto de línea

    return libro;
}

// Función para mostrar la base de datos de libros
void mostrarBaseDeDatos(const std::vector<Libro>& baseDeDatos) {
    // Mostrar la información de cada libro almacenado en la base de datos
    std::cout << "=== Base de Datos de Libros ===" << std::endl;
    for (const auto& libro : baseDeDatos) {
        std::cout << "Título: " << libro.titulo << std::endl;
        std::cout << "Fecha de Publicación: " << libro.fechaPublicacion << std::endl;
        std::cout << "Autor: " << libro.autor << std::endl;
        std::cout << "Libros en Pedidos: " << libro.librosEnPedidos << std::endl;
        std::cout << "Precio de Venta: $" << libro.precioVenta << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }
}

int main() {
    std::vector<Libro> baseDeDatosLibros; // Vector para almacenar la base de datos de libros
    char opcion;

    do {
        // Menú de opciones
        std::cout << "Seleccione una opción:" << std::endl;
        std::cout << "1. Agregar Libro" << std::endl;
        std::cout << "2. Mostrar Base de Datos" << std::endl;
        std::cout << "3. Salir" << std::endl;

        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer del salto de línea

        switch (opcion) {
            case '1': {
                // Agregar un nuevo libro a la base de datos
                baseDeDatosLibros.push_back(leerLibro());
                std::cout << "Libro agregado correctamente." << std::endl;
                break;
            }
            case '2': {
                // Mostrar la base de datos de libros
                mostrarBaseDeDatos(baseDeDatosLibros);
                break;
            }
            case '3':
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }
    } while (opcion != '3');

    return 0;
}
