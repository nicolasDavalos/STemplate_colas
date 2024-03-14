#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Cola
{
private:
	T* cola;
	int frente;
	int fin;
	int tamano;
public:
	Cola(int tamano);
	~Cola();
	void push(T dato);
	T pop();
	int getFrente();
	bool estaVacia();
	bool estaLlena();
	void imprimir();
};

template<typename T>
inline Cola<T>::Cola(int _tamano)
{
	tamano = _tamano;
	cola = new T[tamano];
	frente = -1;
	fin = -1;
}

template<typename T>
inline Cola<T>::~Cola()
{
	delete[] cola;
}

template<typename T>
inline void Cola<T>::push(T dato)
{
	if (!estaLlena())
	{
		if (estaVacia()) {
			frente++;
		}
		fin = (fin + 1) % tamano;
		cola[fin] = dato;
	}
	else
	{
		cout << "La cola esta llena" << endl;
	}
}

template<typename T>
inline T Cola<T>::pop()
{
	if (!estaVacia())
	{
		T dato = cola[frente];
		if (frente == fin) {
			frente = fin = -1;
		}
		else {
			frente = (frente + 1) % tamano;
		}
		return dato;
	}
	else
	{
		cout << "La cola esta vacia" << endl;
		return T();
	}
}

template<typename T>
inline int Cola<T>::getFrente()
{
	return frente;
}

template<typename T>
inline bool Cola<T>::estaVacia()
{
	return frente == -1 && fin == -1;
}

template<typename T>
inline bool Cola<T>::estaLlena()
{
	return (fin + 1) % tamano == frente;
}

template<typename T>
inline void Cola<T>::imprimir()
{
	if (estaVacia()) {
		cout << "La cola esta vacia" << endl;
		return;
	}

	int i = frente;
	do {
		cout << cola[i] << " ";
		i = (i + 1) % tamano;
	} while (i != (fin + 1) % tamano);

	cout << endl;
}