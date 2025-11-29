#include <iostream> //Biblioteca estándar para entrada cin y salida cout de datos.
#include <cmath> //Biblioteca matemática que me permite usar herramientas como pow() para potencia y sqrt() para raíz.
#include <stdexcept> //Biblioteca de excepciones que permite usar 'runtime_error' para manejar errores sin crashear.


using namespace std;

//Se declaran las funciones que se usaran en el programa antes de crearlas 

double sumar(double a, double b); //funciones para sumar dos numeros


double sumar(double a, double b, double c); //Declaramos otra función con el MISMO nombre sumar, pero con 3 numeros

double restar(double a, double b);
double multiplicar(double a, double b);

double dividir(double a, double b);// Esta función promete devolver un double, pero si algo sale mal división por 0, lanzará una excepción.


double potencia(double base, int exponente = 2); // Al poner exponente = 2, le decimos al compilador que si el usuario no me da el segundo número, asume que es un 2
//Esto solo se escribe aquí en el prototipo, no abajo en la implementación.

double raizCuadrada(double numero);
long long factorial(int n); // Usamos long long porque los factoriales crecen muy rápido y necesitan más memoria


int main()
{
   cout << "Hello World!\n";



   return 0;
}


//Se desarrollan las funcioens


double sumar(double a, double b) {
    return a + b; //Devuelve la suma simple.
}

double sumar(double a, double b, double c) {  //Esta es una función distinta en memoria a la anterior, aunque se llamen igual
    return a + b + c; //Devuelve la suma de 3.
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}


