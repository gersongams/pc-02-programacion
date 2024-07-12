#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_EMPLEADOS = 100;
const int MAX_ELEMENTOS = 1000;

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int datos[MAX_ELEMENTOS];
    int n, totalElementos = 0;

    cout << "Ingrese el número de empleados: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int codigo, meses;
        cout << "Ingrese el código del empleado " << i+1 << " (3 dígitos): ";
        cin >> codigo;
        datos[totalElementos++] = codigo;

        cout << "Ingrese el número de meses con horas extras: ";
        cin >> meses;

        for (int j = 0; j < meses; j++) {
            int horas;
            cout << "Ingrese las horas extras del mes " << j+1 << " (2 dígitos): ";
            cin >> horas;
            datos[totalElementos++] = horas;
        }
    }

    cout << "Arreglo original: ";
    mostrarArreglo(datos, totalElementos);

    int totalHoras = 0, contadorEmpleados = 0;
    for (int i = 0; i < totalElementos; i++) {
        if (datos[i] >= 100) {
            contadorEmpleados++;
        } else {
            totalHoras += datos[i];
        }
    }
    double promedio = static_cast<double>(totalHoras) / contadorEmpleados;

    cout << "Promedio de horas extras: " << fixed << setprecision(2) << promedio << endl;

    int nuevoTotal = 0;
    for (int i = 0; i < totalElementos; i++) {
        if (datos[i] >= 100) {
            int horasEmpleado = 0;
            int j = i + 1;
            while (j < totalElementos && datos[j] < 100) {
                horasEmpleado += datos[j];
                j++;
            }
            if (horasEmpleado <= promedio) {
                datos[nuevoTotal++] = datos[i];
                for (int k = i + 1; k < j; k++) {
                    datos[nuevoTotal++] = datos[k];
                }
            }
            i = j - 1;
        }
    }

    cout << "Arreglo después de la eliminación: ";
    mostrarArreglo(datos, nuevoTotal);

    return 0;
}