#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Individuo {
    vector<double> genes;
    double fitness;
};

void inicializarPopulacao(vector<Individuo>& populacao, int tamanhoPopulacao, int numGenes) {
        for (int i = 0; i < tamanhoPopulacao; ++i) {
        Individuo individuo;
        for (int j = 0; j < numGenes; ++j) {
            individuo.genes.push_back(rand() % 200 - 100); // Genes variando entre -100 e 100
        }
        individuo.fitness = 0.0;
        populacao.push_back(individuo);
    }
}

void avaliarFitness(vector<Individuo>& populacao) {
    for (auto& individuo : populacao) {
        double a = individuo.genes[0];
        double b = individuo.genes[1];
        double c = individuo.genes[2];
        double d = individuo.genes[3];
        double e = individuo.genes[4];
        double f = individuo.genes[5];
        double soma = 0.0;

        for (double x = -10; x <= 10; x += 0.1) {
            double x2 = x * x;
            double x3 = x2 * x;
            double x4 = x2 * x2;
            double x5 = x4 * x;

            double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
            soma += abs(valor);
        }

        individuo.fitness = soma;
    }
}

int main() {
    srand(time(nullptr));

    vector<int> tamanhosPopulacao = {10, 100, 1000};
    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6;

    for (int tamanho : tamanhosPopulacao) {
        vector<Individuo> populacao;
        inicializarPopulacao(populacao, tamanho, numGenes);

        for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
            avaliarFitness(populacao);
        }

        Individuo melhorIndividuo = populacao[0];
        for (const auto& individuo : populacao) {
            if (individuo.fitness < melhorIndividuo.fitness) {
                melhorIndividuo = individuo;
            }
        }

        cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
        for (double gene : melhorIndividuo.genes) {
            cout << gene << " ";
        }
        cout << endl;
        cout << "Fitness: " << melhorIndividuo.fitness << endl;
    }

    return 0;
}
