#include <iostream>
#include "Auxiliar.h"
#include "Archivo.h"
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: Viernes,Diciembre  29, 2021 5:49:23 PM
 * Fecha de modificacion: Viernes, Diciembre 29, 2021 11:10:23 PM
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 * Programa: Busqueda guia telefonica

 ***********************************************************************/

int main(int argc, char** argv) {
	Auxiliar aux;
	Archivo archivo;
	int opc,opc2;
	do{
		system("cls");
		opc=aux.menu();	
		switch(opc){
		case 1:{
			cout<<"\n\tRegistro de numeros telefonicos\n";
			archivo.leerArchivo();
			system("pause");
			break;
		}
		case 2:{
			do{
				system("cls");
				opc2=aux.menu2();	
				switch(opc2){ 
					case 1:{
						archivo.buscarPorNombre();
						system("pause");
						break;
					}
					case 2:{
						
						archivo.buscarPorNum();
						system("pause");
						break;
					}
					case 0:{
						cout<<"\n\tRegresando menu principal\n";
						break;
					}
					default:{
						cout<<"\n\tOpcion Incorrecta\n";
						system("pause");
						break;
					}
				}	
			}while(opc2!=0);
			break;
		}
		case 0:{
			cout<<"\n\tAdios...\n";
			break;
		}
		default:{
			cout<<"\n\tOpcion Incorrecta\n";
			break;
		}
	}
	system("pause");	
	}while(opc!=0);
	
	
	
	
	
	
	return 0;
}