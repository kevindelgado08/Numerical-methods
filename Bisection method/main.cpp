#define problema1
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
    //  e.g. f: pow(x,6) - pow(x,4) - pow(x,3) -1 ;
    return pow(x,6) - pow(x,4) - pow(x,3) -1;
}

/**
 * Derivada de f utilizada en el algoritmo
 *
 * @param x Preimagen de la derivada
 * @return La imagen de x evaluada en df
 */
float df(float x){
    //  e.g. f: pow(x,6) - pow(x,4) - pow(x,3) -1 ;
    return 6*pow(x,5) - 4*pow(x,3) - 3*pow(x,2);
}

/**
 * Algoritmo recursivo de Bisección
 *
 * Sea f una función definida sobre un intervalo continuo [xi,xu]
 *
 * @param xi Valor de inicio del intervalo continuo sobre el que se define la función f
 * @param xu Valor de cierre del intervalo continuo sobre el que se define la función f
 * @param E Valor de error definido por el usuario
 *
 * @return El valor dentro del intervalo que es un cero de f
 * @throws ArgumentosInvalidos! Mensaje de error cuando no se cumple que f(xi) y f(xu)
 tienen distinto signo.
*/
float biseccion(float xi, float xu, float E){
    if ((f(xi)*f(xu)) < 0){ //si los argumentos son validos
        // calcula xr
        float xr = (xi+xu) / 2;

        // imprime los x's en consola como tabla
        std::cout << xi << "\t";
        std::cout << xu << "\t";
        std::cout << xr << std::endl;

        if (f(xi)*f(xr) == 0){
            // La raíz ha sido encontrada
            return xr;
        }
        else if(f(xi)*f(xr) < 0){
            xu = xr;
        }
        else if(f(xu)*f(xr) < 0){
            xi = xr;
        }
        // Calcula el siguiente xr para evaluar la salida
        float xr_2 = (xi+xu) / 2;
        if (abs(xr_2 - xr) < E){
            // La raíz ha sido encontrada
            return xr;
        } else {
            // Llamado recursivo, debe seguir buscando la raíz
            return biseccion(xi,xu,E);
        }
    } else {
        throw "Argumentos invalidos!";
    }
}

/**
 * Algoritmo recursivo de Newton Rapson
 *
 * Sea f una función definida sobre un intervalo continuo [xi,xu]
 *
 * @param xi Valor de inicio del intervalo continuo sobre el
    que se define la función f
 * @param E Valor de error definido por el usuario
 *
 * @return El valor dentro del intervalo que es un cero de f
*/
float newton_rapson(float xi, float E){

   std::cout << xi << std::endl;
   float xr_2 = xi - (f(xi)/df(xi));
   if (abs(xr_2 - xi) < E){
        return xr_2;
   }
   else{
        xi = xr_2;
        return newton_rapson(xi,E);
   }
}


int main(){
    try{
        std::cout << "Por el metodo de Biseccion \n" << std::endl;
        std::cout << "xi:\txu:\txr:" << std::endl;
        float raiz = biseccion(1,1.6,0.000005);
        std::cout << "\nPor lo tanto, la raiz es aproximadamente: " << raiz << std::endl;

        std::cout << "\n\nPor el metodo de Newton Rapson \n" << std::endl;
        std::cout << "xr:" << std::endl;
        float raiz2 = newton_rapson(1.6,0.00005);
        std::cout << "\nPor lo tanto, la raiz es aproximadamente: " << raiz2 << std::endl;

    } catch (const char* msg){
        std::cout << msg << std::endl;
    }
}
