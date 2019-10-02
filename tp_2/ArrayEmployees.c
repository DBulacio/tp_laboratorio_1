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

int askForEmployeeParameters(Employee vec[], int tam, int id){
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

void modifyEmployee(Employee vec[], int tam){
    int index;
    int option;
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;

    system("cls");
    printf("*** MODIFICAR UN EMPLEADO ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);
    index = findEmployeeById(vec, tam, id);

    if(index == -1){
        printf("No existe un empleado con esa id\n");
    } else {
        printEmployee(vec[index]);
        modifyMenu();
        printf("Ingrese la opcion: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nIngrese el nuevo nombre: ");
                fflush(stdin);
                gets(name);
                strcpy(vec[index].name, name);
                break;
            case 2:
                printf("\nIngrese el nuevo apellido: ");
                fflush(stdin);
                gets(lastName);
                strcpy(vec[index].lastName, lastName);
                break;
            case 3:
                printf("\nIngrese el nuevo salario: ");
                scanf("%f", &salary);
                vec[index].salary = salary;
                break;
            case 4:
                printf("\nIngrese el nuevo sector: ");
                scanf("%d", &sector);
                vec[index].sector = sector;
                break;
            case 5:
                printf("Se ha cancelado la modificacion");
            default:
                printf("ERROR: elija una opcion valida");
                break;
        }
    }
}

int findEmployeeById(Employee vec[], int tam, int id){
    int index = -1;

    for(int i = 0 ; i < tam ; i++){
        if(vec[i].id == id && vec[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

void printEmployees(Employee vec[], int tam){
    int flag = 0;
    system("cls");
    printf("**** Listado de Empleados ****\n\n");

    printf("id            nombre            apellido             salario    sector\n");
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
    printf("%4d %20s %20s     %6.2ff      %d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

void removeEmployee(Employee vec[], int tam, int id){
    int index;
    char confirm;

    index = findEmployeeById(vec, tam, id);

    if(index == -1){
        printf("No existe un alumno con ese legajo\n");
    } else {
        printEmployee(vec[index]);
        printf("Confirma la baja? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirm);
        if(confirm == 's'){
            vec[index].isEmpty = 1;
            printf("Baja exitosa!\n\n");
        } else {
            printf("Se cancelo la baja\n");
        }
    }
}

void sortEmployee(Employee vec[], int tam, int order){
    Employee aux;

    if(order == 0){
        for(int i = 0 ; i < tam - 1 ; i++){
            for(int j = i + 1 ; j < tam ; j++){
                if(vec[i].sector > vec[j].sector && vec[i].isEmpty == 0 && vec[j].isEmpty == 0){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        ordenarAlfabeticamente(vec, tam);
        printf("Empleados Ordenados de manera Ascendente!!!\n\n");
        system("pause");
        printEmployees(vec, tam);
    }

    if(order == 1){
        for(int i = 0 ; i < tam - 1 ; i++){
            for(int j = i + 1 ; j < tam ; j++){
                if(vec[i].sector < vec[j].sector && vec[i].isEmpty == 0 && vec[j].isEmpty == 0){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
        ordenarAlfabeticamente(vec, tam);
        printf("Empleados Ordenados de manera Descendente!!!\n\n");
        system("pause");
        printEmployees(vec, tam);
    }



}



// ---------------------------------------------------------
// =========================================================
// ========================================modifyMenu();=================
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

void modifyMenu(){
    printf("1. Modificar el nombre\n");
    printf("2. Modificar el apellido\n");
    printf("3. Modificar el salario\n");
    printf("4. Modificar el sector\n");
    printf("5. Cancelar");
    printf("\n\n");
}

void hardcodeEmployee(Employee vec[], int tam, int cant){
    Employee listaAuxiliar[] = {
        {20000, "Juan",    "Pereyra",  10000, 3, 0},
        {20001, "Laura",   "Alfaro",   20000, 2, 0},
        {20002, "Yamila",  "Zabaleta", 31000, 1, 0},
        {20003, "Bruno",   "Lucente",  22000, 2, 0},
        {20004, "Diego",   "Carrizo",  24000, 0, 0},
        {20005, "Paula",   "Gallardo", 28000, 3, 0},
        {20006, "Camila",  "Cabello",  21000, 1, 0},
        {20007, "Daniel",  "Amorcito", 21000, 2, 0},
        {20008, "Fiorella", "Panizza", 21000, 0, 0},
        {20009, "Clara",    "DeMarco", 21000, 3, 0}
    };

    if(cant <= tam && cant < 11){
        for(int i = 0 ; i < cant ; i++){
            vec[i] = listaAuxiliar[i];
        }
    }

}

void ordenarAlfabeticamente(Employee vec[], int tam){
    Employee aux;

    for(int i = 0 ; i < tam - 1 ; i++){
        for(int j = i + 1 ; j < tam ; j++){
            if(vec[i].sector == vec[j].sector && vec[i].isEmpty == 0 && vec[j].isEmpty == 0){
                if(vec[i].name[0] > vec[j].name[0]){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

void informeSalario(Employee vec[], int tam){
    system("cls");
    printf("****INFORME SALARIO****\n\n");

    float sum = 0;
    float promedio;
    int cont = 0;
    int contSuperaPromedio = 0;

    for(int i = 0 ; i < tam ; i++){
        if(vec[i].isEmpty == 0){
            sum += vec[i].salary;
            cont++;
        }
    }
    printf("La suma de todos los salarios es: %.2f\n", sum);
    promedio = (float) sum / cont;
    printf("El promedio de todos los salarios es: %.2f\n", promedio);

    for(int i = 0 ; i < tam ; i++){
        if(vec[i].isEmpty == 0 && vec[i].salary > promedio){
            contSuperaPromedio++;
        }
    }

    printf("La cantidad de empleados que cobran mas que el promedio son: %d\n\n", contSuperaPromedio);
}
