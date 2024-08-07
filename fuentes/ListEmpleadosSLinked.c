#include <stdio.h>
#include <stdlib.h>
#include "ListEmpleadosSLinked.h"

T_Ptr CrearNodo(long dni){
    T_Ptr nvo;
    nvo = (T_Ptr)malloc(sizeof(T_Nodo));
    nvo->datum = CargaEmpleado(dni);
    nvo->next = NULL;
    return nvo;
}

/*Inserta ordenado siempre*/
InsertaNvoNodo(T_Ptr* lista, T_Ptr new){
    T_Ptr prev, next;
    prev = NULL;
    next = *lista;
    if (next == NULL){
        *lista = new;
    }
    else{
        if(ReturnDNI(new->datum) < ReturnDNI(next->datum)){
            new->next = *lista;
            *lista = new;
        }
        else{
            prev = next;
            next = next->next;
            while (ReturnDNI(next->datum) < ReturnDNI(new->datum) && next->next != NULL){
                prev = next;
                next = next->next;
            }
            if (next->next == NULL && ReturnDNI(next->datum) < ReturnDNI(new->datum)){
                next->next = new;
            }
            else{
                prev->next = new;
                new->next = next;
            }
        }
    }
}

void CargaListSLinked (T_Ptr* lista, int tam){
    long dni;
    int pos, i;
    T_Ptr aux;
    printf("Ingrese dni: ");
    scanf("%ld", &dni);
    for (i = 0; i < tam; i++){
        if (*lista == NULL){
            aux = CrearNodo(dni);
            InsertaNvoNodo(lista, aux);
        }
        else{
            do{
                printf("Ingrese dni: ");
                scanf("%ld", &dni);
                pos = Busqueda(*lista, dni);
            } while (pos == -1);
            aux = CrearNodo(dni);
            InsertaNvoNodo(lista, aux);
        }
    }
}

Lista CargaListaSinRep(){
    Lista lista;
    int aux;
    printf("\nIngese cantidad deseada: ");
    scanf ("%d", &aux);
    CargaListSLinked(&lista.lista, aux);
    lista.tam = aux;
}

void MuestaSLinked (T_Ptr lista, int tam){
    T_Ptr reco;
    int i;
    reco = lista;
    for (i = 0; i < tam; i++){
        MostrarEmpleado(reco->datum);
        reco = reco->next;
    }
    
}

void MostrarListaS(Lista lista){
    printf("\nSU LISTA:\n");
    MuestaSLinked(lista.lista, lista.tam);
}

int Busqueda(T_Ptr lista, long dniBus){
    T_Ptr node;
    int i;
    i = 0;
    node = lista;
    while (ReturnDNI(node->datum) != dniBus && node != NULL){
        node = node->next;
        i++;
    }
    if (node == NULL){
        i = -1;
    }
    return i;
}

int BuscarSLinked (Lista, long);
void AgregarNvo(Lista*);

int Tamanio(Lista list){
    int ret;
    ret = list.tam;
    return ret;
}
