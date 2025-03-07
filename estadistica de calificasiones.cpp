#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> N;

    vector<float> calificaciones(N);
    float suma = 0;
    float maxCalificacion = -1; // Inicializamos con un valor bajo
    float minCalificacion = 101; // Inicializamos con un valor alto
    int aprobados = 0;
    int reprobados = 0;

    // Ingreso de calificaciones
    for (int i = 0; i < N; i++) {
        cout << "Ingrese la calificacion del estudiante " << (i + 1) << ": ";
        cin >> calificaciones[i];

        // Acumulamos la suma para el promedio
        suma += calificaciones[i];

        // Encontramos la calificación más alta y la más baja
        if (calificaciones[i] > maxCalificacion) {//verifica el valor actual de la calificasion en la posicion i para verificar si es mayor al que esta almacenado
            maxCalificacion = calificaciones[i];// Si la condición es verdadera, actualiza el valor de `maxCalificacion` con la calificación actual, ya que es la nueva calificación más alta.
        }
        if (calificaciones[i] < minCalificacion) {//verifica el valor actual de la calificasion en a posicion i para verificar si es menor al que esta almacenado
            minCalificacion = calificaciones[i];// Si la condición es verdadera, actualiza el valor de `minCalificacion` con la calificación actual, ya que es la nueva calificación más baja.
        
        }

        // Contamos aprobados y reprobados
        if (calificaciones[i] >= 60) {
            aprobados++;
        }
        else {
            reprobados++;
        }
    }

    // Cálculo del promedio
    float promedio = suma / N;

    // Resultados
    cout << "Calificación mas alta: " << maxCalificacion << endl;// Imprime la frase Calificación más alta
    cout << "Calificación mas baja: " << minCalificacion << endl;//imprime la frase calificasion minima
    cout << "Promedio de calificaciones: " << promedio << endl;//imprime la frase calificasion promedio
    cout << "Estudiantes aprobados: " << aprobados << endl;//imprime la frase calificasiion aprobada
    cout << "Estudiantes reprobados: " << reprobados << endl;//imprime la frase calificasion reprobada

    return 0;
}

