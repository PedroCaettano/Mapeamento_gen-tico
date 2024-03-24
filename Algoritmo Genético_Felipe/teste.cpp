#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Individuo {
    int genes;
    double fitness;
};

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

void selecao(Individuo populacao[], Individuo novaPopulacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int melhorIndividuo = 0;
        for (int j = 1; j < tamanhoPopulacao; ++j) {
            if (populacao[j].fitness < populacao[melhorIndividuo].fitness) {
                melhorIndividuo = j;
            }
        }
        novaPopulacao[i] = populacao[melhorIndividuo];
        populacao[melhorIndividuo].fitness = numeric_limits<double>::max();
    }
}

void cruzamento(Individuo populacao[], int tamanhoPopulacao, double taxaCrossover) {
    for (int i = 0; i < tamanhoPopulacao; i += 2) {
        if ((rand() % 100) / 100.0 < taxaCrossover) {
            int pontoCorte = rand() % (sizeof(int) * 8);
            int pai1 = populacao[i].genes;
            int pai2 = populacao[i + 1].genes;
            int mask = (1 << pontoCorte) - 1;
            int filho1 = (pai1 & mask) | (pai2 & ~mask);
            int filho2 = (pai2 & mask) | (pai1 & ~mask);
            populacao[i].genes = filho1;
            populacao[i + 1].genes = filho2;
        }
    }
}

void mutacao(Individuo populacao[], int tamanhoPopulacao, double taxaMutacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        for (int j = 0; j < sizeof(int) * 8; ++j) {
            if ((rand() % 100) / 100.0 < taxaMutacao) {
                populacao[i].genes ^= 1 << j;
            }
        }
    }
}

int main() {
    srand(time(nullptr));

    int tamanhosPopulacao[] = {10, 100, 1000};
    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6;

    for (int tamanho : tamanhosPopulacao) {
        Individuo populacao[tamanho];
        inicializarPopulacao(populacao, tamanho, numGenes);

        for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
            double a = rand() % 200 - 100;
            double b = rand() % 200 - 100;
            double c = rand() % 200 - 100;
            double d = rand() % 200 - 100;
            double e = rand() % 200 - 100;
            double f = rand() % 200 - 100;

            avaliarFitness(populacao, a, b, c, d, e, f);
            Individuo novaPopulacao[tamanho];
            selecao(populacao, novaPopulacao, tamanho);
            cruzamento(novaPopulacao, tamanho, taxaCrossover);
            mutacao(novaPopulacao, tamanho, taxaMutacao);
            for (int i = 0; i < tamanho; ++i) {
                populacao[i] = novaPopulacao[i];
            }
        }

        Individuo melhorIndividuo = populacao[0];
        for (int i = 1; i < tamanho; ++i) {
            if (populacao[i].fitness < melhorIndividuo.fitness) {
                melhorIndividuo = populacao[i];
            }
        }

        cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
        for (int i = 0; i < numGenes; ++i) {
            cout << ((melhorIndividuo.genes >> i) & 1) << " ";
        }
        cout << endl;
        cout << "Fitness: " << melhorIndividuo.fitness << endl;
    }

    return 0;
}
