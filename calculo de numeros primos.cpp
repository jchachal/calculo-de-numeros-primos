// calculo de numeros primos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Ingresa un numero entero positivo N"<<endl;
    cin >> N;

    // Validar que N sea positivo
    if (N <= 0) {
        cout << "Por favor, ingresa un numero positivo." << endl;
        return 1;
    }

    vector<int> numerosPrimos; // Vector para almacenar los números primos
    int numeroActual = 2; // Número desde el que comenzamos a buscar primos

    // Encontrar los primeros N números primos
    while (numerosPrimos.size() < N) {
        if (esPrimo(numeroActual)) {
            numerosPrimos.push_back(numeroActual); // Agregar número primo al vector
        }
        numeroActual++;
    }

    // Imprimir la lista de números primos
    cout << "Los primeros " << N << " numeros primos son: ";
    for (int primo : numerosPrimos) {
        cout << primo << " ";
    }
    cout << endl;


    return 0;
}