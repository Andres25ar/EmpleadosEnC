#include <stdio.h>
#include <string.h>
#include "Cadena.h"

void LeeCad (TCadena cad, int tam){
    char c;
    int j;
    j = 0;
    c = getchar();
    while (c != EOF && c != '\n' && j<tam-1){
        cad[j] = c;
        c = getchar();
        j++;
    }
    cad [j] = '\0';
    j = 0;
    while (c != EOF && c != '\n'){
        j++;
        c = getchar();
    }
}

SCadena IngresaCadena (){
    SCadena cad;
    cad.tam = TAM_CAD;
    fflush(stdin);
    LeeCad (cad.cad, cad.tam);
    return cad;
}

int ComaparaCadenas (SCadena cad1, SCadena cad2){
    int ret;
    ret = -2;
    if (strlen(cad1.cad) != 0 && strlen(cad2.cad) != 0){
        ret = strcmp(cad1.cad, cad2.cad);
    }
    else{
        printf("\nError! Un texto vacio...");
    }
    return ret;
}

void MostrarCadena(SCadena cad){
    printf("%s", cad.cad);
}

void IntercambiaCadenas (SCadena*cad1, SCadena*cad2){
    TCadena cadAux;
    strcpy(cadAux, cad1->cad);
    strcpy(cad1->cad, cad2->cad);
    strcpy(cad2->cad, cadAux);
}

SCadena CopyCadena(SCadena cad){
    SCadena aux;
    aux.tam = cad.tam;
    strcpy(aux.cad, cad.cad);
    return aux;
}