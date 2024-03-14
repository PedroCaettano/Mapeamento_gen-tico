#include <iostream>
using namespace std;

bool isEven(int n){
     char str[4] ="Oi";
     cout<<str<<endl;
     for(int i=0; i< 300; i++) {
         str[i]='A'; // Isso aqui é como se eu tivesse um Gets com 'A' sendo repetido milhares de vezes
     }
     return n%2==0;

}

int main(){
    cout <<"Teste de aplicacao!" << endl;
    cout <<"Digite um valor: ";
    int numero;
    cin >> numero; // lendo um valor de um dispositivo de entrada padrão
    // sempre forneça sua forma de cálculo e a forma como você realiza os cálculo 
     
    if(isEven(numero)) cout<<"O numero"<<numero<<"eh par!"<<endl;
       else cout<<"O numero"<<numero<<"eh impar!"<<endl;
}