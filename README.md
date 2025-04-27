# 🔥 Simulador de Propagação de Fogo em Floresta com Comportamento Animal 🔥

*Aluno:* Tauane Luísa Silva  
*Professor:* Michel Pires da Silva  
*Disciplina:* Algoritmos e Estruturas de Dados I  

## 📚 Índice
1. [Introdução](#-introdução)
2. [Objetivos](#-objetivos)
3. [Funcionalidades](#-funcionalidades)
4. [Estrutura do Projeto](#-estrutura-do-projeto)
5. [Configuração](#-configuração)
6. [Compilação e Execução](#-compilação-e-execução)
7. [Formatos de Arquivos](#-formatos-de-arquivos)
8. [Lógica de Implementação](#-lógica-de-implementação)
9. [Exemplos de Simulação](#-exemplos-de-simulação)
10. [Melhorias Futuras](#-melhorias-futuras)
11. [Conclusão](#-conclusão)

## 🌍 Introdução
Este projeto simula a propagação de fogo em uma floresta representada por uma matriz bidimensional, enquanto um animal inteligente tenta sobreviver ao desastre. Desenvolvido em C++, o sistema utiliza:

- Matrizes dinâmicas para representação do ambiente
- Algoritmos de propagação condicional
- Sistema de prioridades para tomada de decisão do animal
- Gerenciamento de arquivos para entrada/saída de dados

## 🎯 Objetivos
1. Modelar a propagação realista de fogo considerando:
   - Direção e intensidade do vento
   - Tipos de terreno (árvores saudáveis, áreas queimadas, água)
2. Implementar sistema autônomo para o animal com:
   - Comportamento estratégico
   - Mecanismo de "segunda chance"
   - Coleta de estatísticas de desempenho
3. Fornecer ferramentas para análise:
   - Visualização em tempo real
   - Geração de relatórios detalhados
   - Configuração flexível de parâmetros

## ✨ Funcionalidades

### 🌳 Sistema de Floresta
Matriz dinâmica com 5 estados:
- 0: Área vazia (segura)
- 1: Árvore saudável (combustível)
- 2: Fogo ativo
- 3: Árvore queimada (inerte)
- 4: Água (extingue fogo)

Propagação configurável por vento:

cpp
// Em Config.hpp
const bool VENTO_CIMA = true;
const bool VENTO_BAIXO = true;
const bool VENTO_ESQUERDA = true;
const bool VENTO_DIREITA = true;


### 🦊 Comportamento do Animal
Sistema de prioridades:
1. Água (4) - Movimento preferencial
2. Área vazia (0) - Movimento seguro
3. Árvore saudável (1) - Risco futuro
4. Árvore queimada (3) - Última opção

Mecanismo de sobrevivência:
- Segunda chance ao encontrar fogo
- Registro da iteração da morte

### 📊 Sistema de Saída
- *Terminal*: Visualização com símbolos e cores (opcional)
- *Arquivos*: Geração de output.dat com histórico completo e estatísticas finais detalhadas

## 📂 Estrutura do Projeto


.
├── include/
│   ├── Animal.hpp       # Lógica do animal
│   ├── Config.hpp       # Parâmetros da simulação
│   ├── Floresta.hpp     # Modelagem da floresta
│   └── Simulador.hpp    # Orquestração principal
├── src/
│   ├── Animal.cpp       # Implementação do animal
│   ├── Floresta.cpp     # Propagação do fogo
│   ├── Simulador.cpp    # Loop da simulação
│   └── main.cpp         # Ponto de entrada
├── input/
│   └── input.dat        # Exemplo de entrada
└── output/
    └── output.dat       # Resultados gerados


## ⚙ Configuração
Edite Config.hpp para ajustar os parâmetros:

cpp
namespace Config {
    // Direções do vento
    const bool VENTO_CIMA = true;
    const bool VENTO_BAIXO = true;
    const bool VENTO_ESQUERDA = true;
    const bool VENTO_DIREITA = true;

    // Limites da simulação
    const int MAX_INTERACOES = 100;
    const int MIN_LINHAS = 5;
    const int MIN_COLUNAS = 5;

    // Símbolos de exibição
    const char CHAR_VAZIO = '.';
    const char CHAR_SAUDE = '🌲';
    const char CHAR_FOGO = '🔥';
    const char CHAR_QUEIMADA = '💀';
    const char CHAR_AGUA = '💧';
    const char CHAR_ANIMAL = '🦊';
}


## 🚀 Compilação e Execução

*Requisitos*:
- Compilador C++11 (g++ ou clang++)
- CMake (opcional)

### Método 1: Compilação Direta
bash
g++ -std=c++11 src/*.cpp -I include -o simulador
./simulador


### Método 2: Usando CMake
bash
mkdir build
cd build
cmake ..
make
./simulador


## 📄 Formatos de Arquivos

### Entrada (input/input.dat)

LINHAS COLUNAS X_FOGO Y_FOGO
MATRIZ_DA_FLORESTA...

*Exemplo*:

5 5 2 2
1 1 1 1 1
1 0 4 0 1
1 1 2 1 1
1 0 0 0 1
1 1 1 1 1


### Saída (output/output.dat)

--- Iteração 0 ---
1 1 1 1 1 
1 0 A 0 1 
1 1 2 1 1 
1 0 0 0 1 
1 1 1 1 1 

====== RESUMO ======
Iterações: 5
Passos do animal: 3
Água encontrada: 1
Sobreviveu: Sim


## 🧠 Lógica de Implementação

### 🔥 Propagação do Fogo
cpp
void Floresta::propagarFogo() {
    vector<vector<int>> novaMatriz = matriz;
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 2) { // Célula em chamas
                novaMatriz[i][j] = 3; // Queimada

                // Propaga para vizinhos conforme vento
                if (VENTO_CIMA && i > 0 && matriz[i-1][j] == 1)
                    novaMatriz[i-1][j] = 2;
                if (VENTO_BAIXO && i < linhas-1 && matriz[i+1][j] == 1)
                    novaMatriz[i+1][j] = 2;
                if (VENTO_ESQUERDA && j > 0 && matriz[i][j-1] == 1)
                    novaMatriz[i][j-1] = 2;
                if (VENTO_DIREITA && j < colunas-1 && matriz[i][j+1] == 1)
                    novaMatriz[i][j+1] = 2;
            }
        }
    }
    matriz = novaMatriz;
}


### 🦊 Movimento do Animal
cpp
void Animal::mover(Floresta& floresta) {
    vector<pair<int,int>> vizinhos;
    // Coleta vizinhos válidos
    // [...]
    
    // Ordena por prioridade
    sort(vizinhos.begin(), vizinhos.end(), [&](auto a, auto b){
        return prioridade(floresta.getValor(a.first, a.second)) 
             < prioridade(floresta.getValor(b.first, b.second));
    });
    
    // Tenta se mover
    for (auto& pos : vizinhos) {
        int tipo = floresta.getValor(pos.first, pos.second);
        if (tipo == 4) aguaEncontrada++;
        // [...] Lógica de movimento
    }
}


## 🌐 Exemplos de Simulação

### Caso 1: Sobrevivência do Animal
*Cenário*:
- Animal começa em (0,0)
- Água em (1,2)
- Fogo se propaga da direita

*Resultado*:
- Animal encontrou água na iteração 3!
- Sobreviveu: Sim
- Água encontrada: 1

## 🔮 Melhorias Futuras

*Otimização*:
- Usar std::queue para células em chamas
- Implementar multithreading para propagação do fogo

*Visualização*:
- Criar interface gráfica com SFML
- Adicionar animações da propagação

*Funcionalidades*:
- Múltiplos animais com estratégias diferentes
- Diferentes tipos de vegetação e resistência
- Considerar umidade do ambiente

*Análise Científica*:
- Exportar dados para análise em Python
- Gerar gráficos de velocidade de propagação

## 📝 Conclusão
Este projeto demonstra competência em:

- Projeto de sistemas complexos em C++
- Uso eficiente de estruturas de dados dinâmicas
- Implementação de algoritmos de simulação
- Boas práticas de organização de código

As técnicas aplicadas podem ser estendidas para:
- Simulações ecológicas realistas
- Desenvolvimento de autômatos celulares
- Jogos de estratégia baseados em simulação
---
<img src="https://www.mermaidchart.com/raw/c45abd61-03f4-49d4-8610-1d51e501106b?theme=light&version=v0.1&format=svg"/>
