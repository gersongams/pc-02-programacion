#include <iostream>
#include <string>

using namespace std;

string eliminarLetrasRepetidas(string texto) {
    string resultado = "";
    int longitud = texto.length();

    for (int i = 0; i < longitud; i++) {
        if (resultado.empty() || resultado.back() != texto[i]) {
            resultado.push_back(texto[i]);
        } else {
            resultado.pop_back();
        }
    }

    return resultado;
}

int main() {
    string entrada;
    cout << "input: ";
    getline(cin, entrada);

    // Valida la longitud del texto de entrada
    if (entrada.length() >= 1 && entrada.length() <= 2e5) {
        string salida = eliminarLetrasRepetidas(entrada);
        cout << "salida: " << salida << endl;
    } else {
        std::cout << "Longitud de entrada no válida. Por favor, ingresa un texto con una longitud entre 1 a 2 x 10^5." << std::endl;
    }
    return 0;
}
