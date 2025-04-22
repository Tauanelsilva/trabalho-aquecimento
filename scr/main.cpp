#include "Simulador.hpp"
#include <iostream>

int main() {
    Simulador simulador;

    if (simulador.carregar("input/input.dat")) {
        simulador.executar();
    } else {
        std::cerr << "Erro ao carregar a simulação.\n";
    }

    return 0;
}

