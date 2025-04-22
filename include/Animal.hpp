#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Floresta.hpp"

class Animal {
private:
    int x, y;                 // posição atual
    int passos;              // total de passos dados
    int ciclosParado;        // quantos ciclos ele ficou parado
    int aguaEncontrada;      // número de vezes que achou água
    int iteracaoMorte;       // -1 se estiver vivo
    bool segundaChanceUsada; // para saber se ele já sobreviveu uma vez ao fogo

public:
    Animal();                                // Construtor padrão
    Animal(int startX, int startY);          // Construtor com posição inicial

    void mover(Floresta& floresta);          // movimentação baseada nas regras
    bool estaVivo() const;                   // se morreu ou não
    int getX() const;
    int getY() const;
    int getPassos() const;
    int getAguaEncontrada() const;
    int getIteracaoMorte() const;

    void marcarMorte(int iteracao);
};

#endif // ANIMAL_HPP
