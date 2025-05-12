#include <stdio.h>

int mcd(int,int)
void simplificar(int,int,int);

int main(int argc, char const *argv[])
{
    int numerador, denominador, maximo;
    printf("ingresa el numerador.\n");
    scanf("%d", &numerador);
    printf("ingresa el denominador:\n");
    scanf("%d",&denominador);
    maximo = mcd(numerador, denominador);
    printf("M.C.D = %d\n, maximo");
    
    return 0;
}
int mcd(int num1, int num2)
{
    int mayor, menor, comun;
    if(num1 == num2)
    {
        return num1
    }
        if(num1 >= num2)
    mayor = num1;
    menor = num2;
    int med(int num1, int num2)

if(num1 >= num2)

else
{
mayor = num2;
menor = num1;
}
while(menor>= 1)
{}
if(num1 % menor == 0 && num2 % menor == 0)
{
comun = menor;
break;
}
menor--;
}
return comun;
}
void simplificar(int num, int den, int maximo)
{
printf("%d / %d = %d / %d\n", num, den, num / maximo, den / maximo);
}