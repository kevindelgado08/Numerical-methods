#define problema4
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
    //  e.g. f:pow(x,4) + 0.4*pow(x,2) - 12*x;
    return pow(x,4) + 0.4*pow(x,2) - 12*x;
}

/**
 * Algoritmo recursivo de Euler
 *
 * Sea f una función definida sobre un intervalo continuo [xi,xu]
 *
 * @param xi Valor de inicio del intervalo continuo sobre el que se define la función f
 * @param xf Valor de cierre del intervalo continuo sobre el que se define la función f
 * @param yi Valor de inicio de y
 * @param h Valor de incremento
 *
 * @return El valor de soluciones de la ecuacion diferencial
*/
float metodo_Euler(float xi, float xf, float yi, float h){
    std::cout << xi << "\t";
    std::cout << yi << "\t";
    std::cout << f(xi) << std::endl;
    float y_1 = yi + h*f(xi);
    if (xi == xf){
        return xi;
    }
    else if(xi < xf){
        if (xi+h > xf){
            return xi;
        }
        return metodo_Euler(xi+h,xf,y_1,h);
    }
}

/**
 * Algoritmo recursivo de Runge Kutta
 *
 * Sea f una función definida sobre un intervalo continuo [xi,xu]
 *
 * @param xi Valor de inicio del intervalo continuo sobre el que se define la función f
 * @param xf Valor de cierre del intervalo continuo sobre el que se define la función f
 * @param yi Valor de inicio de y
 * @param h Valor de incremento
 *
 * @return El valor de soluciones de la ecuacion diferencial
*/
float metodo_RungeKutta(float xi, float xf, float yi, float h){

    std::cout << xi << "\t";
    std::cout << yi << std::endl;

    float k1 = f(xi);
    float k2 = f(xi + (h/2));
    float k3 = f(xi + (h/2));
    float k4 = f(xi + h);

    float y_1= yi + (h/6)*(k1+(2*k2)+(2*k3)+k4);
    if (xi == xf){
        return xi;
    }
    else if(xi < xf){
        if (xi+h > xf){
            return xi;
        }
        return metodo_RungeKutta(xi+h,xf,y_1,h);
    }
}



int main(){
        std::cout << "Por el metodo de Euler \n" << std::endl;
        std::cout << "x:\ty:\tf(x): " << std::endl;
        metodo_Euler(0,10,1,1);

        std::cout << "Por el metodo de Runge Kutta \n" << std::endl;
        std::cout << "x:\ty: " << std::endl;
        metodo_RungeKutta(0,10,1,1);
}
