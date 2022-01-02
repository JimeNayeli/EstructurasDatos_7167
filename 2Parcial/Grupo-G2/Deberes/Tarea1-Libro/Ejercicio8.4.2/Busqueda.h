#include "Vector.h"

template <typename T>
void busquedaSecuencial(Vector<T> vector,int tam,int buscar){
    bool encontrado=false;
    int i=0;
    while (i<tam && encontrado==false)
    {
        if(*(vector.get_vector()+i)==buscar){
            encontrado=true;
        }
        i++;
    }
    if (encontrado==true)
    {
        cout<<"El elemento "<<buscar<<" se encuentra en la posicion "<<i<<endl;
    }
    else{
        cout<<"El elemento "<<buscar<<" no se encuentra en el vector"<<endl; 
    }    
}
