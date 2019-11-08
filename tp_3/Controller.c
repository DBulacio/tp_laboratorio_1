#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* list)
{
    int todoOk = 0;
    FILE* f = fopen("data.csv", "r");

    if(f == NULL || list == NULL || path == NULL) {
        printf("ERROR. No se pudo abrir el archivo. \n");
        system("pause");
        return todoOk;
    }
    parser_EmployeeFromText(f, list);
    todoOk = 1;

    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* list)
{
    int todoOk = 0;
    FILE* f = fopen("data.bin", "rb");

    if(f == NULL || list == NULL  || path == NULL) {
        printf("ERROR. No se pudo abrir el archivo. \n");
        system("pause");
        return todoOk;
    }
    parser_EmployeeFromBinary(f, list);
    todoOk = 1;

    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* list, int id)
{
    int todoOk = 0;
    char nombre[20];
    char buffer[20];
    int bufferInt;
    int horas;
    float sueldo;
    Employee* nuevo = employee_new();

    if(list == NULL || nuevo == NULL){
        return todoOk;
    }

    /* --- PIDO LOS DATOS --- */
    employee_setId(nuevo, id);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(nombre);
    bufferInt = atoi(nombre);

    while(bufferInt != '\0'){
        printf("ERROR. Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre);
        bufferInt = atoi(nombre);
    }

    employee_setNombre(nuevo, nombre);

    printf("Ingrese la cantidad de horas trabajadas: ");
    fflush(stdin);
    gets(buffer);
    horas = atoi(buffer);

    while(horas == '\0'){
        printf("ERROR. Ingrese la cantidad de horas trabajadas: ");
        fflush(stdin);
        gets(buffer);
        horas = atoi(buffer);
    }

    employee_setHorasTrabajadas(nuevo, horas);

    printf("Ingrese el sueldo: ");
    fflush(stdin);
    gets(buffer);
    sueldo = atof(buffer);

    while(sueldo == '\0'){
        printf("ERROR. Ingrese el sueldo: ");
        fflush(stdin);
        gets(buffer);
        sueldo = atof(buffer);
    }

    employee_setSueldo(nuevo, sueldo);
    /* --- TERMINO DE PEDIR LOS DATOS --- */

    if(nuevo == NULL){
        return todoOk;
    } else {
        ll_add(list, nuevo);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* list)
{
    int todoOk = 0;
    int flag = 0;
    int option = 0;
    int id;
    int bufferInt;
    char buffer[20];
    char nombre[20];
    int horas;
    float sueldo;
    Employee* aux = NULL;
    Employee* emp = NULL;

    if(list == NULL){
        return todoOk;
    }

    printf("Ingrese el id del empleado: ");
    fflush(stdin);
    gets(buffer);
    // VALIDAR
    id = atoi(buffer);

    while(id == '\0'){
        printf("ERROR. Ingrese el id del empleado: ");
        fflush(stdin);
        gets(buffer);
        // VALIDAR
        id = atoi(buffer);
    }

    for(int i = 0 ; i < ll_len(list) ; i++){
        aux = (Employee*) ll_get(list, i);
        if(id == aux->id){
            emp = aux;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("No existe empleado con ese id. \n\n");
        return todoOk;
    }

    printf("%4d %20s %6d %8.2f\n\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    printf("1. Modificar nombre\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");

    while(option < 1 || option > 3){
        printf("Ingrese la opcion: ");
        fflush(stdin);
        gets(buffer);
        // VALIDAR
        option = atoi(buffer);

        while(option == '\0'){
            printf("Ingrese la opcion: ");
            fflush(stdin);
            gets(buffer);
            option = atoi(buffer);
        }

        if(option == 1){
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(nombre);
            bufferInt = atoi(nombre);

            while(bufferInt != '\0'){
                printf("ERROR. Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(nombre);
                bufferInt = atoi(nombre);
            }

            employee_setNombre(emp, nombre);
            todoOk = 1;

        } else if(option == 2){
            printf("Ingrese la nueva cantidad de horas trabajadas: ");
            fflush(stdin);
            gets(buffer);
            horas = atoi(buffer);

            while(horas == '\0'){
                printf("ERROR. Ingrese la nueva cantidad de horas trabajadas: ");
                fflush(stdin);
                gets(buffer);
                horas = atoi(buffer);
            }

            employee_setHorasTrabajadas(emp, horas);
            todoOk = 1;

        } else if(option == 3){
            printf("Ingrese el nuevo sueldo: ");
            fflush(stdin);
            gets(buffer);
            sueldo = atof(buffer);fflush(stdin);
            gets(buffer);
            sueldo = atoi(buffer);

            while(sueldo == '\0'){
                printf("ERROR. Ingrese el nuevo sueldo: ");
                fflush(stdin);
                gets(buffer);
                sueldo = atoi(buffer);
            }

            while(sueldo == '\0'){
                printf("ERROR. Ingrese el nuevo sueldo: ");
                fflush(stdin);
                gets(buffer);
                sueldo = atof(buffer);
            }

        } else {
            return todoOk;
        }
    }
    return todoOk;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* list)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char salir;
    char buffer[20];
    Employee* aux = NULL;
    Employee* emp = NULL;

    if(list == NULL){
        return todoOk;
    }

    printf("Ingrese el id del empleado: ");
    fflush(stdin);
    gets(buffer);
    id = atoi(buffer);

    while(id == '\0'){
        printf("ERROR. Ingrese el id del empleado: ");
        fflush(stdin);
        gets(buffer);
        id = atoi(buffer);
    }

    for(int i = 0 ; i < ll_len(list) ; i++){
        aux = (Employee*) ll_get(list, i);
        if(id == aux->id){
            emp = aux;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("El id no existe\n");
        return todoOk;
    }

    index = ll_indexOf(list, emp);

    printf("El empleado que selecciono es: \n");
    printf("%4d %20s %6d %8.2f\n\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);

    printf("Seguro desea eliminar este empleado? (s/n) ");
    fflush(stdin);
    salir = getchar();
    if(salir == 's'){
        printf("\n-----EMPLEADO ELIMINADO-----\n\n");
    } else {
        printf("Baja cancelada\n");
        return todoOk;
    }

    ll_remove(list, index);
    todoOk = 1;

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* list)
{
    int todoOk = 0;
    Employee* emp;

    if(list == NULL){
        return todoOk;
    }

    printf(" ID                 NOMBRE                  HORAS   SUELDO  \n");
    for(int i = 0 ; i < ll_len(list) ; i++){
        emp = (Employee*) ll_get(list, i);

        if(emp != NULL){
            printf("%4d %20s %6d %8.2f\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            todoOk = 1;
        }
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* list)
{
    int todoOk = 0;
    int option;

    if(list == NULL){
        return todoOk;
    }

    system("cls");

    printf("1. Ordenar por id\n");
    printf("2. Ordenar por nombre\n");
    printf("3. Ordenar por horas\n");
    printf("4. Ordenar por sueldo\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    while(option < 1 || option > 4){
        printf("Ingrese una opcion: ");
        scanf("%d", &option);
    }

    if(option == 1){
        ll_sort(list, employee_compareById, 0);
    }
    if(option == 2){
        ll_sort(list, employee_compareByName, 0);
    }
    if(option == 3){
        ll_sort(list, employee_compareByHour, 0);
    }
    if(option == 4){
        ll_sort(list, employee_compareBySalary, 0);
    }

    printf("Empleados ordenados correctamente\n\n");
    todoOk = 1;
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* list)
{
    int todoOk = 0;
    int cant;
    FILE* f;
    Employee* aux = employee_new();

    f = fopen(path, "w");

    if(path == NULL ||list == NULL ||f == NULL || aux == NULL){
        return todoOk;
    }

    fprintf(f, "id,nombre,horasTrabajadas,sueldo\n"); // Encabezado
    for(int i = 1 ; i < ll_len(list) ; i++){
        aux = (Employee*) ll_get(list, i);
        cant = fprintf(f, "%d,%s,%d,%.2f\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
        if(cant < 1){
            return todoOk;
        }
    }
    fclose(f);
    todoOk = 1;

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* list)
{
    int todoOk = 0;
    int cant;
    Employee* emp;
    FILE* f;

    if(path != NULL && list != NULL){
        f = fopen(path, "wb");
        if(f == NULL){
            return todoOk;
        }
        for(int i = 0 ; i < ll_len(list) ; i++){
            emp = (Employee*) ll_get(list, i);
            cant = fwrite(emp, sizeof(Employee), 1, f);
            if(cant < 1){
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }

    return todoOk;
}






