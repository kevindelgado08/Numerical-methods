#define problema3
#include <iostream>
#include <iomanip>
#include <math.h>

/**
 * Función f utilizada en el algoritmo
 *
 * @param x Preimagen de la función
 * @return La imagen de x evaluada en f
 */
float f(float x){
    return sqrt(2+(pow(x,2))) / sqrt(2-(pow(x,2)));
}

/**
 * Función comparacion
 *
 * @param a Valor inicial
 * @param b Valor final
 * @param a Porcentaje de error
 * @return Verdadero o falso
 */
bool AreSame(float a, float b, float epsilon)
{
    return fabs(a - b) < epsilon;
}

/**
  * Este método recursivo calcula la suma de "y´s" pares e impares
  *     dejando el resultado de la sumatoria escrito en un vector
  *     totales[0] es la suma de los pares,
  *     totales[1] es la suma de los impares,
  */
void suma_de_yes(float totales[], float xn, float h, int iteracion, float xf){

    float yn = f(xn);

     if(iteracion%2 == 0){ //si la iteracion es par
        totales[0] = totales[0] + yn;
     } else {
        totales[1] = totales[1] + yn;
     }
     if ( !AreSame(xn+h,xf,0.0005) ){
        suma_de_yes(totales, xn+h, h, iteracion+1, xf);
     }
}

/**
  * Esta función retorna el resultado de la integral de una función f dada
  *    en el intervalo [Xi, Xf], usando el metodo simpson
  *    con n distinto de cero
  **/
float metodo_simpson(float xi, float xf, int n){
    float h = (xf - xi)/n;
    float totales[2]; // almacenamos acá la suma de los y'es para calcular la integral
    totales[0] = 0; totales[1] = 0; // limpia el vector
    suma_de_yes(totales, xi, h, 1, xf); // se obtiene la suma

    return (h/3) * (f(xi) + 4 * totales[0] + 2 * totales[1] + f(xf));

}

int main(){
    float integral = metodo_simpson(-1,1,250);
    std::cout << "\nPor lo tanto, la integral es aproximadamente: " << integral << std::endl;
}
