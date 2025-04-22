#include "Animal.hpp"
#include <iostream>
#include <algorithm> // std::sort

using namespace std;

// Construtor padrão (posição inválida inicialmente)
Animal::Animal()
    : x(-1), y(-1), passos(0), ciclosParado(0), aguaEncontrada(0),
      iteracaoMorte(-1), segundaChanceUsada(false) {}

// Construtor com posição inicial
Animal::Animal(int startX, int startY)
    : x(startX), y(startY), passos(0), ciclosParado(0), aguaEncontrada(0),
      iteracaoMorte(-1), segundaChanceUsada(false) {}

// Getters
int Animal::getX() const {
    return x;
}

int Animal::getY() const {
    return y;
}

int Animal::getPassos() const {
    return passos;
}

int Animal::getAguaEncontrada() const {
    return aguaEncontrada;
}

int Animal::getIteracaoMorte() const {
    return iteracaoMorte;
}

bool Animal::estaVivo() const {
    return iteracaoMorte == -1;
}

void Animal::marcarMorte(int iteracao) {
    iteracaoMorte = iteracao;
}

// ======================
// Movimento do animal
// ======================
void Animal::mover(Floresta& floresta) {
    if (!estaVivo()) return; // se já morreu, não faz nada

    vector<pair<int, int>> vizinhos;
    int dx[] = {-1, 1, 0, 0}; // cima, baixo
    int dy[] = {0, 0, -1, 1}; // esquerda, direita

    // 1. Coletar vizinhos válidos
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < floresta.getLinhas() && ny >= 0 && ny < floresta.getColunas()) {
            vizinhos.emplace_back(nx, ny);
        }
    }

    // 2. Ordenar vizinhos por prioridade de terreno
    auto prioridade = [&](int tipo) -> int {
        switch (tipo) {
            case 4: return 1; // água
            case 0: return 2; // vazio
            case 1: return 3; // saudável
            case 3: return 4; // queimada
            case 2: return 5; // fogo (último caso)
            default: return 6;
        }
    };

    sort(vizinhos.begin(), vizinhos.end(), [&](auto a, auto b) {
        int tipoA = floresta.getValor(a.first, a.second);
        int tipoB = floresta.getValor(b.first, b.second);
        return prioridade(tipoA) < prioridade(tipoB);
    });

    // 3. Tentar se mover para o melhor vizinho
    bool moveu = false;
    for (const auto& pos : vizinhos) {
        int tipo = floresta.getValor(pos.first, pos.second);

        // Evita entrar em fogo se já usou a segunda chance
        if (tipo == 2 && segundaChanceUsada) continue;

        // Move
        x = pos.first;
        y = pos.second;
        passos++;

        // Atualiza estado
        if (tipo == 4) aguaEncontrada++;
        if (tipo == 2 && !segundaChanceUsada) {
            segundaChanceUsada = true;
            cout << "[!] O animal usou sua segunda chance!\n";
        }

        ciclosParado = 0;
        moveu = true;
        break;
    }

    // 4. Se não se moveu, aumenta ciclos parado
    if (!moveu) {
        ciclosParado++;
        cout << "[~] Animal permaneceu parado. Ciclos parado: " << ciclosParado << "\n";
    }

    // 5. Verifica se está em fogo após o movimento
    int tipoAtual = floresta.getValor(x, y);
    if (tipoAtual == 2) {
        if (segundaChanceUsada) {
            cout << "[X] O animal morreu no fogo em (" << x << ", " << y << ")\n";
            marcarMorte(passos); // pode trocar por número da iteração se desejar
        } else {
            segundaChanceUsada = true;
            cout << "[!] O animal sobreviveu ao fogo uma vez.\n";
        }
    }
}
