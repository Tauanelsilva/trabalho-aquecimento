#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "Floresta.hpp"
#include "Animal.hpp"

class Simulador {
private:
    Floresta floresta;
    Animal animal;
    int iteracao;

public:
    Simulador();

    // Carrega a floresta e cria o animal
    bool carregar(const std::string& arquivoEntrada);

    // Executa o loop da simulação
    void executar();

    // Verifica condição de parada
    bool terminou() const;

    // Exibe estatísticas finais
    void mostrarResumo() const;
};

#endif // SIMULADOR_HPP
