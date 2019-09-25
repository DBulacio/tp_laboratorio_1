#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee vec[], int tam){
    for(int i = 0 ; i < tam ; i++){
        vec[i].isEmpty = 1;
    }

    return 0;
}

int addEmployee(Employee vec[], int tam, int id, char name[], char lastName[], float salary, int sector){
    int index = lookForEmptyPosition(vec, tam);

    Employee addedEmployee;
    addedEmployee.id = id;
    strcpy(addedEmployee.name, name);
    strcpy(addedEmployee.lastName, lastName);
    addedEmployee.salary = salary;
    addedEmployee.sector = sector;
    addedEmployee.isEmpty = 0;

    vec[index] = addedEmployee;

    return 0;
}

void findEmployeeById(Employee vec[], int tam, int id){

}

void removeEmployee(Employee vec[], int tam, int id){

}

void sortEmployee(Employee vec[], int tam, int order){
    // despues de ordenarlos, llamar a printEmployee
}

void printEmployees(Employee vec[], int tam){
    int flag = 0;
    system("cls");
    printf("**** Listado de Empleados ****\n\n");

    printf("id   nombre    apellido    salario    sector\n");
    for(int i = 0 ; i < tam ; i++){
        if(vec[i].isEmpty == 0){
            printEmployee(vec[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("\n---No hay empleados que mostrar---");
    }
    printf("\n\n");
}

void printEmployee(Employee x){
    printf("%4d %20s %20s %6.2ff %d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

// ---------------------------------------------------------
// =========================================================
// =========================================================
// =========================================================
// ---------------------------------------------------------


int lookForEmptyPosition(Employee vec[], int tam){
    int index = -1;

    for(int i = 0 ; i < tam ; i++){
        if(vec[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int newEmployee(Employee vec[], int tam, int id){
    int itWorked = 0;
    char name[20];
    char lastName[20];
    float salary;
    int sector;

    system("cls");
    printf("**** Alta Empleado ****\n\n");

    if(lookForEmptyPosition(vec, tam) == -1){
        printf("SISTEMA COMPLETO. Imposible agregar nuevos empleados");
    } else {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(name);

        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("\nIngrese el salario: ");
        scanf("%f", &salary);

        printf("\nIngrese el sector: ");
        scanf("%d", &sector);

        addEmployee(vec, tam, id, name, lastName, salary, sector);
        itWorked = 1;
    }
    return itWorked;
}
