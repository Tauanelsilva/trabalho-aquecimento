🔥 Simulador de Propagação de Fogo em Floresta com Comportamento Animal 🔥
Aluno: Tauane Luísa Silva
Professor: Michel Pires da Silva
Disciplina: Algoritmos e Estruturas de Dados I

📚 Índice
Introdução

Objetivos

Funcionalidades

Estrutura do Projeto

Configuração

Compilação e Execução

Formatos de Arquivos

Lógica de Implementação

Casos de Teste

Melhorias Futuras

Como Contribuir

Licença

Conclusão

🌍 Introdução
Este projeto simula a propagação de fogo em uma floresta representada por uma matriz bidimensional, enquanto um animal inteligente tenta sobreviver ao desastre. Desenvolvido em C++, o sistema utiliza:

Matrizes dinâmicas para representação do ambiente.

Algoritmos de propagação condicional baseados na direção do vento.

Sistema de prioridades para tomada de decisão do animal.

Gerenciamento de arquivos para entrada/saída de dados.

A ideia é criar um ambiente interativo e educativo que pode ser utilizado tanto para simulações em ecossistemas quanto para análise de emergências, proporcionando uma ferramenta para estudar a dinâmica de incêndios e comportamentos animais sob situações extremas.

🎯 Objetivos
Modelar a propagação realista de fogo considerando:

Direção e intensidade do vento.

Tipos de terreno (árvores saudáveis, áreas queimadas, água).

Implementar um sistema autônomo para o animal com:

Comportamento estratégico.

Mecanismo de "segunda chance".

Coleta de estatísticas de desempenho.

Fornecer ferramentas para análise:

Visualização em tempo real.

Geração de relatórios detalhados.

Configuração flexível de parâmetros.

✨ Funcionalidades
🌳 Sistema de Floresta
Matriz dinâmica com 5 estados:

cpp
Copiar
Editar
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

Água (4) - Converte para área segura.

Vazio (0) - Movimento seguro.

Árvore saudável (1) - Risco futuro.

Queimada (3) - Última opção.

Mecanismo de sobrevivência:

Segunda chance ao encontrar fogo.

Registro de iteração da morte.

📊 Sistema de Saída
Terminal:

Visualização com símbolos personalizáveis.

Cores para diferentes estados (opcional).

Arquivos:

output.dat com histórico completo.

Estatísticas finais detalhadas.

📂 Estrutura do Projeto
plaintext
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
Requisitos
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
plaintext
Copiar
Editar
LINHAS COLUNAS X_FOGO Y_FOGO
MATRIZ_DA_FLORESTA...
Exemplo:

plaintext
Copiar
Editar
5 5 2 2
1 1 1 1 1
1 0 4 0 1
1 1 2 1 1
1 0 0 0 1
1 1 1 1 1
Saída (output/output.dat)
plaintext
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

plaintext
Copiar
Editar
3 3 1 1
1 1 1
1 2 1 
1 1 1
Saída no Terminal:

plaintext
Copiar
Editar
Iteração 0    Iteração 1    Iteração 2
🌲🌲🌲        🌲🔥🌲        💀💀💀
🌲🔥🌲   →   💀💀💀   →   💀💀💀
🌲🌲🌲        🌲🔥🌲        💀💀💀
Caso 2: Sobrevivência do Animal
Cenário:

Animal começa em (0,0).

Água em (1,2).

Fogo se propaga da direita.

Resultado:

Animal encontrou água na iteração 3!

Sobreviveu: Sim.

Água encontrada: 1.

🔮 Melhorias Futuras
Otimização: Usar std::queue para células em chamas e implementar multithreading.

Visualização: Interface gráfica com SFML ou OpenGL para animações de propagação.

Funcionalidades: Adicionar múltiplos animais, diferentes tipos de vegetação e umidade variável.

Análise Científica: Exportar dados para Python e gerar gráficos de propagação.

🤝 Como Contribuir
Contribuições são bem-vindas! Para contribuir com este projeto, siga estas etapas:

Faça um fork deste repositório.

Crie uma nova branch (git checkout -b feature-xyz).

Realize as modificações desejadas.

Teste as suas alterações localmente.

Envie um pull request explicando as modificações realizadas.

Diretrizes de Contribuição:

Siga o estilo de codificação usado no projeto.

Adicione comentários e documentação para suas alterações.

Verifique se todos os testes passam antes de enviar o pull request.

📝 Licença
Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para mais detalhes.

🏁 Conclusão
Este projeto demonstra competência em:

Projeto de sistemas complexos em C++.

Uso eficiente de estruturas de dados.

Implementação de algoritmos de simulação.

Boas práticas de organização de código.

As técnicas aplicadas podem ser estendidas para simulações ecológicas mais complexas e sistemas de autômatos celulares, oferecendo diversas possibilidades de aplicação no estudo de emergências e comportamentos ecológicos.
