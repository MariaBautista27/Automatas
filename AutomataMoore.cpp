#include <iostream>
#include <string>
using namespace std;

class AutomataMoore {
private:
    enum Estado { S0, S1, S2 };  // Definimos los estados
    Estado estado_actual;

public:
    AutomataMoore() {
        estado_actual = S0;  // Inicializamos en el estado S0
    }

    string procesar(const string& entrada) {
        string salida = "";

        for (char bit : entrada) {
            switch (estado_actual) {
                case S0:
                    if (bit == '1') {
                        estado_actual = S1;
                    }
                    salida += bit;
                    break;

                case S1:
                    if (bit == '1') {
                        estado_actual = S2;
                        salida.pop_back();  // Eliminamos el último '1'
                        salida += "00";     // Sustituimos por "00"
                    } else {
                        estado_actual = S0;
                        salida += bit;
                    }
                    break;

                case S2:
                    estado_actual = S0;  // Siempre volvemos al estado inicial
                    salida += bit;       // Continuamos con el flujo normal
                    break;
            }
        }
        return salida;
    }
};

int main() {
    string entrada;
    cout << "Introduce la secuencia binaria: ";
    cin >> entrada;

    AutomataMoore automata;
    string salida = automata.procesar(entrada);

    cout << "Salida: " << salida << endl;
    return 0;
}
