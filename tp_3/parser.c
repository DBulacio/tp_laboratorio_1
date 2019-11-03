#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* f , LinkedList* list)
{
    int todoOk = 0;
    int cant;
    int id;
    char nombre[20];
    float sueldo;
    int horas;
    char buffer[4][30];

    Employee* aux = NULL;

    while(!feof(f)){
        cant = fscanf(f, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant == 4){
            id = atoi(buffer[0]);
            strcpy(nombre, buffer[1]);
            horas = atoi(buffer[2]);
            sueldo = atof(buffer[3]);

            aux = employee_newParametros(id, nombre, horas, sueldo);

            if(aux != NULL){
                ll_add(list, aux);
                todoOk = 1;
            } else {
                printf("ERROR: referencia nula");
            }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
