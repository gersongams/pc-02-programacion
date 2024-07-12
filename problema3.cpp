#include <iostream>
#include <string>
#include <vector>

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
    vector<int> conteo_a(10, 0), conteo_b(10, 0);
    string resultado;

    for (char c : a) conteo_a[c - '0']++;
    for (int i = 0; i < 10; i++) {
        resultado.append(conteo_a[i], '0' + i);
    }

    for (char c : b) {
        int digit = c - '0';
        if (conteo_a[digit] == 0) {
            resultado += c;
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

    cout << "Ingrese los números separados por espacios: ";
    cin >> a >> b >> c;


    if (!validarEntrada(a, 4) || !validarEntrada(b, 4) || !validarEntrada(c, 1) || c.length() > 1) {
        cout << "Entrada inválida." << endl;
        return 1;
    }

    string mezclado = mezclarNumeros(a, b);
    string resultado = eliminarDigito(mezclado, c[0]);

    cout << "Se ingresan los números " << a << " " << b << " " << c << endl;
    cout << "El numero mezclado sera: " << mezclado << endl;
    cout << "El numero resultante sera: " << resultado << endl;

    return 0;
}