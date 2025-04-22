#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <string>

class Floresta {
private:
    int linhas;
    int colunas;
    std::vector<std::vector<int>> matriz;

public:
    // Construtor padrão
    Floresta();

    // Lê o input.dat, preenche matriz, e retorna posição inicial do fogo
    bool carregarDeArquivo(const std::string& nomeArquivo, int& fogoX, int& fogoY);

    // Salva o estado atual da floresta em output.dat
    void salvarEmArquivo(const std::string& nomeArquivo) const;

    // Exibe a matriz no terminal
    void imprimir() const;

    // Propaga o fogo segundo as regras do problema
    void propagarFogo();  // 👈 adicionado aqui

    // Acessores úteis
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }

    int getValor(int x, int y) const;              // retorna valor da célula (x, y)
    void setValor(int x, int y, int valor);        // define valor da célula (x, y)
};

#endif // FLORESTA_HPP
