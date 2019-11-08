#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

// FALTA ORDENAR Y LAS VALIDACIONES

int menu();

int main()
{
    int flag = 0;
    int flagBin = 0;
    char salir;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBin = ll_newLinkedList();
    //int id;
    //Employee emp = {1234, "Daniel", 20, 14000};

    if(listaEmpleados == NULL ||listaEmpleadosBin == NULL) {
        printf("ERROR: no se puedo asignar memoria. \n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {
            case 1:
                // uso una copia del archivo para no modificar el original
                if(ll_isEmpty(listaEmpleados)){
                    if(controller_loadFromText("data.csv",listaEmpleados)){
                        printf("Empleados cargados correctamente.\n\n");
                        flag = 1;
                    }
                }
                break;
            case 2:
                if(ll_isEmpty(listaEmpleados)){
                    if(flagBin == 1){
                        if(controller_loadFromBinary("data.bin", listaEmpleadosBin)){
                            printf("Empleados cargados desde binario correctamente.\n\n");
                        }
                    } else {
                        printf("Debe haber creado el archivo .bin para utlizar esta opcion.\n\n");
                    }
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados, ll_len(listaEmpleados))){
                    printf("Empleado creado correctamente.\n\n");
                }
                break;
            case 4:
                if(flag == 1){

                    controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if(flag == 1){

                    controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if(flag == 1){
                    controller_ListEmployee(listaEmpleados);
                } else {
                    printf("Debe cargar los empleados desde texto antes de continuar\n\n");
                }
                break;
            case 7:
                if(flag == 1){

                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(flag == 1){
                    if(controller_saveAsText("data.csv", listaEmpleados)){
                        printf("Empleados guardados a texto correctamente.\n\n");
                    }
                } else {
                    printf("Debe cargar los empleados desde texto antes de continuar\n\n");
                }
                break;
            case 9:
                if(flag == 1){
                    if(controller_saveAsBinary("data.bin", listaEmpleados)){
                        printf("Empleados guardados a binario correctamente.\n\n");
                    }
                    flagBin = 1;
                } else {
                    printf("Debe cargar los empleados desde texto antes de continuar\n\n");
                }
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
