%defines
%{
    #include "scanner.cpp"
    #include <stdlib.h>
    #include <iostream>
    #include "nodo.h"

    using namespace std;

    extern int yylineno;
    extern char *yytext;
    extern int yyfila;
    extern int yycolum;
    Nodo* Raiz = nullptr;

    int yyerror(const char* mensaje){
        return 0;
    }

    Nodo* getRaiz(){
    return Raiz;
    }
%}

%define parse.error verbose

%union{
    char TEXT [300];
    struct Nodo* NODO;
}

%token<TEXT> crear
%token<TEXT> escribir
%token<TEXT> vertodo
%token<TEXT> verx
%token<TEXT> editarx
%token<TEXT> tamano
%token<TEXT> dimensional
%token<TEXT> id
%token<TEXT> nombre
%token<TEXT> telefono
%token<TEXT> direccion
%token<TEXT> x
%token<TEXT> mayor
%token<TEXT> igual
%token<TEXT> entero
%token<TEXT> txt
%type<NODO> INICIO
%type<NODO> LCMD
%type<NODO> COMANDOS
%type<NODO> LCOMANDOS
%type<NODO> LOPCIONES
%type<NODO> OPCIONES

%start INICIO
%%

INICIO:LCMD { Raiz = $$; };

LCMD:LCMD COMANDOS
   {
        Nodo* n = new Nodo("LCMD","","");
        n->addHijo($1);
        n->addHijo($2);
        $$ = n;
   }
   |COMANDOS
   {
        Nodo* n = new Nodo("LCMD","","");
        n->addHijo($1);
        $$ = n;
   };

COMANDOS:LCOMANDOS LOPCIONES
        {
            Nodo* n = new Nodo("COMANDOS","","");
            n->addHijo($1);
            n->addHijo($2);
            $$ = n;
        }
        |LCOMANDOS
        {
            Nodo* n = new Nodo("COMANDOS","","");
            n->addHijo($1);
            $$ = n;
        };

LCOMANDOS:crear
         {
            Nodo* n = new Nodo("Crear",$1,"");
            $$ = n;
         }
         |escribir
         {
            Nodo* n = new Nodo("Escribir",$1,"");
            $$ = n;
         }
         |vertodo
         {
            Nodo* n = new Nodo("Vertodo",$1,"");
            $$ = n;
         }
         |verx
         {
            Nodo* n = new Nodo("Verx",$1,"");
            $$ = n;
         }
         |editarx
         {
            Nodo* n = new Nodo("Editarx",$1,"");
            $$ = n;
         };

LOPCIONES:LOPCIONES OPCIONES
     {
        Nodo* n = new Nodo("LOPCIONES","","");
        n->addHijo($1);
        n->addHijo($2);
        $$ = n;
     }
     |OPCIONES
     {
        Nodo* n = new Nodo("LOPCIONES","","");
        n->addHijo($1);
        $$ = n;
     };

OPCIONES:mayor tamano igual entero
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* ntamano = new Nodo("Tamano",$2,"Tamano");
        Nodo* nentero = new Nodo("Entero",$4,"Entero");
        n->addHijo(ntamano);
        n->addHijo(nentero);
        $$ = n;
    }
    |mayor dimensional igual txt
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* ndimensional = new Nodo("Dimensional",$2,"Dimensional");
        Nodo* ntxt = new Nodo("Texto",$4,"Texto");
        n->addHijo(ndimensional);
        n->addHijo(ntxt);
     $$ = n;
    }
    |mayor id igual entero
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* nid = new Nodo("Id",$2,"Id");
        Nodo* nentero = new Nodo("Entero",$4,"Entero");
        n->addHijo(nid);
        n->addHijo(nentero);
        $$ = n;
    }
    |mayor nombre igual txt
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* nnombre = new Nodo("Nombre",$2,"Nombre");
        Nodo* ntxt = new Nodo("Texto",$4,"Texto");
        n->addHijo(nnombre);
        n->addHijo(ntxt);
     $$ = n;
    }
    |mayor telefono igual entero
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* ntelefono = new Nodo("Telefono",$2,"Telefono");
        Nodo* nentero = new Nodo("Entero",$4,"Entero");
        n->addHijo(ntelefono);
        n->addHijo(nentero);
        $$ = n;
    }
    |mayor direccion igual txt
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* ndireccion = new Nodo("Direccion",$2,"Direccion");
        Nodo* ntxt = new Nodo("Texto",$4,"Texto");
        n->addHijo(ndireccion);
        n->addHijo(ntxt);
     $$ = n;
    }
    |mayor x igual entero
    {
        Nodo* n = new Nodo("OPCIONES","","");
        Nodo* nx = new Nodo("X",$2,"X");
        Nodo* nentero = new Nodo("Entero",$4,"Entero");
        n->addHijo(nx);
        n->addHijo(nentero);
        $$ = n;
    };
