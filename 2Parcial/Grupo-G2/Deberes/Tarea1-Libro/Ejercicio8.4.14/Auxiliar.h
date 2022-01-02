#include <iostream>
using namespace std;
class Auxiliar{
	public: 
		int menu();
		int menu2();
		
	
};
int Auxiliar::menu(){
	int op;
	cout<<"\n\tGUIA TELEFONICA";
	cout<<"\n1. Vizualizar guia telefonica";
	cout<<"\n2. Buscar datos";
	cout<<"\n0. Salir";
	cout<<"\nIngresar opcion: ";
	cin>>op;
	return op;
}

int Auxiliar::menu2(){
	int op;
	cout<<"\n\tBUSQUEDA";
	cout<<"\n1. Buscar por nombre";
	cout<<"\n2. Buscar numero";
	cout<<"\n0. Regresar";
	cout<<"\nIngresar opcion: ";
	cin>>op;
	return op;
}
