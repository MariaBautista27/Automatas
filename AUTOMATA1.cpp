#include <iostream>
#include <string>

using namespace std;

// Define los estados del autómata
enum State { q0, q1, q2 };

// Función para verificar si la palabra solo contiene 'a' y 'b'
bool isValid(const string& word) {
    for (char c : word) {
        if (c != 'a' && c != 'b') return false;
    }
    return true;
}

// Función para procesar la palabra con el autómata
bool processWord(const string& word, State& finalState) {
    State currentState = q0;
    
    for (char c : word) {
        switch (currentState) {
            case q0:
                if (c == 'a') currentState = q1;
                else if (c == 'b') currentState = q2;
                break;
            case q1:
                if (c == 'a') continue;
                else if (c == 'b') currentState = q2;
                break;
            case q2:
                if (c == 'a') currentState = q0;
                else if (c == 'b') continue;
                break;
        }
    }

    finalState = currentState;
    return currentState == q2; // Asumimos q2 como estado de aceptación
}

int main() {
    string word;
    int option;
    
    do {
        cout << "ESCRIBE UNA PALABRA SOLO CON 'a' y 'b': ";
        cin >> word;
        
        if (!isValid(word)) {
            cout << "ERROR: LA PALABRA DEBE CONTENER SOLO CARACTERES 'a' y 'b'.\n";
        } else {
            State finalState;
            bool isAccepted = processWord(word, finalState);

            if (isAccepted)
                cout << "PALABRA ACEPTADA:). TERMINO EN EL ESTADO q2, QUE ES UN ESTADO DE ACEPTACION :) .\n";
            else
                cout << "PALABRA NO ACEPTADA. TERMINO EN EL ESTADO " << finalState << ", QUE NO ES UN ESTADO DE ACEPTACION :( ).\n";
        }

        cout << "¿Deseas ingresar otra palabra? (1 para SI, 2 para NO): ";
        cin >> option;
    } while (option == 1);

    cout << "GRACIAS, HASTA LUEGO :).\n";

    return 0;
}
