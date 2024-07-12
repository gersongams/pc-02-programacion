#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int hexADecimal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return 10 + (toupper(c) - 'A');
}

char decimalAHex(int n) {
    if (n < 10) return '0' + n;
    return 'A' + (n - 10);
}

string sumaHexadecimal(string num1, string num2) {
    string resultado = "";
    int acarreo = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || acarreo) {
        int suma = acarreo;
        if (i >= 0) suma += hexADecimal(num1[i--]);
        if (j >= 0) suma += hexADecimal(num2[j--]);
        resultado = decimalAHex(suma % 16) + resultado;
        acarreo = suma / 16;
    }

    return resultado;
}

int main() {
    string num1 = "AB10F";
    string num2 = "FF041F";

    cout << "Primer número: " << num1 << endl;
    cout << "Segundo número: " << num2 << endl;

    string suma = sumaHexadecimal(num1, num2);
    cout << "Suma: " << suma << endl;

    return 0;
}