#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void registrarVentas(vector<double>& ventas) {
    vector<string> dias_semana = { "Lunes", "Martes", "Miircoles", "Jueves", "Viernes", "Sabado", "Domingo" };
    double venta;

    for (int i = 0; i < 7; ++i) {
        cout << "Ingrese las ventas del dia " << dias_semana[i] << ": ";
        cin >> venta;
        ventas[i] = venta;
    }
}

void guardarVentasEnArchivo(const vector<double>& ventas) {
    ofstream archivo("ventas_semanales.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < ventas.size(); ++i) {
            archivo << "Dia " << i + 1 << ": " << ventas[i] << endl;
        }
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
    }
}

void mostrarResultados(const vector<double>& ventas) {
    vector<string> dias_semana = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo" };
    double totalVentas = 0;
    int diaMaxVentas = 0;
    double maxVentas = 0;
    bool huboDiaSinVentas = false;

    // Calcular el total de ventas y el día con mayores ventas
    for (int i = 0; i < ventas.size(); ++i) {
        totalVentas += ventas[i];
        if (ventas[i] > maxVentas) {
            maxVentas = ventas[i];
            diaMaxVentas = i + 1;
        }
        if (ventas[i] == 0) {
            huboDiaSinVentas = true;
            cout << "No hubo ventas el dia " << dias_semana[i] << "." << endl;
        }
    }

    // Mostrar los resultados
    cout << "\nEl total de ventas de la semana es: Q." << totalVentas << endl;
    cout << "El dia con mayores ventas fue el dia " << dias_semana[diaMaxVentas - 1] << " con Q." << maxVentas << " de ventas." << endl;

    if (!huboDiaSinVentas) {
        cout << "No hubo dias sin ventas." << endl;
    }
}

int main() {
    vector<double> ventas(7); // Asegurándonos de que el vector tiene 7 elementos

    // Registrar las ventas
    registrarVentas(ventas);

    // Guardar las ventas en un archivo
    guardarVentasEnArchivo(ventas);

    // Mostrar los resultados
    mostrarResultados(ventas);

    return 0;
}
