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
    getline(cin, entrada);

    string salida = eliminarLetrasRepetidas(entrada);

    cout << salida << endl;

    return 0;
}