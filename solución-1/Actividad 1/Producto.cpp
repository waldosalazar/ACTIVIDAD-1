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
	// Lee el siguiente número hasta llegar a una letra
	//		ej:		Se quiere leer el número de "4027Mi historia es .. fin"
	//				1. Lee 4, ¿Es número? size = 0 * 1 + 4 = 4
	//				2. Lee 0, ¿Es número? size = 4 * 10 + 0 = 40
	//				3. Lee 2, ¿Es número? size = 40 * 100 + 2 = 402
	//				4. Lee 7, ¿Es número? size = 402 * 1000 + 7 = 4027
	//				5. Lee M, ¿Es número? No, salir y retornar 4027.
	auto get_next_number = [&](){
		char digit;		// Guarda el último dígito leído
		int total = 0;	// Guarda el valor total de los dígitos acumulados
		in.get(digit);  // Lee el primer char
		while (digit >= '0' && digit <= '9')	// Entra si el char es número
		{
			total = total * 10 + (digit - '0');	// Acumula el valor de todo el número
			in.get(digit);				// Lee siguiente char
		}
		in.unget();	// "Des-lee" el último char leído
		return total + 1;
	};
	int size;
	char *buffer;

	size = get_next_number();	// Lee el tamaño de id
	buffer = new char[size];	// Crea un buffer del tamaño de id
	in.get(buffer, size);	// Lee los size dígitos en buffer
	p.setId(string(buffer));	// Guarda el buffer como string en Id
	delete[] buffer;			// Libera memoria de buffer

	size = get_next_number();	// Lee el tamaño de name
	buffer = new char[size];	// Crea un buffer del tamaño de name
	in.get(buffer, size);	// Lee los size dígitos en buffer
	p.setName(string(buffer));	// Guarda el buffer como string en name
	delete[] buffer;			// Libera memoria de buffer

	size = get_next_number();	// Lee el tamaño de description
	buffer = new char[size];	// Crea un buffer del tamaño de description
	in.get(buffer, size);	// Lee los size dígitos en buffer
	p.setDescription(string(buffer));// Guarda el buffer como string en description
	delete[] buffer;			// Libera memoria de buffer

	return in;
}

ostream& operator<<(ostream& os, Producto& p)
{
	//		tamaño				string
	os  << p.id.size()			<< p.id
		<< p.name.size()		<< p.name
		<< p.description.size()	<< p.description;

	return os;
}