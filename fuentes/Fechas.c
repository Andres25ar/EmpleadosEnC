#include <stdio.h>
#include "Fechas.h"

int ComprobarAnioBisiesto (int anio){
    int bis;
    bis = 0;
    if(anio%4 == 0){
        if (anio%100 == 0){
            if (anio%400 == 0){
                bis = 1;
            }
        }
        else
            bis = 1;
    }
    return bis;
} 

int ValidaFecha (Fecha fecha){
    int validez;
    validez = 0;
    if (fecha.year > 1900 && fecha.year < 2025){
        if (fecha.month>0 && fecha.month<13){
            switch (fecha.month){
            case 1: 
            case 3: 
            case 5: 
            case 7: 
            case 8: 
            case 10: 
            case 12:
                if (fecha.day <= 31)
                    validez = 1;
                break;
            case 4: 
            case 6: 
            case 9: 
            case 11:
                if (fecha.day <= 30)
                    validez = 1;
                break;
            default:
                if (ComprobarAnioBisiesto(fecha.year) == 1 && fecha.day <= 29){
                    validez = 1;
                }
                else if (fecha.day <= 28){
                    validez = 1;
                }
                break;
            }
        }
    }
    return validez;
}

Fecha CargaFecha (){
    Fecha fecha;
    do{
        printf("\nIngrese dia: ");
        scanf("%d", &fecha.day);
        printf("\nIngrese mes: ");
        scanf("%d", &fecha.month);
        printf("\nIngrese anio: ");
        scanf("%d", &fecha.year);
    } while (ValidaFecha(fecha) == 0);
    return fecha;
}

void ModificarFecha (Fecha*fecha){
    Fecha date;
    printf ("\nSu fecha actual: ");
    MostrarFecha(*fecha);
    printf("\nCargue sus modificaciones: ");
    do{
        printf("\nIngrese dia: ");
        scanf("%d", &date.day);
        printf("\nIngrese mes: ");
        scanf("%d", &date.month);
        printf("\nIngrese anio: ");
        scanf("%d", &date.year);
    } while (ValidaFecha(date) == 0);
    *fecha = date;
}

void MostrarFecha (Fecha fcha){
    printf("\n%d/%d/%d", fcha.day, fcha.month, fcha.year);
}

/*FUNCIONA*/
void IntercambiaFechas(Fecha*fcha1, Fecha*fcha2){
    Fecha aux;
    aux.day = fcha1->day;    
    aux.month = fcha1->month;
    aux.year = fcha1->year;
    fcha1->day = fcha2->day;    
    fcha1->month = fcha2->month;
    fcha1->year = fcha2->year;
    fcha2->day = aux.day;    
    fcha2->month = aux.month;
    fcha2->year = aux.year; 
}

Fecha CopyFecha(Fecha fcha){
    return fcha;
}
