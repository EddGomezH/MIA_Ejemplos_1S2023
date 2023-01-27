#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int retVal;
    FILE *file;
    char cont[51] = "Ejemplo 1, Sobreescritura de Archivos con fwrite.\n";

    file = fopen("ejemplo1_3.txt","a+");
    retVal = fwrite(&cont,sizeof(cont),1,file);
    
    cout << "fwrite returned " << retVal;
    return 0;
}