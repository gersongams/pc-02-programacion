#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> encontrarProgresionAritmetica(const vector<int>& X, unordered_set<int>& usados) {
    int n = X.size();
    vector<int> mejor_progresion;

    for (int i = 0; i < n; i++) {
        if (usados.find(X[i]) != usados.end()) continue;
        for (int j = i + 1; j < n; j++) {
            if (usados.find(X[j]) != usados.end()) continue;
            int diferencia = X[j] - X[i];
            vector<int> progresion = {X[i], X[j]};
            int siguiente = X[j] + diferencia;

            for (int k = 0; k < n; k++) {
                if (k != i && k != j && X[k] == siguiente && usados.find(X[k]) == usados.end()) {
                    progresion.push_back(X[k]);
                    siguiente += diferencia;
                }
            }

            if (progresion.size() > mejor_progresion.size()) {
                mejor_progresion = progresion;
            }
        }
    }

    for (int num : mejor_progresion) {
        usados.insert(num);
    }

    return mejor_progresion;
}

vector<int> encontrarProgresionGeometrica(const vector<int>& X, unordered_set<int>& usados) {
    int n = X.size();
    vector<int> mejor_progresion;

    for (int i = 0; i < n; i++) {
        if (usados.find(X[i]) != usados.end()) continue;
        for (int j = i + 1; j < n; j++) {
            if (usados.find(X[j]) != usados.end()) continue;
            if (X[i] != 0 && X[j] % X[i] == 0) {
                int razon = X[j] / X[i];
                vector<int> progresion = {X[i], X[j]};
                int siguiente = X[j] * razon;

                for (int k = 0; k < n; k++) {
                    if (k != i && k != j && X[k] == siguiente && usados.find(X[k]) == usados.end()) {
                        progresion.push_back(X[k]);
                        siguiente *= razon;
                    }
                }

                if (progresion.size() > mejor_progresion.size()) {
                    mejor_progresion = progresion;
                }
            }
        }
    }

    if (mejor_progresion.empty()) {
        for (int i = 0; i < n; i++) {
            if (usados.find(X[i]) == usados.end()) {
                mejor_progresion.push_back(X[i]);
                break;
            }
        }
    }

    for (int num : mejor_progresion) {
        usados.insert(num);
    }

    return mejor_progresion;
}

void imprimirProgresiones(const vector<int>& X, int n) {
    unordered_set<int> usados;
    vector<int> progresion_aritmetica = encontrarProgresionAritmetica(X, usados);

    unordered_set<int> usados_temp = usados;
    vector<int> progresion_geometrica = encontrarProgresionGeometrica(X, usados_temp);

    int longitud_combinada = progresion_aritmetica.size() + progresion_geometrica.size();

    for (int i = 0; i < n; i++) {
        if (usados.find(X[i]) == usados.end()) {
            unordered_set<int> usados_temp2 = usados;
            vector<int> progresion_temp = encontrarProgresionAritmetica(X, usados_temp2);
            vector<int> progresion_geometrica_temp = encontrarProgresionGeometrica(X, usados_temp2);
            int longitud_combinada_temp = progresion_temp.size() + progresion_geometrica_temp.size();

            if (longitud_combinada_temp > longitud_combinada) {
                progresion_aritmetica = progresion_temp;
                progresion_geometrica = progresion_geometrica_temp;
                longitud_combinada = longitud_combinada_temp;
            }
        }
    }

    cout << "A: ";
    for (int num : progresion_aritmetica) {
        cout << num << " ";
    }
    cout << "- G: ";
    for (int num : progresion_geometrica) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> casos_prueba = {
        {1, 10, 9, 5, 7, 13, 100},
        {5, 5, 5, 5, 5, 1},
        {0, 10, 3, 8, 9, 6},
        {100}
    };

    for (const auto& X : casos_prueba) {
        imprimirProgresiones(X, X.size());
    }

    return 0;
}
