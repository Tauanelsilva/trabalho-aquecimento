# 🔥 Simulador de Propagação de Fogo em Floresta com Comportamento Animal 🔥

**Aluno:** Tauane Luísa Silva  
**Professor:** Michel Pires da Silva  
**Disciplina:** Algoritmos e Estruturas de Dados I  

## 📚 Índice
1. [Introdução](#-introdução)
2. [Objetivos](#-objetivos)
3. [Funcionalidades](#-funcionalidades)
4. [Estrutura do Projeto](#-estrutura-do-projeto)
5. [Configuração](#-configuração)
6. [Compilação e Execução](#-compilação-e-execução)
7. [Formatos de Arquivos](#-formatos-de-arquivos)
8. [Lógica de Implementação](#-lógica-de-implementação)
9. [Casos de Teste](#-casos-de-teste)
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

0: Área vazia (segura)
1: Árvore saudável (combustível)
2: Fogo ativo
3: Árvore queimada (inerte)
4: Água (extingue fogo)
Propagação configurável por vento:

cpp
Copiar
Editar
// Em Config.hpp
const bool VENTO_CIMA = true;
const bool VENTO_BAIXO = true;
const bool VENTO_ESQUERDA = true;
const bool VENTO_DIREITA = true;
🦊 Comportamento do Animal
Sistema de prioridades:

Água (4) - Converte para área segura

Vazio (0) - Movimento seguro

Árvore saudável (1) - Risco futuro

Queimada (3) - Última opção

Mecanismo de sobrevivência:

Segunda chance ao encontrar fogo

Registro de iteração da morte

📊 Sistema de Saída
Terminal:

Visualização com símbolos personalizáveis

Cores para diferentes estados (opcional)

Arquivos:

output.dat com histórico completo

Estatísticas finais detalhadas

📂 Estrutura do Projeto
graphql
Copiar
Editar
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
⚙️ Configuração
Edite Config.hpp para ajustar os parâmetros:

cpp
Copiar
Editar
#pragma once
namespace Config {
    // Direções de vento
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
🚀 Compilação e Execução
Requisitos:

Compilador C++11 (g++ ou clang++)

CMake (opcional)

Método 1: Compilação Direta

bash
Copiar
Editar
g++ -std=c++11 src/*.cpp -I include -o simulador
./simulador
Método 2: Com CMake

bash
Copiar
Editar
mkdir build && cd build
cmake ..
make
./simulador
📄 Formatos de Arquivos
Entrada (input/input.dat)
nginx
Copiar
Editar
LINHAS COLUNAS X_FOGO Y_FOGO
MATRIZ_DA_FLORESTA...
Exemplo:

Copiar
Editar
5 5 2 2
1 1 1 1 1
1 0 4 0 1
1 1 2 1 1
1 0 0 0 1
1 1 1 1 1
Saída (output/output.dat)
yaml
Copiar
Editar
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
🧠 Lógica de Implementação
🔥 Propagação do Fogo
cpp
Copiar
Editar
void Floresta::propagarFogo() {
    vector<vector<int>> novaMatriz = matriz;
    
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(matriz[i][j] == 2){ // Célula em chamas
                novaMatriz[i][j] = 3; // Vira cinza
                
                // Propaga para vizinhos conforme vento
                if(VENTO_CIMA && i>0 && matriz[i-1][j]==1)
                    novaMatriz[i-1][j] = 2;
                // [...] outras direções
            }
        }
    }
    matriz = novaMatriz;
}
🦊 Movimento do Animal
cpp
Copiar
Editar
void Animal::mover(Floresta& floresta){
    vector<pair<int,int>> vizinhos;
    // Coleta vizinhos válidos
    // [...] 
    
    // Ordena por prioridade
    sort(vizinhos.begin(), vizinhos.end(), [&](auto a, auto b){
        return prioridade(floresta.getValor(a.first, a.second)) 
             < prioridade(floresta.getValor(b.first, b.second));
    });
    
    // Tenta se mover
    for(auto& pos : vizinhos){
        int tipo = floresta.getValor(pos.first, pos.second);
        if(tipo == 4) aguaEncontrada++;
        // [...] Lógica de movimento
    }
}
🌐 Exemplos de Simulação
Caso 1: Propagação Completa
Entrada:

Copiar
Editar
3 3 1 1
1 1 1
1 2 1 
1 1 1
Saída no Terminal:

Copiar
Editar
Iteração 0    Iteração 1    Iteração 2
🌲🌲🌲        🌲🔥🌲        💀💀💀
🌲🔥🌲   →   💀💀💀   →   💀💀💀
🌲🌲🌲        🌲🔥🌲        💀💀💀
Caso 2: Sobrevivência do Animal
Cenário:

Animal começa em (0,0)

Água em (1,2)

Fogo se propaga da direita

Resultado:

Animal encontrou água na iteração 3!

Sobreviveu: Sim

Água encontrada: 1

🔮 Melhorias Futuras
Otimização:
Usar std::queue para células em chamas

Implementar multithreading

Visualização:
Interface gráfica com SFML

Animações de propagação

Funcionalidades:
Múltiplos animais

Diferentes tipos de vegetação

Umidade variável

Análise Científica:
Exportar dados para Python

Gerar gráficos de propagação

📝 Conclusão
Este projeto demonstra competência em:

Projeto de sistemas complexos em C++

Uso eficiente de estruturas de dados

Implementação de algoritmos de simulação

Boas práticas de organização de código

As técnicas aplicadas podem ser estendidas para:

Simulações ecológicas mais complexas

Sistemas de autômatos celulares

Modelagem de emergências

nginx
Copiar
Editar
