// Trabalho realizado por:
// Pedro Henrique Caetano Barbosa | 2154635
// Filipe Sanches |


// SOBRE O SISTEMA DE PARTES: Estou me baseando no algoritmo genético presente no material de referência do trabalho.
// Então para eu não me perder com o desenvolvimento do código eu estou definindo parte do fluxograma que estou usando
// para me basear no código do trabalho.

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

// Estabelecendo informações básicas do índividuo que vamos procurar no mapeamento genético
struct Individuo {
       vector<double> Genes;
       int Populacao; 
       double fitness; // Termo usado para significar uma boa forma física
};

// Estabelecendo valores para a entrada/saída de informações no código
int MapeamentoGenetico(int valor, int minEntrada, int maxEntrada, int minSaida, int maxSaida){
return ((valor - minEntrada) * (maxSaida - minSaida)) / (maxEntrada - minEntrada) + minSaida;
}

// Função para inicializar a população com valores aleatórios
void inicializarPopulacao(vector<Individuo>& populacao, int tamanhoPopulacao, int numGenes) {
         for (int i = 0; i < tamanhoPopulacao; ++i) {
        Individuo individuo;
        for (int j = 0; j < numGenes; ++j) {
            IndividuoGenes. push_back(rand() % 200 - 100); // Genes estabelecidos em uma variação entre -100 e 100
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

        // Função realizada para o calculo dos genes
        for (double x = -10; x <= 10; x += 0.1) {
        double x2 = x * x;            // x^2
        double x3 = x2 * x;           // x^3
        double x4 = x2 * x2;          // x^4
        double x5 = x4 * x;           // x^5

    double valor = a * x5 + b * x4 + c * x3 + d * x2 + e * x + f;
    soma += abs(valor);
}
        }

        individuo.fitness = soma;
    }


int main(){
// PARTE 1 Do FLUXOGRAMA - ESTABELECENDO O TAMANHO DE UMA POPULAÇÃO

// Estabelcendo que o código me dará uma ampla variedade de valores
srand(time(NULL));

// Declarando o tamanho máximo de variáveis 
int tamanhoPopulacao = {10, 100, 1000}
int max_Geracoes = 500;
double mutation_taxa = 0,01;
double crossover_taxa = 0,7;
int numGenes = 6; // Número de genes que vamos trabalhar neste código


// PARTE 2 Do FLUXOGRAMA - GERANDO UMA POPULAÇÃO INICIAL

// Iniciando códigos responsáveis pelo calculo do tamanho da população
for(int tamanho: tamanhoPopulacao) {
    vector<Individuo> populacao;
    inicializarPopulacao(tamanhoPopulacao, tamanho, numGenes);

for (int geracao = 0; geracao < max_Geracoes; ++geracao ) {
     avaliarfitness(populacao)
}

void inicializarPopulacao(vector<Individuo>& populacao, int tamanhoPopulacao, int tamanhoGenes) {
     populacao.resize(tamanhoPopulacao, {"A"s + string(tamanhoGenes - 1, 'A'), 0.0});
}

void avaliarFitness(vector<Individuo>& populacao) {
     for (auto& individuo : populacao) {
          individuo.fitness = 0.0;
    }
}

vector<string> selecionarMelhores(const vector<Individuo>& populacao, int numMelhores) {
       vector<string> melhoresIndividuos;
       for (int i = 0; i < numMelhores; ++i) {
       melhoresIndividuos.push_back(populacao[i].genes);
    }
       return melhoresIndividuos;
}

bool verificarSelecao(const vector<string>& melhoresIndividuos) {
return true;
}


// Exibindo o melhor individuo com base nos seus genes
Individuo melhorIndividuo = populacao[0];
          for(const auto&Individuo : populacao) {
          if (Individuo.fitness < melhorIndividuo.fitness) {
              melhorIndividuo = Individuo;
          }
          }

         cout << "Melhor indivíduo para população de tamanho " << tamanho << ":" << endl;
         for (double gene : melhorIndividuo.Genes) {
            cout << gene << " ";
        }
            cout << endl;
            cout << "Fitness: " << melhorIndividuo.fitness << endl;
    }

// PARTE 3 



cout << "Melhores indivíduos selecionados:" << endl;
         for (const auto& individuo : Populacao) {
         cout << individuo.genes << " - Fitness: " << individuo.fitness << endl;
    }
    return 0;
}