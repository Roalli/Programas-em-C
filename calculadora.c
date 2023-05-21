#include <stdio.h>
#include <math.h>
/*Prototipos das funções*/ 
double SOMA(double num1, double soma);
double SUBTRACAO( double num1, double subtracao);
double MULTIPLICAR(double num1, double multiplica);
double DIVISAO(double num1, double dividir);
double POTENCIA(double num1, int potencia);
float FATORIAL(int num);

/*Função main*/ 
int main(void)
{
    /*as variavies*/ 
    int opcao = 0 ;
    double num1 = 0;

    /*Laço de controle para manter na escolha do programa*/ 
    while(opcao != 7){
    printf("\n\n\t\tOs programas:\n\t\t\t1 - Soma.\n\t\t\t2 - Subtração.\n\t\t\t3 - Multiplicação.");
    printf("\n\t\t\t4 - Divisão.\n\t\t\t5 - Potencialização. \n\t\t\t6 - Fatorial.\n\t\t\t7 - Sair.\n");

    printf("Digite a opção:");
    scanf("%d",&opcao);


    /*comando de escolha para escolher o programa*/ 
    switch (opcao) {

        case 1 :

            printf("");/*foi usado para evitar um bug de declaração de variavel*/ 
           int quantidade_soma = 1 , cont;

           double num1 = 0, soma = 0;
            printf("\t\t------Ira realizar soma de numero------");
            printf("\n\nDigite quantos numeros ira ser usado na soma:");
           scanf("%d",&quantidade_soma);
           for(cont = 1 ; cont <= quantidade_soma; cont++){

               if(cont == 1){
                   printf("\nDigite o numero:");
               }
               if(cont!= 1 ){
                   printf("\t       +");
               }
               scanf("\t\t%lf",&num1);
               soma = SOMA(num1 , soma);
           }

           printf("O resultado da soma: %f", soma);


            break;
            
        case 2:
           
            printf("");
           

           double  subtracao = 0;
            printf("\t\t------Ira realizar subtração de numero------");
            printf("\n\nSera subtração de dois numeros.");
        

               
            printf("\nDigite o numero:");
               
            scanf("%lf",&num1);

            printf("\t       -");
               
            scanf("\t\t%lf",&subtracao);
            subtracao = SUBTRACAO(num1 , subtracao);
           

           printf("O resultado da subtração: %f", subtracao);



            break;

        case 3:

            printf("");
            double multiplica = 1;
            int quantidade_multiplicacao = 0;
            printf("\n\t\t\t------Programa de Multiplicação------\n");
            printf("Digite quantos numeros serão multiplicados:");

            scanf("%d", &quantidade_multiplicacao);

            for(cont = 1; cont <= quantidade_multiplicacao; cont++){

                if(cont == 1){
                    printf("Digite o numero:");
    
                }
                

                if(cont != 1){
               
                    printf("\t       x");
                }
                scanf("%lf", &num1);
                multiplica = MULTIPLICAR(num1 ,multiplica);
            }

                printf("O resultado da multiplicação é: %lf", multiplica);



            break;

        case 4:

            printf("");

            double dividir = 1, resultado;

            printf("\t\t\t------Programa que faz divisão com dois numero------\n");

            printf("Digite o dividendo:");
            scanf("%lf", &num1);
            printf("Digite o divisor:");
            scanf("%lf", &dividir);

            resultado = DIVISAO(num1, dividir);

            printf("O resultado da divisão:%lf", resultado);

            break;

        case 5:

            printf("");

            double result;
            int potencia;

            printf("\t\t\t------Programa que calcula potencia------\n");

            printf("Digite a base:");
            scanf("%lf", &num1);
            printf("Digite o expoente:");
            scanf("%d", &potencia);

            result = POTENCIA(num1, potencia);

            printf("O resultado da potencia:%lf", result);

            break;

        case 6:

            printf("");

            float fatorial;
            int num;

            printf("\t\t\t------Programa que calcula o fatorial------\n");

            printf("\t\t\tDigite o fatorial:");
            scanf("%d", &num);

            fatorial = FATORIAL(num);

            printf("O fatorial: %f", fatorial);

            break;

        default:
            break;
    
    
    }
    }

    return 0;
}

/*As funções*/ 
double SOMA( double num1, double soma)
{

    double resultado = 0;

    resultado = num1 + soma;

    return resultado;

}

double SUBTRACAO( double num1, double subtracao)
{

    double resultado = 0;
    resultado = num1 - subtracao;

    return resultado;
}

double MULTIPLICAR(double num1, double multiplica)
{
    double resultado = 1;
    resultado = num1 * multiplica;
    return resultado;
}

double DIVISAO(double num1, double dividir)
{
    double resultado = 1;

    resultado = num1 / dividir;

    return resultado;
}

double POTENCIA( double num1, int potencia)
{

    double resultado = num1;

    int cont;

    if(resultado == 0){
        resultado = 1;
    }
    for(cont = 1; cont < potencia; cont++){
        resultado = resultado * num1;
    }

    return resultado;
}

float FATORIAL(int num)
{
    float fatorial = 1 ;

    int cont;

    for(cont = 1 ; cont <= num ; cont++){

        fatorial = cont * fatorial;
    }

    return fatorial;
}
