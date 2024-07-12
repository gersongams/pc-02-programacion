#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int analizarOracion(const string& oracion) {
    istringstream iss(oracion);
    string palabra;
    int suma = 0;
    int contadorPalabras = 0;

    while (iss >> palabra) {
        if (all_of(palabra.begin(), palabra.end(), ::isdigit)) {
            suma += stoi(palabra);
        } else {
            set<char> vocales;
            for (char c : palabra) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    vocales.insert(lower);
                }
            }
            if (vocales.size() == 3) {
                contadorPalabras++;
            }
        }
    }

    int r = suma % 5;
    int n = r + 1;

    cout << "Hay " << contadorPalabras << " palabras con 3 vocales diferentes" << endl;
    cout << "Nota: s = " << suma << "; r = " << r << "; n = " << n << ";" << endl;

    return contadorPalabras;
}

int main() {
    string oracion;
    cout << "Ingrese una oración (máximo 200 caracteres): ";
    getline(cin, oracion);

    if (oracion.length() > 200) {
        cout << "La oración excede los 200 caracteres." << endl;
        return 1;
    }

    int resultado = analizarOracion(oracion);
    cout << "Resultado: " << resultado << endl;

    return 0;
}