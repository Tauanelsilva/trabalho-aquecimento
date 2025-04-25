#include "Simulador.hpp"
#include "Config.hpp"
#include <iostream>

using namespace std;

// Construtor
Simulador::Simulador() : iteracao(0) {}

// Carrega floresta e cria o animal
bool Simulador::carregar(const string& arquivoEntrada) {
    int fogoX = 0, fogoY = 0;
    if (!floresta.carregarDeArquivo(arquivoEntrada, fogoX, fogoY)) {
        cerr << "Erro ao carregar a floresta.\n";
        return false;
    }

    // Cria o animal em uma posição inicial (ajuste se quiser aleatório)
    animal = Animal(0, 0);

    // Marca o ponto inicial do fogo
    floresta.setValor(fogoX, fogoY, 2);

    return true;
}

// Verifica se a simulação deve parar
bool Simulador::terminou() const {
    return !animal.estaVivo() || iteracao >= MAX_INTERACOES;
}

// Mostra estatísticas finais
void Simulador::mostrarResumo() const {
    cout << "\n======= RESUMO DA SIMULAÇÃO =======\n";
    cout << "Iterações realizadas: " << iteracao << '\n';
    cout << "Passos dados pelo animal: " << animal.getPassos() << '\n';
    cout << "Água encontrada: " << animal.getAguaEncontrada() << '\n';
    if (!animal.estaVivo())
        cout << "Animal morreu na iteração: " << animal.getIteracaoMorte() << '\n';
    else
        cout << "Animal sobreviveu até o fim!\n";
}

// Executa o loop da simulação
void Simulador::executar() {
    while (!terminou()) {
        cout << "\n--- Iteração " << iteracao << " ---\n";

        floresta.propagarFogo();
        animal.mover(floresta);
        floresta.imprimir();
        floresta.salvarEmArquivo("output/output.dat");

        iteracao++;
    }

    mostrarResumo();
}
