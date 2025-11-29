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
   

    int opcion;
    double num1, num2, num3; //Se declaran las variables para guardar los números que escriba el usuario.
    int numFactorial;        //Variable exclusiva para enteros que se usa en potencia y factorial


    do {
        // Mostrar Menú en pantalla
        cout << "\n--- CALCULADORA AVANZADA ---" << endl;
        cout << "1. Sumar (2 numeros)" << endl;
        cout << "2. Sumar (3 numeros) [Sobrecarga]" << endl;
        cout << "3. Restar" << endl;
        cout << "4. Multiplicar" << endl;
        cout << "5. Dividir" << endl;
        cout << "6. Potencia (con exponente personalizado)" << endl;
        cout << "7. Cuadrado de un numero (Parametro por omision)" << endl;
        cout << "8. Raiz Cuadrada" << endl;
        cout << "9. Factorial" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        try {

            switch (opcion) {

            case 1:
                break;

            case 2:
                break;
            
            
            case 1:
                break;
            
            
            case 1:
                break;
            
            
            case 1:
                break;
            
            
            case 1:
                break;
            
            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            default:

                cout << "Opcion no valida." << endl;
            }

        }
        //en el catch: si alguien lanzó un throw runtime_error arriba, este bloque lo atrapa
        //La variable 'e' contiene el mensaje de error
        catch (const exception& e) {
            cout << "\nError: " << e.what() << endl; //.what extrae el texto del mensaje de error
        }

    } while (opcion != 0); //si opcion es 0, el bucle termina y el programa finaliza.


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


double dividir(double a, double b) {
    //Excepción
        //Antes de dividir, verificamos si el denominador es 0
    if (b == 0) {
        //throw detiene la función inmediatamente No devuelve nada, sino que "tira" el error al 'try-catch' del main.
        throw runtime_error("Division entre cero no permitida.");
    }
    return a / b;
}


//Parámetros por omisión
//Aqui NO se pone el = 2, eso solo va en el prototipo de arriba. Aquí se define normal.
double potencia(double base, int exponente) {
    return pow(base, exponente); //Funcion de la librería <cmath>.
}

double raizCuadrada(double numero) {
    //Excepción para raíz negativa
    if (numero < 0) {
        //Si es negativo, lanzamos el error y evitamos que el programa falle haciendo cálculos imposibles.
        throw runtime_error("No se puede calcular raiz cuadrada de numero negativo.");
    }
    return sqrt(numero); //Función de la librería <cmath>.
}

//Se utiliza recursividad
long long factorial(int n) {
    //Caso Base, es la condición para que la recursividad se detenga.
    //El factorial de 0 o 1 es siempre 1. Sin esto, la función se llamaría infinitamente hasta colapsar la memoria
    if (n == 0 || n == 1) return 1;

    //La función se llama a sí misma dentro de sí misma.
    return n * factorial(n - 1);
}