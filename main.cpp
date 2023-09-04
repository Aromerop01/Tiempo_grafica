#include <iostream>
#include <vector>
#include <ctime>

std::string busquedaLineal(const std::vector<int>& lista, int elemento) {
    for (int i = 0; i < lista.size(); ++i) {
        if (lista[i] == elemento) {
            return "Elemento encontrado en la posición " + std::to_string(i);
        }
    }
    return "Elemento no encontrado en la lista";
}

int main() {
    std::vector<int> tamanos = {100, 500, 1000, 5000, 10000};
    int elementoABuscar = 3000;

    for (int tamano : tamanos) {
        std::vector<int> lista;
        for (int i = 0; i < tamano; ++i) {
            lista.push_back(i);
        }

        double tiempoPromedio = 0;
        int numEjecuciones = 1000;

        std::string resultado;

        for (int i = 0; i < numEjecuciones; ++i) {
            clock_t start_time = clock();
            resultado = busquedaLineal(lista, elementoABuscar);
            clock_t end_time = clock();
            tiempoPromedio += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        }

        tiempoPromedio /= numEjecuciones;

        std::cout << "Tamaño de la lista: " << tamano << std::endl;
        std::cout << "Tiempo de ejecución promedio: " << tiempoPromedio << " segundos" << std::endl;
        std::cout << "Resultado de la búsqueda: " << resultado << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}


