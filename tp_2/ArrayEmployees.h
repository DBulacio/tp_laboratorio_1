typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

void initEmployees(Employee vec[], int tam);
void addEmployee(Employee vec[], int tam, int id, char name[], char lastName[], float salary, int sector);
void findEmployeeById(Employee vec[], int tam, int id);
void removeEmployee(Employee vec[], int tam, int id);
void sortEmployee(Employee vec[], int tam, int order);
void printEmployee(Employee vec[], int tam);
