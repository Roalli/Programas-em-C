#include <iostream>
#include <string.h>
#include <iomanip>
#include <locale.h>

using namespace std;

//Classe para conta 
class conta {

    //As variaveis ficaram em protected para função transferir poder usar as variaveis
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

    void mostranome(){
        cout << this->nome;
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

//Funcão que ira listar em ordem as contas correntes e as contas poupanças.
  
void listar_contas( int tamanho, conta ** contas){
      cout << "------Listando contas correntes------" << endl;
      
      //Teste para conta corrente.
      for( int cont = 0; cont < tamanho; cont ++){
  
        if(dynamic_cast <conta_corrente *>(contas[cont]) !=NULL ){//caso apresentar diferente que nulo
                                                                  //para conta corrente.
            
          cout << "A conta " << cont+1 << endl;
          contas[cont]->imprimir();
          cout << endl;
          
          
        }
       
      }

      cout << "------Listando contas poupança------" << endl;

       //Teste para conta poupança.
      for( int cont = 0; cont < tamanho; cont ++){

        
      if(dynamic_cast <conta_poupanca *> (contas[cont]) !=NULL){

          cout << "A conta " << cont+1 << endl;
          contas[cont]->imprimir();
          cout << endl;
      }
      }
}

void listar(int tamanho, conta ** elemento){

    for( int cont = 0 ; cont < tamanho; cont++){

        cout << "\n\nConta " << cont+1;
        elemento[cont]->imprimir();
    }


}

//Um menu de seleção para o usuario
void menu (int tamanho, conta ** elemento){

    int opcao = 0;// variavel que sera usada para selecionar as opções e usada dentro do switc
    int opcao2;
    int numconta;
    float valor;

    while( opcao != 4){
    cout << "\n\n\n-------- Menu das contas --------\n\n\n";
    cout << "1 - Listar as Contas\n2 - Escolher uma conta\n3 - Atualizar as contas\n4 - Sair\n\n";
    cout << "Digite a opção: ";
    cin >> opcao;

    switch (opcao){
        case 1://Listar as contas

            listar( tamanho, elemento ); break;

        case 2: //escolher uma conta 
                cout << "\nDigite a conta: ";
                cin >> numconta;

                 while ( numconta > tamanho+1 || numconta <= 0 ){//teste para ver se existe uma conta assim
                            
                        cout << "\nInvalido\n"<< "Digite uma conta valida: ";
                        cin >> numconta;
                    }

                numconta-= 1;

                cout << "\n\nA conta escolhida foi de ";
                elemento[numconta]->mostranome() << "\n\n\n";//mostra o nome da conta escolhida 

                opcao2 = 0;//zera a variavel por estar num laço

                while(opcao2 != 5){//dentro das opção da conta 
                
                cout << "\n\n\n--------Opções da conta--------\n\n";
                cout << "1 - Mostrar conta\n2 - Creditar\n3 - Debitar\n4 - Transferencia\n5 - Voltar\n\n";
                cout << "Digite a opção:";
                cin >> opcao2;q

                switch (opcao2){//nas escolhas das opções da conta 
                    case 1://mostrar conta 
                        elemento[numconta]->imprimir();
                        break;

                    case 2://creditar
                        cout << "Digite o valor: ";
                        cin >> valor;
                        elemento[numconta]->creditar(valor);
                        cout << "\nRealizado com sucesso";
                        break;

                    case 3://Debitar 
                        cout << "Digite o valor:";
                        cin >> valor;
                        elemento[numconta]->debitar(valor);
                        cout << "\nRealizado com sucesso";
                        break;

                    case 4://Transferencia 
                        cout << "Digite a conta que sera realizado a transferencia: ";
                        int numconta2;
                        cin >> numconta2;
                        
                        while ( numconta2 > tamanho+1 || numconta2 <= 0 || numconta2 == numconta+1){
                            
                            if(numconta2 == numconta+1){

                                cout << "\nConta de destino é a mesma que a de destino\n";
                            }
                            cout << "\nInvalido\n"<< "Digite uma conta valida: ";
                            cin >> numconta2;
                        }
                        numconta2-=1 ;
                        cout << "A conta é de ";
                        elemento[numconta2]->mostranome();
                        cout << "\n\nDigite o valor: ";
                        cin >> valor;
                        
                        transferir(elemento[numconta], valor, elemento[numconta2]);

                        cout << "\nRealizado com sucesso.\n";
                        break;

                    case 5://Voltar 
                        break;

                    default://Se não estar dentro das opções 
                        cout << "\n\nOpção invalida\n\n";
                        break;
                }//fim do segundo switch 

                
             }//fim do laço while 
                break;//quebra do caso 2

            case 3://Atualiza conta 

                cout << "\n\nDigite em quantos meses que passara: ";
                int mes;
                cin >> mes;

                for( int i = 0; i < tamanho; i++){

                    elemento[i]->atualizaConta(mes);
                }
                break;

            case 4://Sair 
                break;

            default://Caso não estar dentro das opções 
                cout << "\nOpção invalida\n";
                break;

       }//fim do primeiro switch 

    }//fim do laço while 

}//fim da função

//Fim das funções


    int main(){


        setlocale(LC_ALL, "Portuguese");//Para todos os caracteres funcionarem no windows
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

        while( tamanho <= 0){
            
            cout << "\n\nInvalido\n\n" << "Digite uma quantidade maior que zero: ";
            cin >> tamanho;
        }


      conta * contas[tamanho];//criando ponteiro num vetor para tipo conta 

      for( int cont = 0; cont < tamanho; cont++){//coletando informações para as contas.

          cout << "------Conta " << cont+1 << "------"  << endl << endl;
          cout << "Digite o nome: ";
          cin.ignore();
          getline( cin, nome_temporario );//usado para ser capaz de armazenar nomes com espaços na string
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

      listar_contas( tamanho, contas );

      menu( tamanho, contas );

      return 0;

    }

            
