#include <stdio.h>
#include <math.h>
int delta(int a, int b, int c);//Essa função sera usada para calcular o delta 
void baskara(int a,int b, int c);//Essa função ira calcular a baskara e usara a função delta junto
void equacao(int a, int b, int c);//Essa função monta com as 3 variaveis usada nele para mostrar ela montada em forma de uma equação
int main(void)
{
    int a, b, c;//As variaveis daqui seria como o a, b e o c usado na baskara 
    printf("\n\n\n------Programa para resolver uma equação de segundo grau usando o metodo de funções no programa------\n\n\n");
    //A partir daqui coleta as informações para calcular a equação
    printf("Digite o x² de sua equação:");
    scanf("%d",&a);
    printf("Digite o x de sua equação:");
    scanf("%d",&b);
    printf("Digite a sua constante:");
    scanf("%d",&c);
    equacao(a,b,c);//usado a função para mostrar como é a equação montada 
    baskara(a,b,c);//Calcula a baskara e ja apresenta o resultado das duas raizes
    printf("\n\n\n------Programa Finalizado------\n\n\n");
    return 0;
}
void equacao(int a, int b, int c)//Função para montar a equação
{
    
    printf("(%d)²+%d+%d=0\n",a,b,c);//Um erro que ainda apresenta é se tiver numero negativo ele fica com o sinal +- junto, um erro que terei que consertar ainda 
    
}
int delta(int a, int b, int c)//função para calcular o delta 
{
    int resultado;
    resultado=(b*b)-(4*a*c);
    return resultado;
}
void baskara(int a,int b, int c)//Função que calcula a baskara usando a função delta junto e apresenta o resultado escrito
{
    int x1, x2;
    x1=(-b+(sqrt(delta(a,b,c))))/(2*a);
    x2=(-b-(sqrt(delta(a,b,c))))/(2*a);
    printf("A primeira raiz de sua equação é %d e a sua segunda função é %d",x1,x2);
}
