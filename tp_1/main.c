#include <stdio.h>
#include <stdlib.h>
#include "bulacio.h"

int menu(int, int, int, int);

int main()
{
    char salir;
    int num1 = 0, num2 = 0;
    int rSum, rRes, rMult, rFactA, rFactB;
    float rDiv;
    int flag1 = 0, flag2 = 0;

    do {
        switch(menu(num1, num2, flag1, flag2)){
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%d", &num1);
                flag1 = 1;
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%d", &num2);
                flag2 = 1;
                break;
            case 3:
                if(flag1 == 1 && flag2 == 1){
                    printf("CALCULANDO...\n");
                    rSum = sumar(num1, num2);
                    rRes = restar(num1, num2);
                    rDiv = dividir(num1, num2);
                    rMult = multiplicar(num1, num2);
                    rFactA = factorialA(num1);
                    rFactB = factorialB(num2);
                } else {
                    printf("Ingrese el operando faltante\n");
                }
                break;
            case 4:
                printf("El resultado de la suma es: %d\n", rSum);
                printf("El resultado de la resta es: %d\n", rRes);
                if(num2 != 0){
                    printf("El resultado de la division es: %f\n", rDiv);
                } else {
                    printf("No se puedo realizar la division porque el dividendo es 0");
                }
                printf("El resultado de la multiplicacion es: %d\n", rMult);
                // Si se hizo la operacion, damos un mensaje para cada resultado posible
                if(rFactA == 0 && rFactB > 0){
                    printf("El factorial de A no se puede calcular y el factorial de B es: %d\n", rFactB);
                } else if(rFactA > 0 && rFactB == 0){
                    printf("El factorial de A es %d y el factorial de B no se puede calcular\n", rFactA);
                } else if(rFactA == 0 && rFactB == 0){
                    printf("No se puede calcular el factorial de A ni de B\n");
                } else {
                printf("El factorial de A es: %d y El factorial de B es: %d\n", rFactA, rFactB);
                }
                break;
            case 5:
                printf("¿Seguro quiere salir? (s/n) ");
                fflush(stdin);
                salir = getchar();      // Si se ingresa un String se rompe
                if(salir == 's'){
                    printf("\n-----HASTA LUEGO!-----\n\n");
                }
                break;
            default:
                printf("ERROR: elija una opcion valida");
                break;
        }
        system("pause");
    } while (salir != 's');

    return 0;
}

int menu(int a, int b, int flag1, int flag2){
    int rta;
    char x = 'x', y = 'y';

    system("cls");

    printf("----- BIENVENIDO A LA CALCULADORA -----\n\n");
    if(flag1 == 0){
        printf("      1. Ingresar 1er operando (A = %c)\n", x);
    } else {
        printf("      1. Ingresar 1er operando (A = %d)\n", a);
    }
    if(flag2 == 0){
        printf("      2. Ingresar 2do operando (B = %c)\n", y);
    } else {
        printf("      2. Ingresar 2do operando (B = %d)\n", b);
    }
    printf("      3. Calcular todas las operaciones\n");
    printf("        a. Calcular la suma (A + B)\n");
    printf("        b. Calcular la resta (A - B)\n");
    printf("        c. Calcular la division (A / B)\n");
    printf("        d. Calcular la multiplicacion (A * B)\n");
    printf("        e. Calcular el factorial (A!) (B!)\n");
    printf("      4. Informar resultados\n");
    printf("        a. El resultado de A + B es: r\n");
    printf("        b. El resultado de A - B es: r\n");
    printf("        c. El resultado de A / B es: r\n");
    printf("        d. El resultado de A * B es: r\n");
    printf("        e. El factorial de A es: r1 y El factorial de B es: r2\n");
    printf("      5. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}




