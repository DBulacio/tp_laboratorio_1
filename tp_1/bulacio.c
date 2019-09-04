#include "bulacio.h"

/** \brief Funcion que recibe dos numeros y los suma.
 *
 * \param a int
 * \param b int
 * \return int resultado de la suma
 *
 */
int sumar(int a, int b){
    int resultado;

    resultado = a + b;

    return resultado;
}

/** \brief Funcion que recibe dos numeros y los resta
 *
 * \param a int
 * \param b int
 * \return int resultado de el primer numero menos el segundo
 *
 */
int restar(int a , int b){
    int resultado;

    resultado = a - b;

    return resultado;
}

/** \brief funcion que recibe dos numeros y los multiplica
 *
 * \param a int
 * \param b int
 * \return int resultado de la multiplicacion
 *
 */
int multiplicar(int a, int b){
    int resultado;

    resultado = a * b;

    return resultado;
}

/** \brief funcion que recibe dos numeros y los divide
 *
 * \param a int
 * \param b int
 * \return float resultado del primer numero divido el segundo
 *
 */
float dividir(int a, int b){
    float resultado;

    resultado = (float) a / b;

    return resultado;
}

/** \brief funcion que recibe un numero y calcula el factorial del mismo
 *
 * \param a int
 * \return int factorial del numero ingresado
 *
 */
int factorialA(int a){
    int resultado = 1;

    for(int i = a ; i > 0 ; i--){
        resultado *= i;
    }

    return resultado;
}

/** \brief funcion que recibe un numero y calcula el factorial del mismo
 *
 * \param b int
 * \return int factorial del numero ingresado
 *
 */
int factorialB(int b){  // funcion recursiva
    int resultado = 1;

    if(b > 1){
        resultado = b * factorialB(b - 1);
    }

    return resultado;
}
