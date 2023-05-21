#include <stdio.h>
#include <time.h>

long fibonacciint( long n );/*prototipo da função fibonacci iteração*/
long fibonaccirec( long n);/*prototipo da função fibonacci com recursão*/
void iteracao();//prototipo da função que sera usada com iteração
void recursiva();//prototipo da função que sera usada com recursão

//função main inicia a execução do programa
int main( void )
{
//Esse programa tem duas formas de calcular o fibonacci, ou por iteração ou recursiva
//depende a forma que o usuario ira escolher.
   
    int opcao;//variavel que sera usado para guardar a escolha do usuario


        printf("\n\n\n------Programa para calcular Fibonacci, com a forma de iteração ou recursiva------\n\n\n");
   
    printf("\n\nEscolha qual programa que deseje executar:\n\n1 - Fibonacci com iteração.\n\n2 - Fibonacci com recursiva.\n\nOutro numero ira sair do programa\n\n\nDigite a opção:");
   
    scanf("%d",&opcao);

   
    while( opcao == 1 || opcao == 2 ){
   
        switch (opcao) {//Responsavel por fazer a escolha da opção de qual função ira usar 
                        //para calcular.
    
   
            case 1 :

                
      
                iteracao();
    
 
                break;

   
            case 2 :

     
                recursiva();
                

    
                break;

   
            default:
    
    
                printf("\n\nOpção invalida\n\n");
    
    
                break;

        }
    
                printf("\n\nEscolha qual programa que deseje executar:\n\n1 - Fibonacci com iteração.\n\n2 - Fibonacci com recursiva.\n\nDigite a opção:");
   //o printf está presente no final para quando entrar no teste do laço, poder saber se 
   //continuara no laço ou se saira do laço, assim encerrando o programa.
   
    
                scanf("%d",&opcao);


   
        
   
    }

    printf("\n\n------Programa Finalizado------\n\n\n");

    return 0; 
}//fim do main

long fibonacciint( long n) //A função fibonacci 
{
    //São as variaveis que irão ser usadas no controle para calcular o fibonacci 
    long soma = 0;
    long cont = 1;
    long ultimo = 1, penultimo = 0;

    for ( ;cont <= n ; cont++ ) { //O laço de repetição usado para calcular o fibonacci 
        
        if( cont != 2 ){ //Esse if é para manter a sequencia 0,1,1.
                         //Assim ele mantem o 1 duas vezes antes de continuar
        soma = penultimo + ultimo;
        penultimo = ultimo;
        ultimo = soma;
        
        } 
            
      }

    
    return soma;
    //fim da função fibonacci iterativa
}
long fibonaccirec( long n )//função fibonacci recursiva
{
    if( n == 0 || n == 1 ) {
        return n;
    }
    else { 
        return fibonaccirec( n - 1 ) + fibonaccirec( n - 2 );
    }
    //fim da função fibonacci recursiva
}
void iteracao()
{
    //Essa parte do programa é pela forma de iteração
    long result;//valor de fibonacci
    long number,cont1;//numero fornecido pelo usuario
       printf("\n\n------Programa para calcular a serie de Fibonacci na forma iterativa------\n\n\n");
    printf("Para sair do programa digite um numero negativo.\n\n");
    
    //Ira pedir um numero para o usuario digitar e usara para calcular o fibonacci.
    printf( "Digite um inteiro: ");
    scanf( "%ld",&number);

    while( number >= 0 ){//Laço utilizado para repetir o calculo de Fibonacci até o numero
                         //digitado ser negativo, quando for o programa se encerra.
    
            
        //chama a função para calcular a serie que digitou do fibonacci    
        //e armazena na variavel com o resultado.    
       

        //Mostra na tela o resultado do Fibonacci.
        printf( "\n\nFibonacci(%ld) = ", number);
       clock_t tInicio, tFim; //usado da biblioteca time.h, ela é as variaveis dessa função de 
                              //medir os clocks do processo de seu inicio até o seu final 
                              //definido, no caso ira medir o tempo do inicio da função fibonacci
                              //ate o seu final.
    
       double tDecorrido;//varivel que ira calcular o tempo total de uso da função.

            tInicio = clock();/*Tempo de inicio guardado nessa variavel*/ 
       
            for( cont1=0; cont1 <= number; cont1++){
           

           

            result = fibonacciint(cont1 );
            if( cont1 != number ) {

            printf("%ld, ", result);

            } else{ printf("%ld.", result); }
           
            }

    
            tFim = clock();/*Tempo de final guardado*/
            tDecorrido = ( (double) (tFim - tInicio) * 1000 / (CLOCKS_PER_SEC));
           
            printf("\n\nTempo usado para o calculo: %lf millisegundos.", tDecorrido);



        //Ira pedir um numero para o usuario digitar e usara para calcular o fibonacci.
        printf( "\n\nDigite um inteiro: ");         
        scanf( "%ld",&number);
    }
}
void recursiva()
{
//Essa parte do programa é pela forma de recursiva

    long result;//valor de fibonacci
    long number,cont1;//numero fornecido pelo usuario
       printf("\n\n------Programa para calcular a serie de Fibonacci na forma recursiva------\n\n\n");
    printf("Para sair do programa digite um numero negativo.\n\n");
    
    //Ira pedir um numero para o usuario digitar e usara para calcular o fibonacci.
    printf( "Digite um inteiro: ");
    scanf( "%ld",&number);

    while( number >= 0 ){//Laço utilizado para repetir o calculo de Fibonacci até o numero
                         //digitado ser negativo, quando for o programa se encerra.
    
            
        //chama a função para calcular a serie que digitou do fibonacci    
        //e armazena na variavel com o resultado.    
       

        //Mostra na tela o resultado do Fibonacci.
        printf( "\n\nFibonacci(%ld) = ", number);
       

        clock_t tInicio, tFim; /*usado da biblioteca time.h, ela é as variaveis dessa função de 
                              medir os clocks do processo de seu inicio até o seu final 
                              definido, no caso ira medir o tempo do inicio da função fibonacci
                              ate o seu final.*/ 
    
       double tDecorrido;//varivel que ira calcular o tempo total de uso da função.


       tInicio = clock();/*Tempo do inicio guardado*/ 

        for( cont1=0; cont1 <= number; cont1++){
           
            

            result = fibonaccirec(cont1 );

            if( cont1 != number ) {

            printf("%ld, ", result);

            } else{ printf("%ld.", result); }
            
        }

    
        tFim = clock();/*Tempo de final guardado*/ 
        
        tDecorrido = ( (double) ( (tFim - tInicio) * 1000)  / (CLOCKS_PER_SEC ));
           
        
        printf("\n\nTempo usado para o calculo: %lf millisegundos.", tDecorrido);



        //Ira pedir um numero para o usuario digitar e usara para calcular o fibonacci.
        printf( "\n\nDigite um inteiro: ");         
        scanf( "%ld",&number);

    }
    
}
//fim do programa 
