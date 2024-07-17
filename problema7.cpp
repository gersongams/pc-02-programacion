#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_EMPLEADOS = 100;
const int MAX_ELEMENTOS = 1000;

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mostrarOriginal(int n, int arr[]){
    int index = 0;
    for (int i = 0; i < n; ++i) {
        int codigo = arr[index++];
        int meses = arr[index++];
        cout << "Empleado " << codigo << ": ";
        for (int j = 0; j < meses; ++j) {
            cout << arr[index++] << " ";
        }
        cout << endl;
    }
}

bool EsUnNumero(const char* cadena) {
    for (; *cadena; ++cadena) {
        if (!std::isdigit(*cadena)) {
            return false;
        }
    }
    return true;
}

int main() {
    int datos[MAX_ELEMENTOS];
    int n, totalElementos = 0;
    int nOK = 0;

    cout << "Ingrese el número de empleados: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int meses;
        char codigo[4];
        cout << "Ingrese el código del empleado " << i+1 << " (3 dígitos): ";
        cin >> codigo;

        if (EsUnNumero(codigo) && std::atoi(codigo) >= 100 && std::atoi(codigo) <= 999) {
            datos[totalElementos++] =  atoi(codigo);
            cout << "Ingrese el número de meses con horas extras: ";
            cin >> meses;
            datos[totalElementos++] = meses;
            for (int j = 0; j < meses; j++) {
                char horas[3];
                cout << "Ingrese las horas extras del mes " << j+1 << " (2 dígitos): ";
                cin >> horas;
                if (EsUnNumero(horas) && std::atoi(horas) >= 10 && std::atoi(horas) <= 99) {
                    datos[totalElementos++] = atoi(horas);
                } else {
                    cout << "Código inválido: El código debe ser de 2 dígitos y un entero positivo." << endl;
                    j--; // Reintentar la entrada de horas extras
                }
            }
            nOK++;
        } else {
            cout << "Código inválido: El código debe ser de 3 dígitos y un entero positivo." << endl;
            i--; // Reintentar la entrada del código del empleado
        }
    }

    cout << "\nArreglo original:" << endl;
    mostrarOriginal(nOK, datos);

    int totalHoras = 0, contadorEmpleados = 0;
    int index = 0;

    while (index < totalElementos) {
        int codigo = datos[index++];
        int meses = datos[index++];
        contadorEmpleados++;
        for (int j = 0; j < meses; j++) {
            totalHoras += datos[index++];
        }
    }

    double promedio = static_cast<double>(totalHoras) / contadorEmpleados;

    cout << "\nPromedio de horas extras: " << fixed << setprecision(2) << promedio << endl;

    int nuevoTotal = 0;
    index = 0;
    int nEliminados = 0;
    while (index < totalElementos) {
        int codigo = datos[index];
        int meses = datos[index + 1];
        int horasEmpleado = 0;

        for (int j = 0; j < meses; j++) {
            horasEmpleado += datos[index + 2 + j];
        }

        if (horasEmpleado <= promedio) {
            datos[nuevoTotal++] = codigo;
            datos[nuevoTotal++] = meses;
            for (int j = 0; j < meses; j++) {
                datos[nuevoTotal++] = datos[index + 2 + j];
            }
            nEliminados++;
        }
        index += 2 + meses;
    }

    cout << "\nArreglo después de la eliminación: ";
    mostrarOriginal(nEliminados, datos);
    return 0;
}
