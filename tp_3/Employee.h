#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(int id, char* nombre, int horas, float sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horas);
int employee_getHorasTrabajadas(Employee* this,int* horas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

/* --- FUNCIONES DE SORTING --- */
int employee_compareById(void* emp1, void* emp2);
int employee_compareByName(void* emp1, void* emp2);
int employee_compareByHour(void* emp1, void* emp2);
int employee_compareBySalary(void* emp1, void* emp2);

#endif // employee_H_INCLUDED
