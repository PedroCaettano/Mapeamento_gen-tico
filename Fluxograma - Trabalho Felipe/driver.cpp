// Estrutura do trabalho do Felipe

#include <iostream>
using namespace std;

//Realizando uma função para o mapeamento genético
int MapeamentoGenetico(int valor, int minEntrada, int maxEntrada, int minSaida, int maxSaida){
return ((valor - minEntrada) * (maxSaida - minSaida)) / (maxEntrada - minEntrada) + minSaida;
}



// Estabelecendo uma quantidade de valores para população, crossover, mutação e gerações

const int Tam_Populacao = 100;
const double Taxa_De_Crossover = 0.7;
const double Taxa_De_Mutacao = 0.01;
const int max_geracoes = 1000;
 
 
int main(){
// Inicializando o gerador de números aleatórios
srand(time(NULL))


// Declaração de variáveis

// Inicialização das variáveis
   

// gerar aleatoriamente a população inicial

/*laço das gerações*/
for(int i = 0; i<max_geracoes; i++){
//avaliar a população

//armazenar o melhor indivíduo até o momento

//verificar se a solução está aceitável (se sim, encerrar laço)

// selecionar os melhores individuos

//aplicar cruzamento com crossover

//aplicando mutação
}

//imprimir a melhor solução
populacao = nova_polucao;

 return 0;   
}