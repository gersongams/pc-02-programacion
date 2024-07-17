#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

int analizarOracion(const string& oracion) {
    istringstream iss(oracion);
    string palabra;
    int suma = 0;
    int contadorPalabras = 0;

    while (iss >> palabra) {
        if (all_of(palabra.begin(), palabra.end(), ::isdigit)) {
            suma += stoi(palabra);
        }
    }

    if(suma == 0){
        cout << "No se encontró ningún número en la oración. " << endl;
        return 0;
    }

    int r = suma % 5;
    int n = r + 1;

    istringstream iss2(oracion);
    while (iss2 >> palabra) {        
        int contadorVocales = 0;
        set<char> vocales;
        for (char c : palabra) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vocales.insert(lower);
            }
        }
        if (vocales.size() == n) {
            //cout << "Palabra: " << palabra << endl;
            contadorPalabras++;
        }
    }

    cout << "Hay " << contadorPalabras << " palabras con " << n << " vocales diferentes" << endl;
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