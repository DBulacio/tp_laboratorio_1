typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int initEmployees(Employee vec[], int tam);
int addEmployee(Employee vec[], int tam, int id, char name[], char lastName[], float salary, int sector);
void findEmployeeById(Employee vec[], int tam, int id);
void removeEmployee(Employee vec[], int tam, int id);
void sortEmployee(Employee vec[], int tam, int order);
void printEmployees(Employee vec[], int tam);
void printEmployee(Employee x);

int lookForEmptyPosition(Employee vec[], int tam);
int newEmployee(Employee vec[], int tam, int id);
