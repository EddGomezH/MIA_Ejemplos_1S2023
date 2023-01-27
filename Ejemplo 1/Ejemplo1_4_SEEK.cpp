
#include <stdio.h>
#include <iostream>
#include <cstring>  

using namespace std;

int main()
{
    FILE *file;
    file = fopen("ejemplo1_4.txt", "r");
    char cont[16];
      
    fseek(file, 0, SEEK_SET);   // Desde el inicio hasta donde el indice indicado.
    //fseek(file, -10, SEEK_END);  // Desde el final hasta donde el indice indicado (Indices negativos).
    fseek(file, 12, SEEK_CUR);   // Desde la posicion actual del punto, avanza las nuevas posiciones indicadas.
    fseek(file, 15, SEEK_CUR);
    fseek(file, -2, SEEK_CUR);

    cout << "Puntero:   " << ftell(file) << endl;
    
    fread(&cont,15,1, file);

    for(int i = 0; i < strlen(cont); i++){
		cout << cont[i];     
	}
  
    return 0;
}