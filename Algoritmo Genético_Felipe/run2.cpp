#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estabelecendo informações básicas do indivíduo que vamos procurar no mapeamento genético.
struct Individuo {
    int genes;
    double fitness; // Termo usado no trabalho para representar uma boa genética dos genes
};

// Função para calcular o fitness de um indivíduo com base nos seus genes
void calcularFitness(Individuo& individuo, double a, double b, double c, double d, double e, double f) {
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

// Função de seleção dos indivíduos para cruzamento
void selecao(Individuo populacao[], int tamanhoPopulacao) {
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

// Função para mapeamento genético de um valor
int MapeamentoGenetico(int valor, int minEntrada, int maxEntrada, int minSaida, int maxSaida) {
    return ((valor - minEntrada) * (maxSaida - minSaida)) / (maxEntrada - minEntrada) + minSaida;
}

int main() {
    srand(time(nullptr));

    // Tamanho da população escolhido pelo usuário
    int tamanhoPopulacao;
    cout << "Digite o tamanho da população (10, 100, ou 1000): ";
    cin >> tamanhoPopulacao;

    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6;

    // Valores a serem fornecidos pelo usuário
    double a, b, c, d, e, f;
    cout << "Digite os valores de a, b, c, d, e, f: ";
    cin >> a >> b >> c >> d >> e >> f;

    // Inicialização da população
    Individuo populacao[tamanhoPopulacao];
    for (int i = 0; i < tamanhoPopulacao; ++i) {
        populacao[i].genes = rand() % 64; // Cada gene é representado por 6 bits
        calcularFitness(populacao[i], a, b, c, d, e, f); // Calcula o fitness de cada indivíduo
    }

    for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
        selecao(populacao, tamanhoPopulacao); // Seleciona os melhores indivíduos
        cruzamento(populacao, tamanhoPopulacao, taxaCrossover); // Realiza o crossover entre os genes
        mutacao(populacao, tamanhoPopulacao, taxaMutacao); // Aplica a mutação nos genes

        // Avalia o fitness dos indivíduos após as operações
        for (int i = 0; i < tamanhoPopulacao; ++i) {
            calcularFitness(populacao[i], a, b, c, d, e, f);
        }
    }

    // Encontra o melhor indivíduo após as gerações
    Individuo melhorIndividuo = populacao[0];
    for (int i = 1; i < tamanhoPopulacao; ++i) {
        if (populacao[i].fitness < melhorIndividuo.fitness) {
            melhorIndividuo = populacao[i];
        }
    }

    // Exibe o melhor indivíduo e seu fitness
    cout << "Melhor indivíduo:" << endl;
    for (int i = 0; i < numGenes; ++i) {
        cout << ((melhorIndividuo.genes >> i) & 1) << " "; // Exibe os bits do melhor indivíduo
    }
    cout << endl;
    cout << "Fitness: " << melhorIndividuo.fitness << endl;

    return 0;
}
