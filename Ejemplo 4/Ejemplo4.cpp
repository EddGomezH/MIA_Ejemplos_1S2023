#include "analizador.cpp"

int main(){
    Analizador analisis;
    // Ejemplos de comandos reconocidos
    // crear >tamano=10 >dimensional="m" // Crea archivo binario con los parametros especificados.
    // escribir >id=1 >nombre="abc" >telefono=123 >direccion="def" >x=5 // Escribe en archivo binario un struct con los datos especificados la cantidad de veces que fue definido.
    // vertodo // Muestra todos los registros registrados en el archivo binario.
    // verx >x=5 // Muestra el registro en la posicion X del archivo binario.
    // eliminarx >x=3 // Elimina el registro en la posicion X del archivo binario.
    string entradacmd = "";
    while(entradacmd != "exit"){
        cout << "*----------------------------------------------------------*" << endl;
        cout << "*                      [MIA] Ejemplo 4                     *" << endl;
        cout << "*----------------------------------------------------------*" << endl;
        cout << "[MIA]@Ejemplo4:~$ ";
        getline(cin,entradacmd);
        analisis.analizar(entradacmd);
    }
    return 0;
}