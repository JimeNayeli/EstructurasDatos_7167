
#pragma once
using namespace std;
template<typename T>
class Vector
{
private:
	int dim; 
	T* data;
public:
	Vector() = default;
	void set_vector(T*);
	T* get_vector();
	T* segmentar(int size);
	void setDim(int newDim);
	int getDim();
};

template<typename T>
inline void Vector<T>::set_vector(T* _data)
{
	this->data = _data;
}

template<typename T>
inline T* Vector<T>::get_vector()
{
	return data;
}

template<typename T>
inline T* Vector<T>::segmentar(int size)
{
	Vector<T> vector;
	vector.set_vector((T*)realloc(data, (size + 1) * sizeof(T)));
	return vector.get_vector();
	dim++;
}
template<typename T>
void Vector<T>::setDim(int newDim) {
   dim = newDim; }
   
template <class T>
int Vector<T>::getDim() {
   return dim; }