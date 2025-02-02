#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funzione per colorare il testo (ANSI escape codes)
void setColor(const string& color) {
    if (color == "red") {
        cout << "\033[1;31m";  // Rosso
    } else if (color == "green") {
        cout << "\033[1;32m";  // Verde
    } else if (color == "yellow") {
        cout << "\033[1;33m";  // Giallo
    } else {
        cout << "\033[0m";  // Ripristina il colore originale
    }
}

void Lettura(string nome) {
    fstream file("file.txt");
    
    if (!file.is_open()) {
        setColor("red");
        cerr << "Errore nell'aprire il file 'file.txt'..." << endl;
        setColor("reset");
        return;
    }

    vector<string> aggettivi;
    string aggettivo;

    // Leggi gli aggettivi dal file
    while (file >> aggettivo) {
        aggettivi.push_back(aggettivo);
    }

    if (aggettivi.empty()) {
        setColor("yellow");
        cout << "Errore: Nessun aggettivo trovato nel file." << endl;
        setColor("reset");
        file.close();
        return;
    }

    srand(time(0));
    int indiceCasuale = rand() % aggettivi.size();

    // Stampa il risultato con un bordo decorativo
    setColor("green");
    cout << "\n=====================================" << endl;
    cout << "  Nome Generato:  " << nome << aggettivi[indiceCasuale] << "  " << endl;
    cout << "=====================================" << endl;
    setColor("reset");

    file.close();
}

int main() {
    cout << "\n\t  Generatore casuale di GamerTag..." << endl;
    cout << "=========================================" << endl;
    
    string tag;
    cout << "Inserisci un Nome per generare un GamerTag casuale: ";
    cin >> tag;
    
    cout << "\nElaborazione in corso..." << endl;

    // Chiamata alla funzione che esegue la generazione del GamerTag
    Lettura(tag);
    
    return 0;
}
