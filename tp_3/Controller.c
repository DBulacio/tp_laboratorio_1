#include <stdio.h>
#include <stdlib.h>
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
int controller_addEmployee(LinkedList* list)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int horas;
    float sueldo;
    Employee* nuevo = employee_new();

    if(list == NULL || nuevo == NULL){
        return todoOk;
    }

    /* --- PIDO LOS DATOS --- */
    printf("Ingrese el id del empleado: ");
    scanf("%d", &id);
    employee_setId(nuevo, id);
    /* --- VALIDAR QUE NO EXISTA EL ID --- */

    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    gets(nombre);
    employee_setNombre(nuevo, nombre);

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas);
    employee_setHorasTrabajadas(nuevo, horas);

    printf("Ingrese el sueldo: ");
    scanf("%f", &sueldo);
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
    return 1;
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
    Employee* aux = employee_new();

    if(list == NULL){
        return todoOk;
    }

    printf("Ingrese el id del empleado: ");

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
    return 1;
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






