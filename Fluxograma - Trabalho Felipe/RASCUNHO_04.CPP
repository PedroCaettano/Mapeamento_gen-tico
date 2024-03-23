#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



// Função realizada para o calculo dos genes
        for (double x = -10; x <= 10; x += 0.1) {
            double x2 = x * x;
            double x3 = x2 * x;
            double x4 = x2 * x2;
            double x5 = x4 * x;

            double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
            soma += abs(valor);
        }

int main (){


// Exibindo o melhor individuo com base nos seus genes
        cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
        for (double gene : melhorIndividuo.genes) {
            cout << gene << " ";
        }
        cout << endl;
        cout << "Fitness: " << melhorIndividuo.fitness << endl;
    }


return 0;
}


//////////////////////////
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Individuo structure
struct Individuo {
    int genes;
    double fitness;
};

// Initialize population
void inicializarPopulacao(Individuo populacao[], int tamanhoPopulacao, int numGenes) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int individualGenes = 0;
        for (int j = 0; j < numGenes; ++j) {
            individualGenes = (individualGenes << 1) | (rand() % 2);
        }
        populacao[i].genes = individualGenes;
        populacao[i].fitness = 0.0;
    }
}

// Evaluate fitness
void avaliarFitness(Individuo populacao[], double a, double b, double c, double d, double e, double f) {
    for (int i = 0; i < 1000; ++i) {
        double x = -10 + i * 0.02;
        double x2 = x * x;
        double x3 = x2 * x;
        double x4 = x2 * x2;
        double x5 = x4 * x;

        double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
        populacao[i].fitness += abs(valor);
    }
}

// Selection
void selecao(Individuo populacao[], Individuo novaPopulacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int melhorIndividuo = 0;
        for (int j = 1; j < tamanhoPopulacao; ++j) {
            if (pop