#include <iostream>
#include <string.h>

using namespace std;

//Classe para conta 
class conta {

    //As variaveis ficaram em public para função transferir 
    public:

    string nome;
    int numero;
    float saldo;

    public:

    //Para iniciar as variaveis da classe para colocar o conteudo para dentro
    void inicializar(string nome, int numero, float valor){
        (*this).nome = nome;
        (*this).numero = numero;
        (*this).saldo = valor;
    }

    //Retira o valor da conta da classe
    void debitar(float valor){
        (*this).saldo -= valor;
    }

    //Acrescenta o valor na conta da classe 
    void creditar(float valor){
        (*this).saldo += valor;
    }

    //Mostra na tela as informações da conta 
    void imprimir(){

        cout << "\nTitular: " << nome << std::endl;
        cout << "Conta: " << numero << std::endl;
        cout << "Saldo: R$ " << saldo << std::endl << std::endl;
    
    }

   };
//fim da classe 

//Transfere valores de uma conta para outra
    void transferir( class conta * contaOrigem, float valor, class conta * contaDestino){

        if(contaOrigem->saldo >= valor){

            cout << "\nTransferencia de R$ " << valor << " para " << contaDestino->nome << std::endl << std::endl;
          
            contaOrigem->debitar(valor);
            contaDestino->creditar(valor);
            

            cout << "Transferencia realizada" << std::endl;

        }else{
            cout << "\nNão possui saldo o suficiente" << std::endl;
        }
    }
 

    int main(){

        conta conta1; //cria conta 1 
        conta conta2;//crita conta 2 

        //inicia com os conteudos na conta 1 e conta 2 
        conta1.inicializar("Joaquim da silva", 1400, 3400);
        conta2.inicializar("Pedrinho Gonçalves", 4230, 3100);

     //mostra os dados da conta 1 e conta 2   
        conta1.imprimir();
        conta2.imprimir();

        transferir(&conta1, 200, &conta2);
        
        conta1.imprimir();
        conta2.imprimir();

    }

            

        
