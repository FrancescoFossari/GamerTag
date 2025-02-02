#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Lettura(string nome){
    fstream file("file.txt");
    if(!file.is_open()){
        cerr<<"Errore file INPUT.txt..."<<endl;
        file.close();
    }
    
    vector<string> aggettivi;
    string aggettivo;
    
    while(file>>aggettivo){
        aggettivi.push_back(aggettivo);
    }
    
    if (aggettivi.empty()) {
        cout << "Errore: Nessun aggettivo trovato nel file." << endl;
        file.close();
        return;
    }
    
    srand(time(0));
    
    int indiceCasuale = rand() % aggettivi.size();
    cout << "Nome Generato: - " << nome << aggettivi[indiceCasuale] <<" - "<<endl;
    
    file.close();
}


int main(){

    cout<<"\t Generatore casuale di GamerTag..."<<endl<<endl;
    
    string tag;
    cout<<"Inserisci un Nome per generare un GamerTag casuale :"<<endl;
    cin>>tag;
    
    Lettura(tag);
    
    return 0;
}
