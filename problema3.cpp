#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool validarEntrada(const string& num, int minDigitos = 1) {
    if (num.empty() || num[0] == '0') {
        return false;
    }
    if (num.length() < minDigitos) {
        return false;
    }
    for (char c : num) {
        if (!isdigit(c)) return false;
    }
    return true;
}

string mezclarNumeros(const string& a, const string& b) {
    string resultado = a;
    for (char digit : b) {
        if (a.find(digit) == std::string::npos) {
            resultado += digit;
        }
    }
    sort(resultado.begin(), resultado.end());
    return resultado;
}

string eliminarDigito(const string& numero, char digito) {
    string resultado;
    for (char c : numero) {
        if (c != digito) resultado += c;
    }
    return resultado;
}

int main() {
    string a, b, c;
    std::cout << "Ingrese el primer numero (a): ";
    std::cin >> a;
    std::cout << "Ingrese el segundo numero (b): ";
    std::cin >> b;
    std::cout << "Ingrese un numero entero positivo de una sola cifra (c): ";
    std::cin >> c;

    if (!validarEntrada(a, 4) || !validarEntrada(b, 4)) {
        cout << "Numero no valido: (a) y (b) deben ser numeros enteros positivos de 4 o mas cifras." << endl;
        return 1;
    }

    if (!validarEntrada(c, 1) || c.length() > 1) {
        cout << "Numero no valido: (c) debe ser un numero entero positivo de una sola cifra." << endl;
        return 1;
    }

    string mezclado = mezclarNumeros(a, b);
    string resultado = eliminarDigito(mezclado, c[0]);
    cout << " " << endl;
    cout << "Se ingresan los numeros: " << a << ", " << b << " y " << c << endl;
    cout << "El numero mezclado sera: " << mezclado << endl;
    cout << "El numero resultante sera: " << resultado << endl;

    return 0;
}