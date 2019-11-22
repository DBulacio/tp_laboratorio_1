#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int modelo;
    char marca[20];
}eAuto;

int menu();
eAuto* newAutoParam(int modelo, char* marca);
eAuto* newAuto();
int setModelo(eAuto* this, int modelo);
int setMarca(eAuto* this, char* marca);
int listAuto(LinkedList* list);
int switchAuto(LinkedList* list);
int removeAuto(LinkedList* list);
void sublistar(LinkedList* list, LinkedList* sublista);
int addAuto(LinkedList* list);
int getMarca(eAuto* this, char* name);
int compareByMarca(void* car1, void* car2);
int sortAuto(LinkedList* list);
int removeAutoPop(LinkedList* list);
void contains(LinkedList* list);

int main()
{
    int modelo;
    int cant;
    int flag = 0;
    char salir;
    char marca[20];
    char buffer[2][20];
    eAuto* aux = NULL;
    LinkedList* list = ll_newLinkedList();
    LinkedList* list2 = ll_newLinkedList();
    LinkedList* sublista = ll_newLinkedList();

    FILE* f = fopen("dato.csv", "r");

    if(list == NULL || f == NULL) {
        printf("ERROR: no se puedo asignar memoria. \n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    while(!feof(f)){
        cant = fscanf(f, "%[^,], %[^\n]\n", buffer[0], buffer[1]);
        if(cant == 2){
            modelo = atoi(buffer[0]);
            strcpy(marca, buffer[1]);

            aux = newAutoParam(modelo, marca);

            if(aux != NULL){
                ll_add(list, aux);
            } else {
                printf("ERROR: referencia nula");
            }
        }
    }

    do{
        switch(menu()){
            case 1:
                listAuto(list);
                break;
            case 2:
                switchAuto(list);
                break;
            case 3:
                removeAuto(list);
                break;
            case 4:
                if(ll_isEmpty(list)){
                    printf("la lista esta vacia\n");
                } else {
                    printf("la lista tiene elementos\n");
                }
                break;
            case 5:
                addAuto(list);
                break;
            case 6:
                list2 = ll_clone(list);
                flag = 1;
                printf("Lista Clonada\n\n");
                break;
            case 7:
                if(flag == 1){
                    if(ll_containsAll(list, list2)){
                        printf("Las listas son iguales\n\n");
                    } else {
                        printf("Las listas son distintas\n\n");
                    }
                }
                break;
            case 8:
                sublistar(list, sublista);
                break;
            case 9:
                sortAuto(list);
                break;
            case 10:
                removeAutoPop(list);
                break;
            case 11:
                contains(list);
                break;
            case 12:
                printf("¿Seguro quiere salir? (s/n) ");
                fflush(stdin);
                salir = getchar();
                if(salir == 's'){
                    printf("\n-----HASTA LUEGO!-----\n\n");
                }
                break;
            default:
                printf("ERROR: elija una opcion valida");
                break;
        }
        system("pause");
    }while(salir != 's');

    ll_clear(list);
    ll_deleteLinkedList(list);
    fclose(f);
    return 0;
}

int menu(){
    system("cls");
    int rta;

    printf("---BIENVENIDO AL SISTEMA---\n\n");
    printf("1. Listar Autos\n");
    printf("2. Reemplaza auto en indice\n");
    printf("3. Eliminar auto\n");
    printf("4. Informe si la lista esta o no vacia\n");
    printf("5. Agrega auto en indice y desplaza los demas\n");
    printf("6. Clonar la lista\n");
    printf("7. Comparar lista con lista clonada\n");
    printf("8. Hacer sublista\n");
    printf("9. Ordenar por marca\n");
    printf("10. Remover Auto Pop (Que sera?)\n");
    printf("11. Algo con contains\n");
    printf("12. Salir\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &rta);

    return rta;
}

eAuto* newAutoParam(int modelo, char* marca){
    eAuto* nuevo = newAuto();

    if(nuevo != NULL){
        if(setModelo(nuevo, modelo) && setMarca(nuevo, marca)){
            // CORRECTAMENTE CARGADO
        } else {
            nuevo = NULL;
        }
    }
    return nuevo;
}

eAuto* newAuto(){
    eAuto* nuevo = (eAuto*) malloc(sizeof(eAuto));

    if(nuevo != NULL){
        nuevo->modelo = 0;
        strcpy(nuevo->marca, " ");
    }

    return nuevo;
}

int setModelo(eAuto* this, int modelo){
    int todoOk = 0;

    if(this != NULL){
        this->modelo = modelo;
        todoOk = 1;
    }

    return todoOk;
}

int setMarca(eAuto* this, char* marca){
    int todoOk = 0;

    if(this != NULL && marca != NULL){
        strcpy(this->marca, marca);
        todoOk = 1;
    }

    return todoOk;
}

int listAuto(LinkedList* list){
    int todoOk = 0;
    eAuto* car = NULL;

    if(list == NULL){
        return todoOk;
    }

    printf("\tMODELO\tMARCA\n");
    for(int i = 0 ; i < ll_len(list) ; i++){
        car = (eAuto*) ll_get(list, i);

        if(car != NULL){
            printf("\t %d \t %10s\n", car->modelo, car->marca);
            todoOk = 1;
        }
    }

    return todoOk;
}


int switchAuto(LinkedList* list)
{
    int todoOk = 0;
    char marca[20];
    char buffer[20];
    int bufferInt;
    int indice;
    int modelo;
    eAuto* nuevo = newAuto();

    if(list == NULL || nuevo == NULL){
        return todoOk;
    }

    /* --- PIDO LOS DATOS --- */

    printf("Ingrese la marca: ");
    fflush(stdin);
    gets(marca);
    bufferInt = atoi(marca);

    while(bufferInt != '\0'){
        printf("ERROR. Ingrese la marca: ");
        fflush(stdin);
        gets(marca);
        bufferInt = atoi(marca);
    }

    setMarca(nuevo, marca);

    printf("Ingrese el modelo: ");
    fflush(stdin);
    gets(buffer);
    modelo = atoi(buffer);

    while(modelo == '\0'){
        printf("ERROR. Ingrese el modelo: ");
        fflush(stdin);
        gets(buffer);
        modelo = atoi(buffer);
    }

    setModelo(nuevo, modelo);

    if(nuevo == NULL){
        return todoOk;
    } else {
        printf("Indique el indice al que quiere ingresarlo: ");
        scanf("%d", &indice);
        ll_set(list, indice, nuevo);
        todoOk = 1;
    }

    return todoOk;
}

int removeAuto(LinkedList* list){
    int todoOk = 0;
    int indice;

    listAuto(list);

    printf("Indique el indice del auto a remover: ");
    scanf("%d", &indice);

    ll_remove(list, indice);
    printf("Auto removido\n");

    return todoOk;
}

int addAuto(LinkedList* list)
{
    int todoOk = 0;
    char marca[20];
    char buffer[20];
    int bufferInt;
    int indice;
    int modelo;
    eAuto* nuevo = newAuto();

    if(list == NULL || nuevo == NULL){
        return todoOk;
    }

    /* --- PIDO LOS DATOS --- */

    printf("Ingrese la marca: ");
    fflush(stdin);
    gets(marca);
    bufferInt = atoi(marca);

    while(bufferInt != '\0'){
        printf("ERROR. Ingrese la marca: ");
        fflush(stdin);
        gets(marca);
        bufferInt = atoi(marca);
    }

    setMarca(nuevo, marca);

    printf("Ingrese el modelo: ");
    fflush(stdin);
    gets(buffer);
    modelo = atoi(buffer);

    while(modelo == '\0'){
        printf("ERROR. Ingrese el modelo: ");
        fflush(stdin);
        gets(buffer);
        modelo = atoi(buffer);
    }

    setModelo(nuevo, modelo);

    if(nuevo == NULL){
        return todoOk;
    } else {
        printf("Indique el indice al que quiere ingresarlo: ");
        scanf("%d", &indice);
        ll_push(list, indice, nuevo);
        todoOk = 1;
    }

    return todoOk;
}

void sublistar(LinkedList* list, LinkedList* sublista){
    int from;
    int to;

    listAuto(list);

    printf("Indique desde donde: ");
    scanf("%d", &from);
    printf("Indique hasta donde: ");
    scanf("%d", &to);

    sublista = ll_subList(list, from, to);
}

int sortAuto(LinkedList* list)
{
    int todoOk = 0;
    void* car1 = NULL;
    void* car2 = NULL;
    void* aux = NULL;

    if(list == NULL){
        return todoOk;
    }

    for(int i = 0 ; i < ll_len(list) - 1 ; i++){
        for(int j = i + 1 ; j < ll_len(list) ; j++){
            car1 = ll_get(list, i);
            car2 = ll_get(list, j);
            if(ll_sort(list, compareByMarca, 0)){
                aux = car1;
                car1 = car2;
                car2 = aux;
            }
        }
    }

    printf("Autos ordenados correctamente\n\n");
    todoOk = 1;
    return todoOk;
}

int compareByMarca(void* car1, void* car2){
    char name1[20];
    char name2[20];

    getMarca((eAuto*) car1, name1);
    getMarca((eAuto*) car2, name2);

    return(strcmp(name1, name2));
}

int getMarca(eAuto* this, char* name){
    int todoOk = 0;

    if(this == NULL || name == NULL){
        return todoOk;
    }

    *name = this->marca;
    todoOk = 1;
    return todoOk;
}

int removeAutoPop(LinkedList* list){
    int todoOk = 0;
    int indice;
    eAuto* car = NULL;

    listAuto(list);

    printf("Indique el indice del auto a remover: ");
    scanf("%d", &indice);

    car = (eAuto*) ll_pop(list, indice);

    indice = ll_indexOf(list, car);
    printf("Auto removido del indice %d. Se corrieron todos los que le seguian una posicion hacia atras\n", indice);

    return todoOk;
}

void contains(LinkedList* list){
    int indice;
    eAuto* car = NULL;

    listAuto(list);

    printf("Indique un indice: ");
    scanf("%d", &indice);

    car = ll_get(list, indice);

    if(ll_contains(list, car)){
        printf("El auto esta en la lista\n");
    } else {
        printf("Como llegaste a este printf???");
    }
}
