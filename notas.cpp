// código retrabalhado usando a função /* laço das gerações */
// for(int i = 0; i < max_geracoes; i++){

    #include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Estabelecendo informações básicas do indivíduo que vamos procurar no mapeamento genético
struct Individuo {
    vector<double> genes;
    double fitness;
};

// Função para realizar o mapeamento genético de um valor
int MapeamentoGenetico(int valor, int minEntrada, int maxEntrada, int minSaida, int maxSaida) {
    return ((valor - minEntrada) * (maxSaida - minSaida)) / (maxEntrada - minEntrada) + minSaida;
}

// Função para inicializar a população com valores aleatórios
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

// Função para avaliar o fitness de cada indivíduo na população
void avaliarFitness(vector<Individuo>& populacao) {
    for (auto& individuo : populacao) {
        // Avalia a função para os genes do indivíduo
        double a = individuo.genes[0];
        double b = individuo.genes[1];
        double c = individuo.genes[2];
        double d = individuo.genes[3];
        double e = individuo.genes[4];
        double f = individuo.genes[5];
        double soma = 0.0;

        for (double x = -10; x <= 10; x += 0.1) {
            double valor = a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f;
            soma += abs(valor);
        }

        individuo.fitness = soma;
    }
}

int main() {
    srand(time(nullptr)); // Inicializa a semente para geração de números aleatórios

    // Declarando os valores utilizados no algoritmo genético
    int tamanhoPopulacao[] = {10, 100, 1000};
    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6;

    for (int tamanho : tamanhoPopulacao) {
        vector<Individuo> populacao;
        inicializarPopulacao(populacao, tamanho, numGenes);

        for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
            avaliarFitness(populacao);

            // Implementação da lógica de seleção, crossover e mutação
            // (Não incluída neste exemplo, deve ser implementada conforme necessário)

            // Exibindo o melhor indivíduo da população
            Individuo melhorIndividuo = populacao[0];
            for (const auto& individuo : populacao) {
                if (individuo.fitness < melhorIndividuo.fitness) {
                    melhorIndividuo = individuo;
                }
            }

            // Exibindo os genes do melhor indivíduo encontrado
            cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
            for (double gene : melhorIndividuo.genes) {
                cout << gene << " ";
            }
            cout << endl;
            cout << "Fitness: " << melhorIndividuo.fitness << endl;
        }
    }

    return 0;
}
