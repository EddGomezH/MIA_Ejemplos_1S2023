#include "analizador.cpp"

int main(){
    Analizador analisis;
    string entradacmd = "";
    while(entradacmd != "exit"){
        cout << "*----------------------------------------------------------*" << endl;
        cout << "*                      [MIA] Ejemplo 6                     *" << endl;
        cout << "*----------------------------------------------------------*" << endl;
        cout << "[MIA]@Ejemplo6:~$ ";
        getline(cin,entradacmd);
        analisis.analizar(entradacmd);
    }
    return 0;
}