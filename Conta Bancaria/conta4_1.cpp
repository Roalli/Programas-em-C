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

virtual void atualizaConta( int mes ) = 0;

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

//Funções

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

//Fim das funções


    int main(){

        int tamanho = 0; // variavel para o tamanho do vetor da conta. 

        //Variaveis para atribuir as informações para cada conta em seu construtor.
        string nome_temporario;
        int numero_temporario;
        float valor_temporario;
        int taxa_temporaria;
        int opcao;// Para atribuir a opção que ira escolher o tipo de conta.

        cout << "\n\n\nDigite quantas contas ira ter no programa: ";
        cin >> tamanho;
        cout << "\n\n";


      conta * contas[tamanho];//criando ponteiro num vetor para tipo conta 

      for( int cont = 0; cont < tamanho; cont++){//coletando informações para as contas.

          cout << "------Conta " << cont+1 << "------"  << endl << endl;
          cout << "Digite o nome: ";
          cin >> nome_temporario;
          cout << endl << "Digite o numero da conta: ";
          cin >> numero_temporario;
          cout << endl << "Digite o valor: ";
          cin >> valor_temporario;
          cout << endl << "Digite a taxa do juros: ";
          cin >> taxa_temporaria;

          cout << endl << "Escolha o tipo de conta para ser criada" << endl << "1 - Conta Poupança\n2 - Conta Corrente" << endl;
          cout << endl << "Opção: ";
          cin >> opcao;

          if( opcao == 1 ){//cria uma conta do tipo poupança.

              contas[cont] = new conta_poupanca( nome_temporario, numero_temporario, valor_temporario, taxa_temporaria);
          }

          if ( opcao == 2 ){//cria uma conta do tipo corrente.

              contas[cont] = new conta_corrente( nome_temporario, numero_temporario, valor_temporario, taxa_temporaria);

          }
      }

//ira listar em ordem as contas correntes e as contas poupanças.
  
      cout << "------Listando contas correntes------" << endl;
      int i = 0;
      
      //Teste para conta corrente.
      for( int cont = 0; cont < tamanho; cont ++){

        
        
        if(dynamic_cast <conta_corrente *>(contas[cont]) !=NULL ){//caso apresentar diferente que nulo
                                                                  //para conta corrente.

          i ++;

          cout << "A conta " << i << endl;
          contas[cont]->imprimir();
          cout << endl;
          
          
        }
       
      }

      cout << "------Listando contas poupança------" << endl;

       i = 0;
      
       //Teste para conta poupança.
      for( int cont = 0; cont < tamanho; cont ++){

        
      if(dynamic_cast <conta_poupanca *> (contas[cont]) !=NULL){

          i ++;

          cout << "A conta " << i << endl;
          contas[cont]->imprimir();
          cout << endl;
      }
      }


      int mes_conta = 0;// variavel para quantos meses que ira se passar para a taxa de juros.

      cout << "\n\n\nDigite quantos meses que ira passar para acumular juros para as devidas contas: ";
      cin >> mes_conta;

      for ( int cont = 0; cont < tamanho ; cont ++ ){//ira atualizar todas as contas

          contas[cont]->atualizaConta(mes_conta);
      }

      cout << "\n\nApos " << mes_conta << " mes(es):"<< endl << endl;

//ira listar em ordem as contas correntes e as contas poupanças.
  
      cout << "------Listando contas correntes------" << endl;
      i = 0;
      
      //Teste para conta corrente.
      for( int cont = 0; cont < tamanho; cont ++){

        
        
        if(dynamic_cast <conta_corrente *>(contas[cont]) !=NULL ){//caso apresentar diferente que nulo
                                                                  //para conta corrente.

          i ++;

          cout << "A conta " << i << endl;
          contas[cont]->imprimir();
          cout << endl;
          
          
        }
       
      }

      cout << "------Listando contas poupança------" << endl;

       i = 0;
      
       //Teste para conta poupança.
      for( int cont = 0; cont < tamanho; cont ++){

        
      if(dynamic_cast <conta_poupanca *> (contas[cont]) !=NULL){

          i ++;

          cout << "A conta " << i << endl;
          contas[cont]->imprimir();
          cout << endl;
      }
      }

     

      return 0;

    }

            
