#include <stdio.h>
#include "Empleado.h"

Empleado CargaEmpleado (long dni){
    Empleado emple;
    SCadena cadAux;
    Fecha fechaAux;
    emple.dni = dni;
    printf("\nIngrese nombre: ");
    cadAux = IngresaCadena();
    emple.nombre = cadAux;
    printf("\nIngrese apellido: ");
    cadAux = IngresaCadena();
    emple.apellido = cadAux;
    printf("\nIngrese celular: ");
    cadAux = IngresaCadena();
    emple.celular = cadAux;
    printf("\nCargue el turno de digitando las sig opciones: 1-Matutino. 2-Tarde. 3-Noche");
    do{
        printf("\nIngrese una opcio correcta: ");
        scanf("%d", &emple.turno);
    } while (emple.turno<=0 || emple.turno>=4);
    printf("\nCargue fecha de alta del empleado (formato dd/mm/aaaa): ");
    emple.fechaAlta = CargaFecha();
    return emple;
}

short ReturnTurno (Empleado emple){
    return emple.turno;
}

long ReturnDNI (Empleado emple){
    return emple.dni;
}

void ModifEmpleado (Empleado* emple, long nvo_dni){
    printf("\nDatos actuales del empleado: ");
    MostrarEmpleado(*emple);
    emple->dni = nvo_dni;
    printf("\nIngrese nobre: ");
    emple->nombre = IngresaCadena();
    printf("\nIngrese apellido: ");
    emple->apellido = IngresaCadena();
    printf("\nIngrese celular: ");
    emple->celular = IngresaCadena();
    printf("\nCargue el turno de digitando las sig opciones: 1-Matutino. 2-Tarde. 3-Noche");
    do{
        printf("\nIngrese una opcio correcta: ");
        scanf("%i", &emple->turno);
    } while (emple->turno<=0 || emple->turno>=4);
    printf("\nCargue fecha de alta del empleado (formato dd/mm/aaaa): ");
    emple->fechaAlta = CargaFecha();
}

void MostrarEmpleado (Empleado emple){
    printf("\nEmpleado: ");
    MostrarCadena(emple.apellido);
    printf(" , ");
    MostrarCadena(emple.nombre);
    printf("\nDni: %d", emple.dni);
    printf("\nTelCelular: ");
    MostrarCadena(emple.celular);
    printf("\nDel Turno:");
    switch (emple.turno)
    {
    case 1:
        printf("\tMatutino");
        break;
    case 2:
        printf("\tTarde");
        break;
    case 3:
        printf("\tNoche");
    default:
        break;
    }
    printf("\nDado de alta el dia: ");
    MostrarFecha(emple.fechaAlta);  
}

/*FUNCIONA*/
void IntercambiaEmpleado(Empleado*emp1, Empleado*emp2){
    Empleado aux;
    aux.dni = emp1->dni;
    aux.turno = emp1->turno;
    IntercambiaCadenas(&aux.apellido, &emp1->apellido);
    IntercambiaCadenas(&aux.nombre, &emp1->nombre);
    IntercambiaCadenas(&aux.celular, &emp1->celular);
    IntercambiaFechas(&aux.fechaAlta, &emp1->fechaAlta);
    emp1->dni = emp2->dni;
    emp1->turno = emp2->turno;
    IntercambiaCadenas(&emp1->apellido, &emp2->apellido);
    IntercambiaCadenas(&emp1->nombre, &emp2->nombre);
    IntercambiaCadenas(&emp1->celular, &emp2->celular);
    IntercambiaFechas(&emp1->fechaAlta, &emp2->fechaAlta);
    emp2->dni = aux.dni;
    emp2->turno = aux.turno;
    IntercambiaCadenas(&emp2->apellido, &aux.apellido);
    IntercambiaCadenas(&emp2->nombre, &aux.nombre);
    IntercambiaCadenas(&emp2->celular, &aux.celular);
    IntercambiaFechas(&emp2->fechaAlta, &aux.fechaAlta);
}

Empleado CopyEmpleado (Empleado emp){
    return emp;
}
