typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/** \brief setea todas las posiciones del array en 1, lo que significa que no hay un empleado
 *         cargado en esa posicion.
 *
 * \param vec[] Employee
 * \param tam int
 * \return int
 *
 */
int initEmployees(Employee vec[], int tam);

/** \brief pide nombre, apellido, salario y sector del empleado
 *         y pasa estos valores (junto con el id que se calcula automaticamente
 *         a addEmployee()
 *
 * \param vec[] Employee
 * \param tam int
 * \param id int
 * \return int
 *
 */
int askForEmployeeParameters(Employee vec[], int tam, int id);

/** \brief agrega los datos recibidos por askForEmployeeParameters() a
 *         una posicion del array de empleados. Setea el isEmpty en esa posicion a 0
 *
 * \param vec[] Employee
 * \param tam int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(Employee vec[], int tam, int id, char name[], char lastName[], float salary, int sector);

/** \brief recibe un id y busca el employee correspondiente.
           cuando lo encuentra, devuelve la posicion del employee en el array
 *
 * \param vec[] Employee
 * \param tam int
 * \param id int
 * \return int
 *
 */
int findEmployeeById(Employee vec[], int tam, int id);

/** \brief muestra el listado de todos los employees por pantalla
 *
 * \param vec[] Employee
 * \param tam int
 * \return void
 *
 */
void printEmployees(Employee vec[], int tam);

/** \brief muestra un employee especifico con todos sus atributos.
 *
 * \param x Employee
 * \return void
 *
 */
void printEmployee(Employee x);

/** \brief permite modificar y, por lo tanto, sobreescribir los atributos de un employee.
 *
 * \param vec[] Employee
 * \param tam int
 * \return void
 *
 */
void modifyEmployee(Employee vec[], int tam);

/** \brief modifica el isEmpty del employee correspondiente al id recibida,
 *         haciendolo invisible al resto de funciones.
 *
 * \param vec[] Employee
 * \param tam int
 * \param id int
 * \return void
 *
 */
void removeEmployee(Employee vec[], int tam, int id);

/** \brief ordena los employee por sector (de forma ascendente o descendente)
 *         y los llama a la funcion para ordenarlos alfabeticamente.
 *
 * \param vec[] Employee
 * \param tam int
 * \param order int
 * \return void
 *
 */
void sortEmployee(Employee vec[], int tam, int order);

/** \brief recorre el array buscando la primer posicion donde no haya un employee activo.
 *         devuelve dicha posicion del array.
 *
 * \param vec[] Employee
 * \param tam int
 * \return int
 *
 */
int lookForEmptyPosition(Employee vec[], int tam);

/** \brief con fines de testing, hardcodeo 10 empleados para ver que todo funcione.
 *
 * \param vec[] Employee
 * \param tam int
 * \param cant int
 * \return void
 *
 */
void hardcodeEmployee(Employee vec[], int tam, int cant);

/** \brief muestra un menu con las opciones que puede modificar el usuario
 *
 * \return void
 *
 */
void modifyMenu();

/** \brief si estan ordenados por sector, ordena a los employee alfabeticamente
 *
 * \param vec[] Employee
 * \param tam int
 * \return void
 *
 */
void ordenarAlfabeticamente(Employee vec[], int tam);

/** \brief muestra y calcula la suma de todos los salarios, el promedio, y los employee con salarios mayores al promedio.
 *
 * \param vec[] Employee
 * \param tam int
 * \return void
 *
 */
void informeSalario(Employee vec[], int tam);
