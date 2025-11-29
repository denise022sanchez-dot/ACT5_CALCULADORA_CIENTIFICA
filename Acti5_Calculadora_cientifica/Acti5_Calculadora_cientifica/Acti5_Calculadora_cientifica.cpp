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
        cout << "6. Potencia " << endl;
        cout << "7. Cuadrado de un numero " << endl;
        cout << "8. Raiz Cuadrada" << endl;
        cout << "9. Factorial" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        try {

            switch (opcion) {

            case 1:
                cout << "Ingrese dos numeros: ";
                cin >> num1 >> num2;
                //busca la función sumar que acepta 2
                cout << "Resultado: " << sumar(num1, num2) << endl;
                break;

            case 2:
                cout << "Ingrese tres numeros: ";
                cin >> num1 >> num2 >> num3;
                //Ve 3 argumentos y usa automáticamente la versión de sumar para 3
                cout << "Resultado: " << sumar(num1, num2, num3) << endl;
                break;
            
            
            case 3:
                cout << "Ingrese dos numeros para restar: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << restar(num1, num2) << endl;
                break;
            
            
            case 4:
                cout << "Ingrese dos numeros para multiplicar: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << multiplicar(num1, num2) << endl;
                break;
            
            
            case 5:
                cout << "Ingrese dividendo y divisor: ";
                cin >> num1 >> num2;
                //Si num2 es 0, la función dividir lanzará un error y saltaremos directo al catch
                cout << "Resultado: " << dividir(num1, num2) << endl;
                break;
            
            
            case 6:
                cout << "Ingrese base y exponente: ";
                cin >> num1 >> numFactorial;
                //Aquí se envian los DOS argumentos explícitamente, no se usa el valor por defecto
                cout << "Resultado: " << potencia(num1, numFactorial) << endl;
                break;
            
            case 7:
                cout << "Ingrese el numero a elevar al cuadrado: ";
                cin >> num1;
                //Llamamos a 'potencia' enviando SOLO la base
                //Como falta el segundo argumento, el programa usa automáticamente el "2" definido en el prototipo.
                cout << "Resultado: " << potencia(num1) << endl;
                break;

            case 8:
                cout << "Ingrese numero para raiz: ";
                cin >> num1;
                //Si num1 es negativo, raizCuadrada lanza un error y saltamos al catch
                cout << "Resultado: " << raizCuadrada(num1) << endl;
                break;

            case 9:
                cout << "Ingrese un entero positivo: ";
                cin >> numFactorial;
                //Verificación manual antes de llamar a la función
                //throw runtime_error crea un error manualmente y lo lanza al catch
                if (numFactorial < 0) throw runtime_error("El factorial no esta definido para negativos.");
                cout << "Resultado: " << factorial(numFactorial) << endl;
                break;

            case 0:
                cout << "Saliendo..." << endl;
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