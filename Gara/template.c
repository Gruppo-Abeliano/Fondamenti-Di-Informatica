#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PATH 20

/*
#define NUM_RIGHE 10
#define NUM_COLONNE 10
*/

/*lista dinamica*/
typedef struct EL{
    char carattere;
    struct EL* next;
} ElemLista;
typedef ElemLista *Lista;

/*function 1*/
void function1();
/*function 2*/
void function2();
/*function 3*/
void function3();
/*function 4*/
void function4();
/*lettura matrice - SI PRESUPPONE CHE VENGA DEFINITO IL TIPO MATRICE DEL TIPO CORRETTO (int,char,float...)*/
void leggiMatrice(Matrice daLeggere);
/*stampa lista*/
void stampalista(ElemLista);

int main(){
    char path[MAX_PATH];
    FILE *input;

    /*leggo il path del file*/
    scanf("%20s", path);
    
    /*To do list*/
    
    /*apro il file*/
    input = fopen(path, "r");

    /*...*/

    /*controlla se corretto e stampa 1 in caso contrario 0*/
    if(/*function*/)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}


void function1(){

}

void function2(){

}

void function3(){

}

void function4(){

}

/*stampa lista*/
void stampalista(ElemLista* l){
    if(l!=NULL)
    {
        printf("%c",l->carattere);
        stampalista(l->next);
    }
}

/*Stampa la matrice*/
void leggiMatrice(Matrice daLeggere)
{
    int contaRighe,contaColonne;

    for(contaRighe=0;contaRighe<NUM_RIGHE;contaRighe++)
    {
        for(contaColonne=0;contaColonne;contaColonne<NUM_COLONNE;contaColonne++)
        {
            printf("%d ",daLeggere[contaRighe][contaColonne]);
        }
        printf("\n");
    }
}