using namespace std;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <initializer_list>
#include <cstring>
#include <cstdlib>
class Archivo{
	public:
	void leerArchivo();
	void buscar();	
	void buscarPorNum();
	void buscarPorNombre();
	bool abrirArchivo();
};

void Archivo::leerArchivo(){
	string texto;
	ifstream archivo;
	archivo.open("GuiaTelefonica.txt",ios::in);
	if(archivo.fail()){
		cout<<"ERROR. No se pudo leer en el archivo."<<endl;	
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<"\n\t"<<texto;					
	}
	archivo.close();				
}                  

void Archivo::buscarPorNombre(){
	fstream archivo;
	string cadena, linea1, linea2;
	int count=0;
	cout<<"\n\tIngresar nombre: ";
	cin>>cadena;
	if(!archivo.is_open()){
		archivo.open("GuiaTelefonica.txt",ios::in);
	}
	while(getline(archivo,linea1)){
		if(linea1.find(cadena)!=string::npos){
			cout<<"\n\tNombre: "<<linea1<<endl;
			getline(archivo,linea2);
			cout<<"\n\tNumero telefonico : "<<linea2<<endl;
			count=1;
		}
		//string::npos es una constante (probablemente -1 ) que representa una no posicion. Se devuelve por el metodo find cuando no se encontro el patron.
	}
	if(count==0){
		cout<<cadena<<" No se ha encontrado en el registro "<<endl;	
	}
	archivo.close();	
}

void Archivo::buscarPorNum(){
	fstream archivo;
	string cadena, linea1, linea2,linea;
	int count=0;
	cout<<"\n\tIngresar numero telefonico: ";
	cin>>cadena;
	if(!archivo.is_open()){
		archivo.open("GuiaTelefonica.txt",ios::in);
	}
	do{
		fflush(stdin);
		getline(archivo,linea);
		getline(archivo,linea2);
		if(linea2.find(cadena)!=string::npos){
			cout<<"\n\tNombre: "<<linea<<endl;
			cout<<"\n\tNumero telefonico : "<<linea2<<endl;
			count=1;
		}
	}while(getline(archivo,linea1));
	
	if(count==0)
		cout<<cadena<<" No se ha encontrado en el registro "<<endl;	
	archivo.close();	
}
