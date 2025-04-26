 README - Simulador de Propagação de Fogo em Floresta com Comportamento Animal 🔥
Aluno: Tauane Luísa Silva
Professor: Michel Pires da Silva
Disciplina: Algoritmos e Estruturas de Dados I

📌 Introdução
Este projeto simula a propagação de fogo em uma floresta representada por uma matriz, enquanto um animal se movimenta estrategicamente para sobreviver. O sistema modela:

Dinâmica do fogo: Influenciada por direções do vento (configuráveis).

Comportamento do animal: Movimentação inteligente baseada em prioridades de terreno.

Geração de relatórios: Logs detalhados em output.dat e visualização no terminal.

🎯 Objetivos
Simular a propagação de fogo com/sem influência do vento.

Implementar algoritmos de movimentação autônoma para o animal.

Analisar a eficiência computacional das estruturas de dados utilizadas.

🛠️ Funcionalidades
🌳 Floresta
Matriz dinâmica com estados:

0: Área vazia (segura)

1: Árvore saudável

2: Fogo ativo

3: Árvore queimada

4: Água (protege adjacências).

Propagação do fogo em direções configuráveis (Config.hpp).

🦊 Animal
Prioridades de movimento: Água > Vazio > Árvore saudável > Queimada.

Segunda chance: Sobrevive uma vez ao fogo antes de morrer.

Estatísticas: Registro de passos, água encontrada e iteração de morte.

📊 Saída
Arquivo output.dat com:

Estado da floresta por iteração.

Posição do animal (A).

Resumo final (sobrevivência, passos, etc.).

⚙️ Configuração
Edite Config.hpp para ajustar:

cpp
const bool VENTO_CIMA = true;     // Vento para cima  
const bool VENTO_BAIXO = true;    // Vento para baixo  
const int MAX_INTERACOES = 100;   // Limite de iterações  
const char CHAR_FOGO = '🔥';      // Símbolo do fogo no terminal  
📂 Estrutura do Projeto
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
🚀 Compilação e Execução
Método 1: Compilação Direta
bash
g++ -std=c++11 src/*.cpp -I include -o simulador  
./simulador  
Método 2: Com CMake
bash
mkdir build && cd build  
cmake ..  
make  
./simulador  
📊 Exemplo de Entrada (input.dat)
5 5 2 2          # 5x5 matriz, fogo inicia em (2,2)
1 1 1 1 1        # Matriz da floresta:
1 0 4 0 1        # 0 = Vazio, 1 = Árvore, 4 = Água
1 1 2 1 1  
1 0 0 0 1  
1 1 1 1 1  
🖥️ Saída no Terminal
--- Iteração 0 ---
1 1 1 1 1  
1 0 A 0 1  
1 1 🔥 1 1  
1 0 0 0 1  
1 1 1 1 1  

[!] Animal usou segunda chance ao escapar do fogo!
📌 Casos de Teste
1. Propagação com Vento
Entrada: Fogo em (1,1) com vento para a direita.

Saída: Fogo se propaga apenas para a direita (VENTO_DIREITA=true).

2. Animal Preso
Cenário: Floresta 3x3 com fogo ao redor do animal.

Resultado: Animal morre na iteração 3.

📈 Melhorias Futuras
Otimização: Usar std::queue para células em chamas (evita varrer matriz inteira).

Visualização: Gráficos em tempo real com SFML ou OpenGL.

Estatísticas: Calcular porcentagem de área queimada por iteração.

📝 Conclusão
O projeto aplicou conceitos de:

Manipulação de matrizes (propagação do fogo).

Tomada de decisão (movimento do animal).

Modularização (separação em classes).

👨‍💻 Autor
Tauane Luísa Silva
