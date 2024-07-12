#include <iostream>
#include <vector>

using namespace std;

class Polinomio {
private:
    vector<int> coeficientes;

public:
    Polinomio(vector<int> coefs) : coeficientes(coefs) {
    }

    void mostrarCoeficientes() const {
        cout << "Coeficientes: ";
        for (int coef: coeficientes) {
            cout << coef << " ";
        }
        cout << endl;
    }

    Polinomio multiplicar(const Polinomio &otro) const {
        int gradoResultado = coeficientes.size() + otro.coeficientes.size() - 1;
        vector<int> resultado(gradoResultado, 0);

        for (int i = 0; i < coeficientes.size(); i++) {
            for (int j = 0; j < otro.coeficientes.size(); j++) {
                resultado[i + j] += coeficientes[i] * otro.coeficientes[j];
            }
        }

        return Polinomio(resultado);
    }
};

int main() {
    Polinomio P({3, -4, 0, 1});
    cout << "P(x): ";
    P.mostrarCoeficientes();

    Polinomio Q({-2, 1, 0});
    cout << "Q(x): ";
    Q.mostrarCoeficientes();

    Polinomio Producto = P.multiplicar(Q);
    cout << "P(x)Q(x): ";
    Producto.mostrarCoeficientes();

    return 0;
}
