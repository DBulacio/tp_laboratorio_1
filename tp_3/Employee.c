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

int employee_setSueldo(Employee* this, float sueldo){
    int todoOk = 0;

    if(this != NULL){
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getId(Employee* this,int* id){
    int todoOk = 0;

    if(this == NULL || id == NULL){
        return todoOk;
    }

    *id = this->id;
    todoOk = 1;
    return todoOk;
}

int employee_getNombre(Employee* this, char* name){
    int todoOk = 0;

    if(this == NULL || name == NULL){
        return todoOk;
    }

    *name = this->nombre;
    todoOk = 1;
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horas){
    int todoOk = 0;

    if(this == NULL || horas == NULL){
        return todoOk;
    }

    *horas = this->horasTrabajadas;
    todoOk = 1;
    return todoOk;
}

int employee_getSueldo(Employee* this,float* sueldo){
    int todoOk = 0;

    if(this == NULL || sueldo == NULL){
        return todoOk;
    }

    *sueldo = this->sueldo;
    todoOk = 1;
    return todoOk;
}








//--------------------
int employee_compareById(void* emp1, void* emp2){
    int id1 = 0;
    int id2 = 0;
    employee_getId((Employee*) emp1, &id1);
    employee_getId((Employee*) emp2, &id2);

    if(id1 > id2){
        return 1;
    } else if(id1 < id2){
        return -1;
    }
    return 0;
}

int employee_compareByName(void* emp1, void* emp2){
    char name1[128];
    char name2[128];

    employee_getNombre((Employee*) emp1, name1);
    employee_getNombre((Employee*) emp2, name2);

    return(strcmp(name1, name2));
}

int employee_compareByHour(void* emp1, void* emp2){
    int h1 = 0;
    int h2 = 0;
    employee_getHorasTrabajadas((Employee*) emp1, &h1);
    employee_getHorasTrabajadas((Employee*) emp2, &h2);

    if(h1 > h2){
        return 1;
    } else if(h1 < h2){
        return -1;
    }
    return 0;
}

int employee_compareBySalary(void* emp1, void* emp2){
    float s1 = 0;
    float s2 = 0;
    employee_getSueldo((Employee*) emp1, &s1);
    employee_getSueldo((Employee*) emp2, &s2);

    if(s1 > s2){
        return 1;
    } else if(s1 < s2){
        return -1;
    }
    return 0;
}
