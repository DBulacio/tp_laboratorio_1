typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int initEmployees(Employee vec[], int tam);
int askForEmployeeParameters(Employee vec[], int tam, int id);
int addEmployee(Employee vec[], int tam, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee vec[], int tam, int id);
void printEmployees(Employee vec[], int tam);
void printEmployee(Employee x);
void modifyEmployee(Employee vec[], int tam);

void removeEmployee(Employee vec[], int tam, int id);
void sortEmployee(Employee vec[], int tam, int order);

int lookForEmptyPosition(Employee vec[], int tam);
void hardcodeEmployee(Employee vec[], int tam, int cant);
void modifyMenu();
void ordenarAlfabeticamente(Employee vec[], int tam);
void informeSalario(Employee vec[], int tam);
