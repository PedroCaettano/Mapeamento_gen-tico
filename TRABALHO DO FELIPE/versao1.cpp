


#include <iostream>
#include <string>
#include <limits>
// possivelmente ofstream
// possivelmente fstream

using namespace std; 

// Void estbelecendo a dimensão das fotos

// Void com a conversão dos byes para a tabela ASCII

// ASCII GRADIENTE
// DEFINIÇÃO DE STRING
// DEFINIÇÃO DA MAIOR CONSTANTE QUE TEM NA GRADE

//Arquivos Sequencial
// inClientFile.seekg -> Uma Alternativa interessante
// ios:: beg,cur, end -> Alternativas interessantes para pontos no trabalho

// Rascunho do conversor para a Tabela ASCII
const std::string ASC_TABLE = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`.";

char byteToAscChar(unsigned char byte) {
    // Calculate index proportional to the byte value
    size_t index = static_cast<size_t>((byte / 255.0) * (ASC_TABLE.size() - 1));
    return ASC_TABLE[index];
}


int main() {
// Duas funções que chamamos quando inicializamos com o valor de altura e largura
// inicializamos com zero, depois chamamos a função que vai puxar os valores da imagem a partir do arquivo.rar. Abrimos para a entrada para ir pro programa
// após isso pegamos os dados 
// Entrada: Altura_Largura;
// Fecha essa função para converter de bytes para ASCII

// for de altura e largura para conversão de byte para ASCII

// NÃO INVERTA ALTURA E LARGURA


// Funções de Largura e Altura com valores nulos
// Chama função que lê a dimensão da imagem. Ele chama a função onde converte bit para ASCII


};