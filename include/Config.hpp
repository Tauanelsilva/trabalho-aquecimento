#ifndef CONFIG_HPP
#define CONFIG_HPP

// Tamanho mínimo da matriz
const int MIN_LINHAS = 5;
const int MIN_COLUNAS = 5;

// Número máximo de interações
const int MAX_INTERACOES = 100;

// Direções do vento
const bool VENTO_CIMA = true;
const bool VENTO_BAIXO = true;
const bool VENTO_ESQUERDA = true;
const bool VENTO_DIREITA = true;

// Caracteres para visualização (opcional)
const char CHAR_VAZIO = '.';
const char CHAR_SAUDE = 'T';
const char CHAR_FOGO = '@';
const char CHAR_QUEIMADA = '#';
const char CHAR_AGUA = '~';
const char CHAR_ANIMAL = 'A';

#endif // CONFIG_HPP
