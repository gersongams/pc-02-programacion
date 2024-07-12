#include <iostream>
#include <vector>

using namespace std;

struct Imagen {
    vector<vector<int>> pixels;
    int filas, columnas;

    Imagen(int f, int c) : filas(f), columnas(c), pixels(f, vector<int>(c)) {}
};

bool esSubimagen(const Imagen& original, int subFilas, int subColumnas) {
    for (int i = 0; i < original.filas; i += subFilas) {
        for (int j = 0; j < original.columnas; j += subColumnas) {
            for (int x = 0; x < subFilas; x++) {
                for (int y = 0; y < subColumnas; y++) {
                    if (original.pixels[i + x][j + y] != original.pixels[x][y]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

Imagen descomponerMosaico(Imagen x) {
    for (int subFilas = 1; subFilas <= x.filas; subFilas++) {
        if (x.filas % subFilas != 0) {
            continue;
        }
        for (int subColumnas = 1; subColumnas <= x.columnas; subColumnas++) {
            if (x.columnas % subColumnas != 0) {
                continue;
            }
            if (esSubimagen(x, subFilas, subColumnas)) {
                Imagen subimagen(subFilas, subColumnas);
                for (int i = 0; i < subFilas; i++) {
                    for (int j = 0; j < subColumnas; j++) {
                        subimagen.pixels[i][j] = x.pixels[i][j];
                    }
                }
                return subimagen;
            }
        }
    }
    return x;
}

void imprimirImagen(const Imagen& img) {
    for (int i = 0; i < img.filas; i++) {
        for (int j = 0; j < img.columnas; j++) {
            cout << img.pixels[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Imagen original(6, 9);
    vector<vector<int>> valores = {
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {120, 255, 120, 120, 255, 120, 120, 255, 120},
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {0, 120, 0, 0, 120, 0, 0, 120, 0},
        {120, 255, 120, 120, 255, 120, 120, 255, 120},
        {0, 120, 0, 0, 120, 0, 0, 120, 0}
    };
    original.pixels = valores;

    cout << "original:" << endl;
    imprimirImagen(original);

    Imagen resultado = descomponerMosaico(original);

    cout << "\n" << endl;

    cout << "subimagen:" << endl;
    imprimirImagen(resultado);

    return 0;
}
