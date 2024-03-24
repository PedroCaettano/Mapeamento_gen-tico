// Trabalho Bimestral de Tecnicas de Programação feito por
// Pedro Henrique Caetado | 2154635
// Filipe Sanches

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Estabelecendo informações básicas do índividuo que vamos procurar no mapeamento genético.
struct Individuo {
    int genes;
    double fitness;// Termo usado no trabalho para representar uma boa genética dos genes
};


// Função realizada para o cálculo dos genes
for(double x = -10; x <= 10; x += 0.1) {
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;
    double x5 = x4 * x;

    double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
            soma += abs(valor);
            individuo.fitness = soma;
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
        }
    }

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



int main(){
srand(time(nullptr));

// Código responsável para o usuário escolher qual o tamanho da população ele deseja trabalhar.
int tamanhoPopulacao;
    cout << "Digite o tamanho da população (10, 100, ou 1000): "<<std;
    cin >> tamanhoPopulacao >>std;

// Declaração do tamanho máximo de variáveis que estão presentes no código
 int maxGeracoes = 500;
     double taxaMutacao = 0.01;
     double taxaCrossover = 0.7;
     int numGenes = 6;

    Individuo populacao[tamanhoPopulacao];
    inicializarPopulacao(populacao, tamanhoPopulacao, numGenes);

// Comando dado para o usuário inserir quais valores ele deseja.
    double a, b, c, d, e, f;
    cout << "Digite os valores de a, b, c, d, e, f: ";
    cin >> a >> b >> c >> d >> e >> f;

// Informando ao usuário os valores da seleção, cruzamento e mutação desses genes
    for (int geracao = 0; geracao < maxGeracoes; ++geracao) {
        avaliarFitness(populacao, a, b, c, d, e, f);

        Individuo novaPopulacao[tamanhoPopulacao];
        selecao(populacao, novaPopulacao, tamanhoPopulacao);
        cruzamento(novaPopulacao, tamanhoPopulacao, taxaCrossover);
        mutacao(novaPopulacao, tamanhoPopulacao, taxaMutacao);



  cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
        for (int i = 0; i < numGenes; ++i) {
            cout << ((melhorIndividuo.genes >> i) & 1) << " ";
        }
        cout << endl;
        cout << "Fitness: " << melhorIndividuo.fitness << endl;
return 0;
}

}