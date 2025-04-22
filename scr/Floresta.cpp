#include "Floresta.hpp"
#include "Config.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Construtor padrão
Floresta::Floresta() : linhas(0), colunas(0) {}

// Leitura do input.dat
bool Floresta::carregarDeArquivo(const string& nomeArquivo, int& fogoX, int& fogoY) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir " << nomeArquivo << endl;
        return false;
    }

    // Leitura das dimensões e posição inicial do fogo
    arquivo >> linhas >> colunas >> fogoX >> fogoY;

    // Validação mínima
    if (linhas < MIN_LINHAS || colunas < MIN_COLUNAS) {
        cerr << "Dimensões inválidas (mínimo " << MIN_LINHAS << "x" << MIN_COLUNAS << ")" << endl;
        return false;
    }

    // Inicializa a matriz
    matriz.resize(linhas, vector<int>(colunas));

    // Leitura da matriz linha por linha
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (!(arquivo >> matriz[i][j])) {
                cerr << "Erro de leitura na linha " << i << ", coluna " << j << endl;
                return false;
            }
        }
    }

    arquivo.close();
    return true;
}

// Gravação da matriz no output.dat
void Floresta::salvarEmArquivo(const string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo, ios::app); // app: adiciona no fim, não sobrescreve
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar em " << nomeArquivo << endl;
        return;
    }

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << "\n";
    }

    arquivo << "\n"; // separa iteração com linha em branco
    arquivo.close();
}

// Impressão da matriz no terminal (usando caracteres visuais)
void Floresta::imprimir() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            char c;
            switch (matriz[i][j]) {
                case 0: c = CHAR_VAZIO; break;
                case 1: c = CHAR_SAUDE; break;
                case 2: c = CHAR_FOGO; break;
                case 3: c = CHAR_QUEIMADA; break;
                case 4: c = CHAR_AGUA; break;
                default: c = '?'; break;
            }
            cout << c << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}
void Floresta::propagarFogo() {
    // Cria uma cópia da matriz original
    std::vector<std::vector<int>> novaMatriz = matriz;

    // Percorre cada célula da matriz
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == 2) {
                // Queima a árvore atual (vira queimada)
                novaMatriz[i][j] = 3;

                // Propaga para as direções permitidas
                if (VENTO_CIMA && i > 0 && matriz[i - 1][j] == 1) novaMatriz[i - 1][j] = 2;
                if (VENTO_BAIXO && i < linhas - 1 && matriz[i + 1][j] == 1) novaMatriz[i + 1][j] = 2;
                if (VENTO_ESQUERDA && j > 0 && matriz[i][j - 1] == 1) novaMatriz[i][j - 1] = 2;
                if (VENTO_DIREITA && j < colunas - 1 && matriz[i][j + 1] == 1) novaMatriz[i][j + 1] = 2;
            }
        }
    }

    // Substitui a matriz original pela atualizada
    matriz = novaMatriz;
}


// Getter de célula
int Floresta::getValor(int x, int y) const {
    return matriz[x][y];
}

void Floresta::setValor(int x, int y, int valor) {
    if (x >= 0 && x < linhas && y >= 0 && y < colunas) {
        matriz[x][y] = valor;
    }
}


