#include <stdio.h>
#include "ListaEmpleados.h"

void MergeSort(ListaEmpleados, int, int);

int BuscaRepetidosSec(ListaEmpleados lista, int tam, long dniBuscado){
    int i, ret;
    i = 1;
    while (i<=tam && ReturnDNI(lista[i]) != dniBuscado)
        i++;
    if (i<=tam)
        ret = 1;    /* si el dni buscado esta en la lista */
    else
        ret = 0;    /* si el dni buscado NO esta en la lista */
    return ret;
}

void CargaEmpleadosSinRep(ListaEmpleados lista, int tam){
    int i, rep;
    long auxDni;
    printf("Ingrese dni: ");
    scanf("%ld", &auxDni);
    lista[1] = CargaEmpleado(auxDni);
    for (i = 2; i <= tam; i++){
        do{
            printf("Ingrese dni: ");
            scanf("%ld", &auxDni);
            rep = BuscaRepetidosSec(lista, i-1, auxDni);
        } while (rep == 1);
        lista[i] = CargaEmpleado(auxDni);
    }
    /*IntercambiaEmpleado(&lista[2], &lista[1]);PROBAR Y BORRAR*/
}

EmpleadoArr CargarLista (){
    /*int tam;*/
    EmpleadoArr lista;
    printf("\nCantidad de empleados a cargar? ");
    scanf ("%d", &lista.tam);
    printf("\nIngrese lista de empleados (NO SE PERMITEN DNI REPETIDOS)...");
    CargaEmpleadosSinRep(lista.lista, lista.tam);
    /*lista.tam = lista.tam+1;PROBAR Y BORRAR*/
    return lista;
}

void Merge (ListaEmpleados lista, int ini, int med, int fin){
    ListaEmpleados listaAux;
    int i, j, k, t;
    k = 0;  i = ini;    j = med+1;
    while (i<=med && j<=fin){
        k++;
        if (ReturnDNI(lista[i]) < ReturnDNI(lista[j])){
            listaAux[k] = CopyEmpleado(lista[i]);
            i++;
        }
        else{
            listaAux[k] = CopyEmpleado(lista[j]);
            j++;
        }
    }
    for (t = i; t <= med; t++){
        k++;
        listaAux[k] = CopyEmpleado(lista[t]);
    }
    for (t = j; t <= fin; t++){
        k++;
        listaAux[k] = CopyEmpleado(lista[t]);
    }
    for (i = 1; i <= fin; i++)
        IntercambiaEmpleado(&lista[ini+i-1], &listaAux[i]);
        /*lista[ini+i-1] = CopyEmpleado(listaAux[i]);*/
}

void MergeSort(ListaEmpleados lista, int ini, int fin){
    int med;
    if (ini < fin){ 
        med = (ini+fin)/2;
        MergeSort(lista, ini, med);
        MergeSort(lista, med+1, fin);
        Merge(lista, ini, med, fin);
    }
    
}

void OrdenarLista (EmpleadoArr *lista){
    MergeSort(lista->lista, 1, lista->tam);
}

void AgregarEmpleado (EmpleadoArr*);
void EliminarEmpleado (EmpleadoArr*);
int BuscarEmpleadoXDni (EmpleadoArr);
void VerTurnoMayoritario (EmpleadoArr);

void MostrarListRecur (ListaEmpleados lista, int tam){
    if (tam > 0){
        MostrarListRecur(lista, tam-1);
        MostrarEmpleado(lista[tam]);
    }
}

void MostrarLista (EmpleadoArr lista){
    if (lista.tam != 0)
        MostrarListRecur(lista.lista, lista.tam);
    else
        printf("\nLISTA VACIA. NADA QUE MOSTRAR");
}

void MostrarXTurnoRec(ListaEmpleados lista, int tam, short turno){
    if (tam>0){
        if (ReturnTurno(lista[tam]) == turno){
            MostrarXTurnoRec(lista, tam-1, turno);
            MostrarEmpleado(lista[tam]);
        }
        else
            MostrarXTurnoRec(lista, tam-1, turno);
    }
}

void MostrarXTurno (EmpleadoArr lista){
    int op;
    printf("\nIngrese un numero por el turno que desea ver: 1-Matutino; 2-Tarde; 3-Noche:\n");
    do{
        scanf("%d", &op);
    } while (op<=0 || op>=4);
    
    switch (op){
    case 1:
        printf("\nTurno Matutino: \n");
        break;
    case 2:
        printf("\nTurno Tarde: \n");
        break;
    case 3:
        printf("\nTurno Noche: \n");
        break;
    default:
        break;
    }
    MostrarXTurnoRec(lista.lista, lista.tam, (short)op);
}
