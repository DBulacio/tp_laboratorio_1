#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000

int menu();
int menuInformes();

int main()
{
    Employee arr[TAM];
    int flag = 1;       // Esta en 1 por testing. VOLVER A PONER EN 0!!!!!!!!%%%%%%%%%%&&&&&&&&&&&&&&
    int id = 1000;
    int order;
    char salir;
    //char order;

    initEmployees(arr, TAM);

    hardcodeEmployee(arr, TAM, 10);

    do{
        switch(menu()){
            case 1:
                // pedir todos los datos y pasarlos por parametro
                if (askForEmployeeParameters(arr, TAM, id)){
                    id++;
                }
                flag = 1;
                break;
            case 2:
                if(flag == 1){
                    modifyEmployee(arr, TAM);
                }
                break;
            case 3:
                if(flag == 1){
                    printf("Ingrese la ID del empleado a eliminar: ");
                    scanf("%d", &id);
                    removeEmployee(arr, TAM, id);
                }
                break;
            case 4:
                if(flag == 1){
                    printEmployees(arr, TAM);
                }
                break;
            case 5:
                switch(menuInformes()){
                    case 1:
                        printf("Ingrese 0 para ascendente o 1 para descendente: ");
                        scanf("%d", &order);
                        sortEmployee(arr, TAM, order);
                        break;
                    case 2:
                        informeSalario(arr, TAM);
                        break;
                    case 3:
                        printf("Informes cancelados\n");
                        break;
                    default:
                        printf("Opcion invalida! \n");
                        break;
                }
                break;
            case 6:
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
    printf("4. Mostrar Empleados\n");
    printf("5. Informes\n");
    printf("6. Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

int menuInformes(){
    system("cls");
    int rta;

    printf("1. Listado de empleados por apellido y sector.\n");
    printf("2. Total y promedio de salarios.\n");
    printf("3. Salir.\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}
