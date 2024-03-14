#include <iostream>
#include "Colas.h"
int main() {
	Cola<string> cola(5);
	cola.push("juan");
	cola.push("pedro");
	cola.push("pablo");
	cola.push("mateo");
	cola.push("marcos");
	cola.push("judas");

	cola.imprimir();

	string aux = cola.pop();

	cola.imprimir();


	return 0;
}