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
    int flag1 = 0, flag2 = 0, fSuma = 0, fResta = 0, fMult = 0, fDiv = 0, fFactA = 0, fFactB = 0;

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
                    printf("Seleccione la operacion a realizar: ");
                    fflush(stdin);
                    char option = getchar();
                    //menu de operaciones
                    switch(option){
                        case 'a':
                            rSum = sumar(num1, num2);
                            fSuma = 1;
                            break;
                        case 'b':
                            rRes = restar(num1, num2);
                            fResta = 1;
                            break;
                        case 'c':
                            if(num2 != 0){
                                rDiv = dividir(num1, num2);
                                fDiv = 1;
                            } else {
                                printf("Ingrese un valor distinto a cero para B\n");
                            }
                            break;
                        case 'd':
                            rMult = multiplicar(num1, num2);
                            fMult = 1;
                            break;
                        case 'e':
                            rFactA = factorialA(num1);
                            fFactA = 1;
                            break;
                        case 'f':
                            rFactB = factorialB(num2);
                            fFactB = 1;
                            break;
                        default:
                            printf("ERROR: elija una operacion valida\n");
                            break;
                    }
                } else {
                    printf("Ingrese el operando faltante\n");
                }
                break;
            case 4:
                printf("Seleccione el resultado a mostrar: ");
                fflush(stdin);
                char option = getchar();
                switch(option){
                    case 'a':
                        if(fSuma == 1){
                           printf("El resultado de la suma es: %d\n", rSum);
                        } else {
                            printf("Tiene que realizar la suma para ver el rusltado.\n");
                        }
                        break;
                    case 'b':
                        if(fResta == 1){
                            printf("El resultado de la resta es: %d\n", rRes);
                        } else {
                            printf("Tiene que realizar la resta para ver el rusltado.\n");
                        }
                        break;
                    case 'c':
                        if(fDiv == 1){
                            printf("El resultado de la division es: %f\n", rDiv);
                        } else {
                            printf("Tiene que realizar la division para ver el rusltado.\n");
                        }
                        break;
                    case 'd':
                        if(fMult == 1){
                            printf("El resultado de la multiplicacion es: %d\n", rMult);
                        } else {
                            printf("Tiene que realizar la multiplicacion para ver el rusltado.\n");
                        }
                        break;
                    case 'e':
                        if(fFactA == 1){
                            printf("El resultado del factorial es: %d\n", rFactA);
                        } else {
                            printf("Tiene que realizar la factorizacion para ver el rusltado.\n");
                        }
                        break;
                    case 'f':
                        if(fFactB == 1){
                            printf("El resultado del factorial es: %d\n", rFactB);
                        } else {
                            printf("Tiene que realizar la factorizacion para ver el rusltado.\n");
                        }
                        break;
                    default:
                        printf("ERROR: elija una opcion valida\n");
                        break;
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
    printf("        e. Calcular el factorial (A!)\n");
    printf("        f. Calcular el factorial (B!)\n");
    printf("      4. Informar resultados\n");
    printf("        a. El resultado de A + B es: r\n");
    printf("        b. El resultado de A - B es: r\n");
    printf("        c. El resultado de A / B es: r\n");
    printf("        d. El resultado de A * B es: r\n");
    printf("        e. El factorial de A es: r\n");
    printf("        f. El factorial de B es: r\n");
    printf("      5. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}




