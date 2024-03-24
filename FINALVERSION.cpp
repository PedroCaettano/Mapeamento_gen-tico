// Glossário do código:
// Fitness: Termo usado no código do trabalho para representar uma boa genética dos genes
// Mascara: Termo usado para se referir um valor binário
// Individuo: Termo usado para referenciar uma solução em potencial do problema em questão
// GenesPai 1 e 2: Termos usados com o intenção de simplificar o exemplo do algoritmo genético.
// PontoCorte: Termo usado para referir-se a um ponto de corte específico que ocorre nos genes dos pais onde ocorre o crossover

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Estabelecendo informações importantes sobre os genes do código
struct Individuo {
    int genes;
    double fitness; 
};

// Função usada para realizar o mapeamento genético de um valor.
// Colocado logo no começo do código  por conta de seu tamanho e fácil localização
    int MapeamentoGenetico(int valor, int minEntrada, int maxEntrada, int minSaida, int maxSaida) {
    return ((valor - minEntrada) * (maxSaida - minSaida)) / (maxEntrada - minEntrada) + minSaida;
}

// Avaliação de Fitness de cada individuo da população
void avaliarFitness(Individuo populacao[], int tamanhoPopulacao, double a, double b, double c, double d, double e, double f) {
     for (int i = 0; i < tamanhoPopulacao; ++i) {
        int aBit = (populacao[i].genes >> 0) & 1;
        int bBit = (populacao[i].genes >> 1) & 1;
        int cBit = (populacao[i].genes >> 2) & 1;
        int dBit = (populacao[i].genes >> 3) & 1;
        int eBit = (populacao[i].genes >> 4) & 1;
        int fBit = (populacao[i].genes >> 5) & 1;

        double soma = 0.0;
        for (double x = -10; x <= 10; x += 0.1) {
            double x2 = x * x;
            double x3 = x2 * x;
            double x4 = x2 * x2;
            double x5 = x4 * x;

            double valor = aBit * x5 + bBit * x4 + cBit * x3 + dBit * x2 + eBit * x + fBit;
            soma += abs(valor);
        }

        populacao[i].fitness = soma;
    }
}

// Realizando o crossover entre os genes dos indivíduos
void cruzamento(Individuo populacao[], int tamanhoPopulacao, double taxaCrossover) {
    for (int i = 0; i < tamanhoPopulacao; i += 2) {
         if (rand() % 100 < taxaCrossover * 100) {
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

// Realizando a função de seleção dos indivíduos para cruzamento
void selecao(Individuo populacao[], int tamanhoPopulacao) {

// Neste exemplo, selecionamos os 50% melhores indivíduos presentes
     int metade = tamanhoPopulacao / 2;
     for (int i = metade; i < tamanhoPopulacao; ++i) {
     populacao[i].genes = populacao[i - metade].genes; // Cópia dos genes dos melhores indivíduos
    }
}

// Realizando a função de mutação dos genes dos indivíduos
    void mutacao(Individuo populacao[], int tamanhoPopulacao, double taxaMutacao) {
    for (int i = 0; i < tamanhoPopulacao; ++i) {
         if (rand() % 100 < taxaMutacao * 100) {
         int bitMutacao = rand() % 10; // Bit aleatório a ser mutado (entre 0 e 9)
             populacao[i].genes ^= (1 << bitMutacao); // Realiza a mutação do bit
        }
    }
}



int main (){
srand(time(nullptr));

    int tamanhoPopulacao;
    cout << "Digite o tamanho da população (10, 100, ou 1000): ";
    cin >> tamanhoPopulacao;

//Estabelecendo o tamanho máximo dos valores máximos presentes no tamanho da população
    int maxGeracoes = 500;
    double taxaMutacao = 0.01;
    double taxaCrossover = 0.7;
    int numGenes = 6; // // Número de genes que vamos trabalhar neste código

    double a, b, c, d, e, f;
    cout << "Digite os valores de a, b, c, d, e, f: ";
    cin >> a >> b >> c >> d >> e >> f;

//Inicialização da população
Individuo populacao[tamanhoPopulacao];
    for (int i = 0; i < tamanhoPopulacao; ++i) {
    populacao[i].genes = rand() % 64; // Cada gene é representado por 6 bits
    avaliarFitness(populacao, tamanhoPopulacao, a, b, c, d, e, f); // Calcula o fitness de cada indivíduo
    }

    for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
    selecao(populacao, tamanhoPopulacao); // Seleciona os melhores indivíduos
    cruzamento(populacao, tamanhoPopulacao, taxaCrossover); // Realiza o crossover entre os genes
    mutacao(populacao, tamanhoPopulacao, taxaMutacao); // Aplica a mutação nos genes

// Avaliação do fitness dos indivíduos após as operações
    for (int i = 0; i < tamanhoPopulacao; ++i) {
    avaliarFitness(populacao,tamanhoPopulacao, a, b, c, d, e, f);
        }
    }


//Encontrando o melhor Indivíduo com o passar das gerações
    Individuo melhorIndividuo = populacao[0];
    for (int i = 1; i < tamanhoPopulacao; ++i) {
        if (populacao[i].fitness < melhorIndividuo.fitness) {
            melhorIndividuo = populacao[i];
        }
    }

// Exibindo o melhor Indivíduo e seus valores
    cout << "Melhor indivíduo:" << endl;
    for (int i = 0; i < numGenes; ++i) {
    cout << ((melhorIndividuo.genes >> i) & 1) << " "; // Exibe os bits do melhor indivíduo
    }
    cout << endl;
    cout << "Fitness: " << melhorIndividuo.fitness << endl;

return 0;    
}
