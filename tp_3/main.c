#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    char salir;
    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados == NULL) {
        printf("ERROR: no se puedo asignar memoria. \n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 10:
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
    }while(salir != 's');

    return 0;
}

int menu(){
    system("cls");
    int rta;

    printf("---BIENVENIDO AL SISTEMA---\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}
