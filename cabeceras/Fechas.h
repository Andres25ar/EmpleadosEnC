#ifndef FECHAS_H
#define FECHAS_H

typedef struct{
	int day;
	int month;
	int year;
}Fecha;

/*Todas las funciones correctamentes revisadas*/
Fecha CargaFecha ();
void ModificarFecha (Fecha*);
void MostrarFecha (Fecha);
void IntercambiaFechas(Fecha*, Fecha*);	/*Funciona ok*/
Fecha CopyFecha(Fecha);					/*Funciona ok*/

#endif
