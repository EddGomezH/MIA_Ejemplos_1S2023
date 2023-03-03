#include "comando.h"

void Comando::identificacionCMD(Parametros p){
    if(p.Comando=="crear"){ // Se identifica el tipo de comando
        if(p.Tamano != " " && p.Dimensional != " "){ // Se validan los parametros para el comando
            crearArchivo(p.Tamano,p.Dimensional);
        }else{
            cout << "Error creando Disco: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="escribir"){ // Se identifica el tipo de comando
        if(p.Id != " " && p.Nombre != " " && p.Telefono != " " && p.Direccion != " " && p.X != " "){ // Se validan los parametros para el comando
            escribir(p.Id,p.Nombre,p.Telefono,p.Direccion,p.X);
        }else{
            cout << "Error escribiendo en Disco: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="vertodo"){ // Se identifica el tipo de comando
        vertodo();
    }else if(p.Comando=="verx"){ // Se identifica el tipo de comando
        if(p.X != " "){ // Se validan los parametros para el comando
            verX(p.X);
        }else{
            cout << "Error visualizando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="eliminarx"){ // Se identifica el tipo de comando
        if(p.X != " "){ // Se validan los parametros para el comando
            eliminarX(p.X);
        }else{
            cout << "Error elinando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="editarx"){ // Se identifica el tipo de comando
        if(p.X != " "){ // Se validan los parametros para el comando
            editarX(p.X);
        }else{
            cout << "Error editando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="graphall"){ // Se identifica el tipo de comando
        graph_ALL();
    }else if(p.Comando=="graphx"){ // Se identifica el tipo de comando
        if(p.X != " "){ // Se validan los parametros para el comando
            graph_X(p.X);
        }else{
            cout << "Error Graficando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="graphdisk"){ // Se identifica el tipo de comando
        graph_TableHTML();
    }else if(p.Comando=="graphtree"){ // Se identifica el tipo de comando
        graph_Tree();
    }
}

void Comando::crearArchivo(string tam, string dim){
    // Calculo Tamaño del Archivo
    int size_file = 0, tamano = atoi(tam.c_str());
    char dimen = dim.at(0);
    if (dimen == 'k' || dimen == 'K')
    {
        size_file = tamano;
    }
    else if (dimen == 'm' || dimen == 'M')
    {
        size_file = tamano * 1024;
    }
    else if (dimen == 'g' || dimen == 'G')
    {
        size_file = tamano * 1024 * 1024;
    }

    // Preparacion Bloque
    char bloque[1024];
    for (int i = 0; i < 1024; i++)
    {
        bloque[i] = '\0';
    }

    // Escritura de Bloque en Archivo
    int limite = 0;
    FILE *archivo_binario;
    archivo_binario = fopen("Ejemplo6.dsk", "w");
    while (limite != size_file)
    {
        fwrite(&bloque, 1024, 1, archivo_binario);
        limite++;
    }
    fclose(archivo_binario);
}

void Comando::escribir(string id, string nombre, string tel, string dir, string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    string nm = "", direc = "";
    int registros = atoi(x.c_str());

    archivo_binario = fopen("Ejemplo6.dsk", "rb+");
    for (int i = 0; i < registros; i++){
        // Seteo de parametros en Struct
        ejm.id = i + atoi(id.c_str());
        nm = nombre;
        nm += " " + to_string(ejm.id);
        strcpy(ejm.nombre, nm.c_str());
        ejm.telefono = (rand() + i) + atoi(tel.c_str());
        direc = dir;
        direc += " " + to_string(ejm.id);
        strcpy(ejm.direccion, direc.c_str());
        // Movimiento de puntero y escritura de Struct en archivo binario 
        fseek(archivo_binario, i * sizeof(Ejemplo), SEEK_SET);
        fwrite(&ejm, sizeof(ejm), 1, archivo_binario);
        nm = "";
        direc = "";
    }
    fclose(archivo_binario);
}

void Comando::vertodo(){
    FILE *archivo_binario;
    Ejemplo ejm;
    int cont = 0;
    archivo_binario = fopen("Ejemplo6.dsk", "rb+");
    while (!feof(archivo_binario)){
        // Movimiento de puntero y lectura de Struct en archivo binario 
        fseek(archivo_binario,cont*sizeof(Ejemplo), SEEK_SET);
        fread(&ejm, sizeof(ejm), 1, archivo_binario);
        mostrar_struct(ejm);
        cont++;
    }
    cont = 0;
    fclose(archivo_binario);
}

void Comando::verX(string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    int xreg = atoi(x.c_str()) - 1;
    archivo_binario = fopen("Ejemplo6.dsk", "rb+");
    // Movimiento de puntero y lectura de Struct en archivo binario 
    fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
    fread(&ejm, sizeof(ejm), 1, archivo_binario);
    mostrar_struct(ejm);
    fclose(archivo_binario);
}

void Comando::eliminarX(string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    ejm.id = 0;
    strcpy(ejm.nombre, " ");
    ejm.telefono = 0;
    strcpy(ejm.direccion, " ");
    int xreg = atoi(x.c_str()) - 1;
    archivo_binario = fopen("Ejemplo6.dsk", "rb+");
    // Movimiento de puntero y escritura de Struct en archivo binario
    fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
    fwrite(&ejm, sizeof(ejm), 1, archivo_binario);
    mostrar_struct(ejm);
    fclose(archivo_binario);
}

void Comando::editarX(string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    int xreg = atoi(x.c_str()) - 1;
    archivo_binario = fopen("Ejemplo6.dsk", "rb+");
    // Movimiento de puntero y lectura de Struct en archivo binario
    fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
    fread(&ejm, sizeof(ejm), 1, archivo_binario);
    mostrar_struct(ejm);
    // Edicion del Struct y escritura en archivo binario
    string nameedit = ejm.nombre;
    nameedit += " edit";
    strcpy(ejm.nombre, nameedit.c_str());
    string diredit = ejm.direccion;
    diredit += " edit"; 
    strcpy(ejm.direccion, diredit.c_str());
    mostrar_struct(ejm);
    fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
    fwrite(&ejm, sizeof(ejm), 1, archivo_binario);
    fclose(archivo_binario);
}

void Comando::mostrar_struct(Ejemplo ejm){
    if(ejm.id > 0 && ejm.nombre != "" && ejm.telefono > 0 && ejm.direccion != ""){
        cout << "ID: ";
        cout << ejm.id;
        cout << ", Nombre: ";
        cout << ejm.nombre;
        cout << ", Telefono: ";
        cout << ejm.telefono;
        cout << ", Direccion: ";
        cout << ejm.direccion << endl;
    }
}

void Comando::graph_ALL(){
    Ejemplo ejm, aux;
    ofstream all;
        int cont = 0, cont2 = 0;
        FILE *archivo_binario;
        archivo_binario = fopen("Ejemplo6.dsk", "rb+");
        string cmd = "dot -Tjpg Ejemplo6_ALL.dot -o Ejemplo6_ALL.jpg";
        all.open("Ejemplo6_ALL.dot");
        all << "digraph Ejemplo6_ALL {\n";
        all << "rankdir = \"LR\"\n";
        all << "edge [arrowhead=vee style=dashed]\n";
        do{
            fseek(archivo_binario, cont * sizeof(Ejemplo), SEEK_SET);
            fread(&ejm, sizeof(ejm), 1, archivo_binario);
            if (ejm.id > 0){
                all << "node";
                all << ejm.id-1;
                all << "[ label = \"<f0>" + to_string(ejm.id) + " | ";
                all << "<f1>";
                all << ejm.nombre;
                all << " | ";
                all << "<f2>";
                all << ejm.telefono;
                all << " | ";
                all << "<f3>";
                all << ejm.direccion;
                all << "\" shape = \"record\" style=filled fillcolor=\"cadetblue1\"];\n";
                fseek(archivo_binario, (cont + 1) * sizeof(Ejemplo), SEEK_SET);
                fread(&aux, sizeof(aux), 1, archivo_binario);
                if(aux.id > 0){
                    all << "node";
                    all <<  ejm.id - 1;
                    all << ":f0 -> node";
                    all << aux.id - 1;
                    all << ":f0\n";
                }
            }
            cont++;
        } while (!feof(archivo_binario));
        cont = 0;
        all << "}\n";
        all.close();
        fclose(archivo_binario);
        system(cmd.c_str());
        system("fim -a Ejemplo6_ALL.jpg");
}

void Comando::graph_X(string x){
        FILE *archivo_binario;
        Ejemplo ejm;
        int xreg = atoi(x.c_str()) - 1;
        archivo_binario = fopen("Ejemplo6.dsk", "rb+");
        // Movimiento de puntero y lectura de Struct en archivo binario
        fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
        fread(&ejm, sizeof(ejm), 1, archivo_binario);
        ofstream registrox;
        string cmd = "dot -Tjpg Ejemplo6_X.dot -o Ejemplo6_X.jpg";
        registrox.open("Ejemplo6_X.dot");
        registrox << "digraph Ejemplo6_X {\n";
        registrox << "node[shape=plaintext];\n";
        registrox << "T[label=<\n<table border=\"1\" cellborder =\"1\">\n";
        registrox << "<tr><td bgcolor=\"yellow\">Ejemplo6_X</td></tr>\n";
        registrox << "<tr><td bgcolor=\"aquamarine\">Atributo</td><td bgcolor=\"darkseagreen3\">Valor</td></tr>\n";
        registrox << "<tr><td bgcolor=\"aquamarine\">id</td><td bgcolor=\"darkseagreen3\">";
        registrox << ejm.id;
        registrox << "</td></tr>\n";
        registrox << "<tr><td bgcolor=\"aquamarine\">nombre</td><td bgcolor=\"darkseagreen3\">";
        registrox << ejm.nombre;
        registrox << "</td></tr>\n";
        registrox << "<tr><td bgcolor=\"aquamarine\">telefono</td><td bgcolor=\"darkseagreen3\">";
        registrox << ejm.telefono;
        registrox << "</td></tr>\n";
        registrox << "<tr><td bgcolor=\"aquamarine\">direccion</td><td bgcolor=\"darkseagreen3\">";
        registrox << ejm.direccion;
        registrox << "</td></tr>\n";
        registrox << "</table>>];\n";
        registrox << "}\n";
        registrox.close();
        system(cmd.c_str());
        system("fim -a Ejemplo6_X.jpg");
}

void Comando::graph_TableHTML(){
    string disk = "digraph Disk {\n";
    disk += "node [shape=box fontname=Helvetica]\n";
    disk += "table [label=<\n";
    disk += "<table border=\"0\">\n";
    disk += "<tr>\n";
    disk += "<td border=\"1\" bgcolor=\"brown1\">\n";
    disk += "<table border=\"0\">\n";
    disk += "<tr>\n";
    disk += "<td border=\"0\">MBR</td>\n";
    disk += "</tr>\n";
    disk += "<tr>\n";
    disk += "<td border=\"0\">0%</td>\n";
    disk += "</tr>\n";
    disk += "</table>\n";
    disk += "</td>\n";
    disk += "<td border=\"1\" bgcolor=\"cadetblue1\">Particion 1</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkolivegreen4\">\n";
    disk += "<table border=\"0\">\n";
    disk += "<tr>\n";
    disk += "<td border=\"1\" bgcolor=\"darkolivegreen1\">EBR</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkgoldenrod1\">Logica 1</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkolivegreen1\">EBR</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkgoldenrod1\">Logica 2</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkolivegreen1\">EBR</td>\n";
    disk += "<td border=\"1\" bgcolor=\"darkgoldenrod1\">Logica 3</td>\n";
    disk += "</tr>\n";
    disk += "</table>\n";
    disk += "</td>\n";
    disk += "<td border=\"1\" bgcolor=\"cadetblue1\">Particion 3</td>\n";
    disk += "<td border=\"1\" bgcolor=\"cadetblue1\">Particion 4</td>\n";
    disk += "</tr>\n";
    disk += "</table>\n";
    disk += ">]\n";
    disk += "}\n";
    ofstream table_disk;
    string cmd = "dot -Tjpg Ejemplo6_Disk.dot -o Ejemplo6_Disk.jpg";
    table_disk.open("Ejemplo6_Disk.dot");
    table_disk << disk;
    table_disk.close();
    system(cmd.c_str());
    system("fim -a Ejemplo6_Disk.jpg");
}

void Comando::graph_Tree(){
    string tree = "digraph Tree {\n";
    tree += "rankdir = \"LR\"\n";
    tree += "\"node0\" [label=\"<f0>Inodo 0|<f1>i_type: 0|<f2>Ap0: Bloq0|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node1\" [label=\"<f0>B. Carpeta 0|<f1>Users.txt: Ino1|<f2>home: Ino2|<f3>. : -1|<f4>. : -1\" shape=\"record\" style=filled fillcolor=\"darkolivegreen1\"];\n";
    tree += "\"node2\" [label=\"<f0>Inodo 1|<f1>i_type: 1|<f2>Ap0: Bloq1|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node3\" [label=\"<f0>B. Archivo 1|<f1>1, G, root\n1, U, root, root, 123\n\" shape=\"record\" style=filled fillcolor=\"gold\"];\n";
    tree += "\"node4\" [label=\"<f0>Inodo 2|<f1>i_type: 0|<f2>Ap0: Bloq2|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node5\" [label=\"<f0>B. Carpeta 2|<f1>archivos: Ino3|<f2>b.txt: Ino5|<f3>. : -1|<f4>. : -1\" shape=\"record\" style=filled fillcolor=\"darkolivegreen1\"];\n";
    tree += "\"node6\" [label=\"<f0>Inodo 3|<f1>i_type: 0|<f2>Ap0: Bloq3|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node7\" [label=\"<f0>B. Carpeta 3|<f1>a.txt: Ino4|<f2>. : -1|<f3>. : -1|<f4>. : -1\" shape=\"record\" style=filled fillcolor=\"darkolivegreen1\"];\n";
    tree += "\"node8\" [label=\"<f0>Inodo 4|<f1>i_type: 1|<f2>Ap0: Bloq4|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node9\" [label=\"<f0>B. Archivo 4|<f1>0123456789012345\" shape=\"record\" style=filled fillcolor=\"gold\"];\n";
    tree += "\"node10\" [label=\"<f0>Inodo 5|<f1>i_type: 1|<f2>Ap0: Bloq5|<f3>Ap1: -1|<f3>Ap3: -1|<f4>...|<f5>Ap15: -1\" shape=\"record\" style=filled fillcolor=\"cadetblue1\"];\n";
    tree += "\"node11\" [label=\"<f0>B. Archivo 5|<f1>mia primer semestre 2023\" shape=\"record\" style=filled fillcolor=\"gold\"];\n";
    tree += "\"node0\":f2 -> \"node1\":f0;\n";
    tree += "\"node1\":f1 -> \"node2\":f0;\n";
    tree += "\"node2\":f2 -> \"node3\":f0;\n";
    tree += "\"node1\":f2 -> \"node4\":f0;\n";
    tree += "\"node4\":f2 -> \"node5\":f0;\n";
    tree += "\"node5\":f1 -> \"node6\":f0;\n";
    tree += "\"node6\":f2 -> \"node7\":f0;\n";
    tree += "\"node7\":f1 -> \"node8\":f0;\n";
    tree += "\"node8\":f2 -> \"node9\":f0;\n";
    tree += "\"node5\":f2 -> \"node10\":f0;\n";
    tree += "\"node10\":f2 -> \"node11\":f0;\n";
    tree += "}\n";
    ofstream dir;
    string cmd = "dot -Tjpg Ejemplo6_Tree.dot -o Ejemplo6_Tree.jpg";
    dir.open("Ejemplo6_Tree.dot");
    dir << tree;
    dir.close();
    system(cmd.c_str());
    system("fim -a Ejemplo6_Tree.jpg");
}