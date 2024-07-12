#include <iostream>
#include <string>

using namespace std;

struct Espia {
    string nombre;
    Espia* siguiente;
    Espia(string _nombre) : nombre(_nombre), siguiente(nullptr) {}
};

int numeroEspias(Espia* espiaInicial) {
    if (!espiaInicial) return 0;
    int contador = 1;
    Espia* actual = espiaInicial->siguiente;
    while (actual != espiaInicial) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

Espia* avanzar(Espia* espiaInicial, int X) {
    Espia* actual = espiaInicial;
    for (int i = 0; i < X - 1; i++) {
        actual = actual->siguiente;
    }
    return actual;
}

Espia* ultimoSobreviviente(Espia* espiaInicial, int K) {
    if (!espiaInicial) return nullptr;

    Espia* actual = espiaInicial;
    int numEspias = numeroEspias(espiaInicial);

    while (numeroEspias(actual) > 1) {
        cout << "Inicia: " << actual->nombre << endl;
        Espia* aEliminar = avanzar(actual, K);
        Espia* previo = actual;
        do {
            previo = previo->siguiente;
        } while (previo->siguiente != aEliminar);
        cout << "Eliminando a " << aEliminar->nombre << endl;
        actual = aEliminar->siguiente;
        previo->siguiente = actual;
        delete aEliminar;
        numEspias--;
    }

    return actual;
}

int main() {
    Espia* pDiego = new Espia("Diego");
    Espia* pPamela = new Espia("Pamela");
    Espia* pRafael = new Espia("Rafael");
    Espia* pPaulo = new Espia("Paulo");
    Espia* pSamir = new Espia("Samir");

    pDiego->siguiente = pPamela;
    pPamela->siguiente = pRafael;
    pRafael->siguiente = pPaulo;
    pPaulo->siguiente = pSamir;
    pSamir->siguiente = pDiego;

    int K = 3;

    cout << "Número de espías: " << numeroEspias(pDiego) << endl;

    Espia* sobreviviente = ultimoSobreviviente(pDiego, K);
    cout << "El último espía en sobrevivir es: " << sobreviviente->nombre << endl;

    delete sobreviviente;

    return 0;
}