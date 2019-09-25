#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000

int menu();

int main()
{
    Employee arr[TAM];
    int flag = 0;
    int id = 1000;
    char salir;
    char confirm;
    //char order;

    initEmployees(arr, TAM);

    do{
        switch(menu()){
            case 1:
                // pedir todos los datos y pasarlos por parametro
                if (newEmployee(arr, TAM, id)){
                    id++;
                }
                flag = 1;
                break;
            case 2:
                if(flag == 1){
                    printf("Ingrese la ID del empleado a modificar: ");
                    scanf("%d", &id);
                    findEmployeeById(arr, TAM, id);
                }
                break;
            case 3:
                if(flag == 1){
                    printf("Ingrese la ID del empleado a eliminar: ");
                    scanf("%d", &id);
                    printf("¿Está seguro? (y/n): ");
                    fflush(stdin);
                    scanf("%c", &confirm);
                    if(confirm == 'y'){
                        removeEmployee(arr, TAM, id);
                    }
                }
                break;
            case 4:
                if(flag == 1){
                        /*
                    printf("¿Ascendente o descendente? (a/d)");
                    fflush(stdin);
                    scanf("%c", &order);
                    sortEmployee(arr, TAM, order);
                    */
                    printEmployees(arr, TAM);
                }
                break;
            case 5:
                printf("¿Seguro quiere salir? (s/n) ");
                fflush(stdin);
                salir = getchar();
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

int menu(){
    system("cls");
    int rta;

    printf("---BIENVENIDO AL SISTEMA---\n\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}
