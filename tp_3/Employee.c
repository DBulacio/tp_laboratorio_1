#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* nuevo = (Employee*) malloc(sizeof(Employee));

    if(nuevo != NULL){
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0.0;
    }

    return nuevo;
}

Employee* employee_newParametros(int id, char* nombre, int horas, float sueldo){
    Employee* nuevo = employee_new();

    if(nuevo != NULL){
       if(employee_setId(nuevo, id) && employee_setNombre(nuevo, nombre) && employee_setHorasTrabajadas(nuevo, horas) && employee_setSueldo(nuevo, sueldo)){
            //printf("Empleado cargado correctamente. \n");
       } else {
            nuevo = NULL;
       }
    }

    return nuevo;
}

int employee_setId(Employee* this, int id){
    int todoOk = 0;

    if(this != NULL){
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this, char* nombre){
    int todoOk = 0;

    if(this != NULL && nombre != NULL){
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this, int horas){
    int todoOk = 0;

    if(this != NULL){
        this->horasTrabajadas = horas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this, int sueldo){
    int todoOk = 0;

    if(this != NULL){
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
