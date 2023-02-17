#include "analizador.cpp"
#include <string>

using namespace std;
static Analizador analizador;

int main(int argc, char *argv[])
{
    string Entrada = "";
    string ContEntrada = "";
    while(!(Entrada.compare("Exit") == 0)){
        cout << "[MIA]@Ejemplo3:~$ ";
        getline(cin,Entrada);
        ContEntrada = Entrada.c_str();
        analizador.LeerEntrada(ContEntrada);
        analizador.Analizar();
    }
    return 0;
}