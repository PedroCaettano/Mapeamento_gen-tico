// Salvando este código para trabalhar com futuras alterações

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estrutura do indivíduo com genes representados como bits de um número inteiro
struct Individuo {
    int genes;
    double fitness; // Termo usado para representar uma boa genética dos genes
};

// Função para inicializar a população com indivíduos contendo genes aleatórios
void inicializarPopulacao(Individuo populacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        populacao[i].genes = rand() % 1024; // Genes variam entre 0 e 1023 (bits de 0 a 9)
        populacao[i].fitness = 0.0;
    }
}

// Função para avaliar o fitness de cada indivíduo na população
void avaliarFitness(Individuo populacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int genes = populacao[i].genes;
        // Lógica para calcular o fitness do indivíduo (simplificado para este exemplo)
        populacao[i].fitness = genes * genes; // Exemplo: fitness é o quadrado dos genes
    }
}

// Função de seleção dos indivíduos para cruzamento
void selecao(Individuo populacao[], int tamanhoPopulacao) {
    // Implementação da seleção dos melhores indivíduos para cruzamento (simplificado para este exemplo)
    // Aqui poderia ser implementado um método de seleção mais avançado, como a roleta ou torneio
    // Neste exemplo, selecionamos os 50% melhores indivíduos
    int metade = tamanhoPopulacao / 2;
    for (int i = metade; i < tamanhoPopulacao; ++i) {
        populacao[i].genes = populacao[i - metade].genes; // Cópia dos genes dos melhores indivíduos
    }
}

// Função de cruzamento (crossover) entre os genes dos indivíduos
void cruzamento(Individuo populacao[], int tamanhoPopulacao, double taxaCrossover) {
    for (int i = 0; i < tamanhoPopulacao; i += 2) {
        if (rand() % 100 < taxaCrossover * 100) { // Verifica se o crossover ocorre com base na taxa
            int pontoCorte = rand() % 10; // Ponto de corte para o crossover (entre 0 e 9)
            int genesPai1 = populacao[i].genes;
            int genesPai2 = populacao[i + 1].genes;
            int mascara = (1 << pontoCorte) - 1; // Máscara para o crossover
            int genesFilho1 = (genesPai1 & mascara) | (genesPai2 & ~mascara);
            int genesFilho2 = (genesPai2 & mascara) | (genesPai1 & ~mascara);
            populacao[i].genes = genesFilho1;
            populacao[i + 1].genes = genesFilho2;
        }
    }
}

// Função de mutação dos genes dos indivíduos
void mutacao(Individuo populacao[], int tamanhoPopulacao, double taxaMutacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        if (rand() % 100 < taxaMutacao * 100) { // Verifica se a mutação ocorre com base na taxa
            int bitMutacao = rand() % 10; // Bit aleatório a ser mutado (entre 0 e 9)
            populacao[i].genes ^= (1 << bitMutacao); // Realiza a mutação do bit
        }
    }
}

int main() {
    srand(time(nullptr)); // Inicializa a semente para geração de números aleatórios

    int tamanhoPopulacao = 10;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;

    Individuo populacao[tamanhoPopulacao];
    inicializarPopulacao(populacao, tamanhoPopulacao);

    for (int geracao = 0; geracao < 500; ++geracao) {
        avaliarFitness(populacao, tamanhoPopulacao);
        selecao(populacao, tamanhoPopulacao);
        cruzamento(populacao, tamanhoPopulacao, taxaCrossover


/// Algoritmo Genético:
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Individuo {
    int genes;
    double fitness;
};

void inicializarPopulacao(Individuo populacao[], int tamanhoPopulacao, int numGenes) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        Individuo ind;
        ind.genes = rand() % (1 << numGenes); // Genes as bits representing an integer
        ind.fitness = 0.0;
        populacao[i] = ind;
    }
}

void avaliarFitness(Individuo populacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int a = (populacao[i].genes >> 0) & 1;
        int b = (populacao[i].genes >> 1) & 1;
        int c = (populacao[i].genes >> 2) & 1;
        int d = (populacao[i].genes >> 3) & 1;
        int e = (populacao[i].genes >> 4) & 1;
        int f = (populacao[i].genes >> 5) & 1;

        double soma = 0.0;
        for (double x = -10; x <= 10; x += 0.1) {
            double x2 = x * x;
            double x3 = x2 * x;
            double x4 = x2 * x2;
            double x5 = x4 * x;

            double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
            soma += abs(valor);