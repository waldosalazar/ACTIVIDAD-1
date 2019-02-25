#include "Producto.h"

using namespace std;

Producto::Producto() : id("XXX-0"), name("Y"), description("Z")
{

}

string Producto::getName() const
{
	return name;
}

void Producto::setName(const string &value)
{
	name = value;
}

string Producto::getDescription() const
{
	return description;
}

void Producto::setDescription(const string &value)
{
	description = value;
}

string Producto::getId() const
{
	return id;
}

void Producto::setId(const string &value)
{
	id = value;
}

int Producto::getIdInt() const
{
	// Retorna el número final del ID como entero
	//		ej:		Se quiere saber el número de XXX-985
	//				1. Crea una substring desde la posición 4 hasta el final
	//				2. Retorna la cadena "985" como entero
					
	return stoi(id.substr(4, id.size()));
}

std::string Producto::toString() const
{
	return id + "\t|\t" + name + "\t|\t" + description;
}

std::istream & operator>>(std::istream & in, Producto & p)
{
	char *buffer;	// Buffer donde se almacena temporalmente el campo
	string tam;		// Buffer donde se almacena temporalmente el tamaño del capo
	int size;		// Tamaño del campo en int

	if (in.peek() == -1) { // Comprueba que no sea el fin del archvio
		in.get();
		return in;
	}

	getline(in, tam, ' ');		// Lee el tamaño de 'id' en 'tam'
	size = stoi(tam) + 1;		// string 'tam' a entero 'size'
	buffer = new char[size];	// Crea un buffer del tamaño de 'id'
	in.get(buffer, size);		// Lee los 'size' caracteres en buffer
	p.setId(string(buffer));	// Guarda el buffer como string en 'Id'
	delete[] buffer;			// Libera memoria de buffer

	getline(in, tam, ' ');		// Lee el tamaño de 'name' en 'tam'
	size = stoi(tam) + 1;		// string 'tam' a entero 'size'
	buffer = new char[size];	// Crea un buffer del tamaño de 'name'
	in.get(buffer, size);		// Lee los 'size' caracteres en buffer
	p.setName(string(buffer));	// Guarda el buffer como string en 'name'
	delete[] buffer;			// Libera memoria de buffer

	getline(in, tam, ' ');		// Lee el tamaño de 'description' en 'tam'
	size = stoi(tam) + 1;		// string 'tam' a entero 'size'
	buffer = new char[size];	// Crea un buffer del tamaño de 'description'
	in.get(buffer, size);		// Lee los 'size' caracteres en buffer
	p.setDescription(string(buffer));// Guarda el buffer como string en 'description'
	delete[] buffer;			// Libera memoria de buffer

	return in;
}

ostream& operator<<(ostream& os, Producto& p)
{
	//		tamaño				   sep	  string
	os  << p.id.size()			<< " " << p.id
		<< p.name.size()		<< " " << p.name
		<< p.description.size()	<< " " << p.description;

	return os;
}