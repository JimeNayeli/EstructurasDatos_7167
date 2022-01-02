#pragma once
using namespace std;
template<typename T>
class Vector
{
private: 
	T* data;
public:
	Vector() = default;
	void setVector(T*);
	T* getVector();
	T* segmentar(int);
};

template<typename T>
inline void Vector<T>::setVector(T* _data)
{
	this->data = _data;
}

template<typename T>
inline T* Vector<T>::getVector()
{
	return data;
}

template<typename T>
inline T* Vector<T>::segmentar(int size)
{
	Vector<T> vector;
	vector.setVector((T*)realloc(data, (size + 1) * sizeof(T)));
	return vector.getVector();
}