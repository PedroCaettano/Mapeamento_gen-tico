#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Indivíduo structure
struct Individuo {
    int genes;
    double fitness;
};

// Inicializar população
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

// Avaliar fitness
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

// Seleção
void selecao(Individuo populacao[], Individuo novaPopulacao[], int tamanhoPopulacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        int melhorIndividuo = 0;
        for (int j = 1; j < tamanhoPopulacao; ++j) {
             if (populacao[j].fitness < populacao[melhorIndividuo].fitness) {
                 melhorIndividuo = j;
            }
        }
        novaPopulacao[i] = populacao[melhorIndividuo];
        populacao[melhorIndividuo].fitness = DBL_MAX; // Marcar como já selecionado
    }
}

// Cruzamento
void cruzamento(Individuo populacao[], int tamanhoPopulacao, double taxaCrossover) {
    for (int i = 0; i < tamanhoPopulacao; i += 2) {
        if (rand() % 100 < taxaCrossover * 100) {
            int pontoCorte = rand() % (sizeof(int) * 8); // Escolhe um ponto de corte aleatório
            int pai1 = i;
            int pai2 = i + 1;
            int mascara = (1 << pontoCorte) - 1;

            int novoIndividuo1 = (populacao[pai1].genes & mascara) | (populacao[pai2].genes & ~mascara);
            int novoIndividuo2 = (populacao[pai2].genes & mascara) | (populacao[pai1].genes & ~mascara);

            populacao[pai1].genes = novoIndividuo1;
            populacao[pai2].genes = novoIndividuo2;
        }
    }
}

// Mutação
void mutacao(Individuo populacao[], int tamanhoPopulacao, double taxaMutacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        for (int j = 0; j < sizeof(int) * 8; ++j) {
            if ((rand() % 100) < (taxaMutacao * 100)) {
                populacao[i].genes ^= (1 << j); // Inverte o bit
            }
        }
    }
}

int main() {
    srand(time(nullptr));

    int tamanhoPopulacao;
    cout << "Digite o tamanho da população (10, 100, ou 1000): ";
    cin >> tamanhoPopulacao;

    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6;

    Individuo populacao[tamanhoPopulacao];
    inicializarPopulacao(populacao, tamanhoPopulacao, numGenes);

    double a, b, c, d, e, f;
    cout << "Digite os valores de a, b, c, d, e, f: ";
    cin >> a >> b >> c >> d >> e >> f;

    for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
        avaliarFitness(populacao, a, b, c, d, e, f);

        Individuo novaPopulacao[tamanhoPopulacao];
        selecao(populacao, novaPopulacao, tamanhoPopulacao);
        cruzamento(novaPopulacao, tamanhoPopulacao, taxaCrossover);
        mutacao(novaPopulacao, tamanhoPopulacao, taxaMutacao);

        for (int i = 0; i < tamanhoPopulacao; ++i) {
            populacao[i] = novaPopulacao[i];
            populacao[i].fitness = 0.0; // Resetando fitness para a próxima geração
        }
    }

    Individuo melhorIndividuo = populacao[0];
    for (int i = 1; i < tamanhoPopulacao; ++i) {
        if (populacao[i].fitness < melhorIndividuo.fitness) {
            melhorIndividuo = populacao[i];
        }
    }

    cout << "Melhor indivíduo:" << endl;
    for (int j = numGenes - 1; j >= 0; --j) {
        cout << ((melhorIndividuo.genes >> j) & 1) << " "; // Exibe os bits do melhor indivíduo
    }
    cout << endl;
    cout << "Fitness: " << melhorIndividuo.fitness << endl;

    return 0;
}
