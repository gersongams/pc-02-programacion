#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

bool esDoblete(const string &palabra1, const string &palabra2) {
    if (palabra1.length() != palabra2.length()) return false;
    int diferencias = 0;
    for (size_t i = 0; i < palabra1.length(); ++i) {
        if (palabra1[i] != palabra2[i]) diferencias++;
        if (diferencias > 1) return false;
    }
    return diferencias == 1;
}

vector<string> encontrarSecuenciaDoblete(const string &inicio, const string &fin, const vector<string> &diccionario) {
    queue<vector<string> > cola;
    unordered_set<string> visitadas;

    cola.push({inicio});
    visitadas.insert(inicio);

    while (!cola.empty()) {
        vector<string> camino = cola.front();
        cola.pop();

        string actual = camino.back();

        if (actual == fin) {
            return camino;
        }

        for (const string &palabra: diccionario) {
            if (!visitadas.count(palabra) && esDoblete(actual, palabra)) {
                vector<string> nuevoCamino = camino;
                nuevoCamino.push_back(palabra);
                cola.push(nuevoCamino);
                visitadas.insert(palabra);
            }
        }
    }

    return {};
}

int main() {
    vector<string> diccionario;
    string palabra;

    while (true) {
        getline(cin, palabra);
        if (palabra.empty()) break;
        diccionario.push_back(palabra);
    }

    string inicio, fin;
    while (cin >> inicio >> fin) {
        vector<string> secuencia = encontrarSecuenciaDoblete(inicio, fin, diccionario);

        if (secuencia.empty()) {
            cout << "No solution." << endl;
        } else {
            for (const string &p: secuencia) {
                cout << p << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
