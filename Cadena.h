#ifndef CADENA_H
#define CADENA_H

#define TAM_CAD 120

typedef char TCadena [TAM_CAD];

typedef struct{
	TCadena cad;
	int tam;
}SCadena;

/*Todas las funciones correctamentes revisadas*/
SCadena IngresaCadena ();
int ComaparaCadenas (SCadena, SCadena);
void MostrarCadena(SCadena);
void IntercambiaCadenas (SCadena*, SCadena*);	/*Funciona ok*/
SCadena CopyCadena(SCadena);					/*Funciona ok*/

#endif
