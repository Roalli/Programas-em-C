#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

//Classe para conta 
class conta {

    //As variaveis ficaram em public para função transferir 
    //public:
protected:

    string nome;
    int numero;
    float saldo;

    public:

    //Para iniciar as variaveis da classe para colocar o conteudo para dentro
    conta(string nome, int numero, float valor){
        this->nome = nome;
        this->numero = numero;
        this->saldo = valor;
    }

    //Retira o valor da conta da classe
    void debitar(float valor){
        this->saldo -= valor;
    }

    //Acrescenta o valor na conta da classe 
    void creditar(float valor){
        this->saldo += valor;
    }

    //Mostra na tela as informações da conta 
    void imprimir(){

        cout << "\nTitular: " << nome << std::endl;
        cout << "Conta: " << numero << std::endl;
        cout << fixed << setprecision(2) << "Saldo: R$ " << saldo << std::endl << std::endl;
    
    }
friend  void transferir( class conta * contaOrigem, float valor, class conta * contaDestino);

   };
//classe para conta poupança
class conta_poupanca : public conta {
//variavel para a taxa de juros
int taxa_juros;
//os metodos
public:

//o construtor agora incluindo a taxa na variavel 
conta_poupanca(string nome, int numero, float valor, int taxa ) : conta( nome, numero, valor) {
  this->taxa_juros = taxa;
}

//ao receber a quantidade de meses que passou, se realiza uma simples conta de juros simples
void atualizaConta(int mes){

  this->saldo += (this->saldo * ((float)this->taxa_juros / 100) * mes );
  
}

};

//classe para conta corrente
class conta_corrente : public conta {

//variavel para a taxa de juros
int taxa_juros;

public:

//construtor para conta corrente, incluindo a taxa de juros
conta_corrente(string nome, int numero, float valor, int taxa) : conta( nome, numero, valor){

  this->taxa_juros = taxa;
}

//atualiza a conta com a quantidade de meses que se passou
//com uma conta de juros simples, e retirando da conta esse valor
void atualizaConta(int mes){

    this->saldo -= (this->saldo * ((float)this->taxa_juros / 100) * mes );
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

        conta conta1("Joaquim da silva", 1400, 3400); //cria conta 1 e ja a construi
        conta conta2("Pedrinho Gonçalves", 4230, 3100);//crita conta 2 e ja a construi


 

     //mostra os dados da conta 1 e conta 2   
        conta1.imprimir();
        conta2.imprimir();

      //transfere os valores de uma conta para a outra
        transferir(&conta1, 200, &conta2);

      //mostra os saldos
        conta1.imprimir();
        conta2.imprimir();

      //Para a conta poupança
      cout << "\n------conta poupança------\n";
      conta_poupanca conta3("Mario Pedroso", 13200, 10020, 10);
      conta3.imprimir(); // mostra os dados da conta e o saldo

      cout << "\n Após 6 meses de poupança" << std::endl;
      
      conta3.atualizaConta(6);// após 6 meses de juros
      conta3.imprimir();//mostra o saldo

      cout << "\nApós 2 meses de poupança" << std::endl;
      conta3.atualizaConta(2);//Após 2 meses de juros
      conta3.imprimir();//mostra saldo
      

      //Para conta corrente
      cout << "\n------Conta corrente-----\n";
      conta_corrente conta4("Helena da Fonseca", 45003, 2500, 5);
      conta4.imprimir();//mostra saldo

      cout << "\nApós 2 meses de conta corrente" << std::endl;

      conta4.atualizaConta(2);//Após 2 meses de juros
      conta4.imprimir();//mostra saldo

    
      return 0;

    }

            

