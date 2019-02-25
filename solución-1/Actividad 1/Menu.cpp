#include "Menu.h"

using namespace std;

Menu::Menu()
{
	
}

void Menu::menu()
{
	string op;
	while (true) {
		cout << "1) Alta de producto" << endl
			 << "2) Consulta" << endl
			 << "3) Mostrar todo" << endl
			 << "0) Salir" << endl
			 << ">> "; getline(cin, op);
		if (op == "1") {
			altaProducto();
		}
		else if (op == "2") {
			consultaProducto();
		}
		else if (op == "3") {
			mostrarProductos();
		}
		else if (op == "0") {
			break;
		}
	}
}

void Menu::altaProducto()
{
	string palabra;
	Producto p;

	cout << setw(40) << "[*ALTA DE PRODUCTO*]" << endl;
	cout << "Nombre: "; getline(cin, palabra);
	p.setName(palabra);
	cout << "Descripcion del producto: "; getline(cin, palabra);
	p.setDescription(palabra);
	p.setId(generarID(p));
	cout << endl << endl << p << endl << endl;
	
	// GUARDA
	ofstream mercancia("mercancia.txt", ios::app);

	if (not mercancia.is_open()) {
		cout << "\t[*ADVERTENCIA*]\nNo se pudo abrir el archivo correctamente" << endl;
		return;
	}
	// Mete el producto con << en mercanc�a
	mercancia << p;

	mercancia.close();
}
string Menu::generarID(Producto &p) {
	Producto p_temp;
	ifstream mercancia("mercancia.txt", ios::app);
	if (not mercancia.is_open()) {
		cout << "ERROR AL ABRIR EL ARCHIVO :(" << endl;
		return "XXX-0";
	}
	// Cuando termina este ciclo, p tiene el �ltimo producto
	while (mercancia.peek() != -1 && mercancia >> p_temp) { }

	mercancia.close();

	return p.getName().substr(0, 3) + '-' +		// Los primeros 3 caracteres del nombre + '-' +
			to_string(p_temp.getIdInt() + 1);	// El n�mero final del ID + 1 como string
}
void Menu::consultaProducto()
{
	string llave;
	cout << "\t[*CONSULTAR PRODUCTO*]" << endl
		<< "ID: "; getline(cin, llave);
	recuperar(llave);
}
void Menu::mostrarProductos()
{
	ifstream mercancia("mercancia.txt", ios::in);

	if (not mercancia.is_open()) {
		cout << "ERROR AL ABRIR EL ARCHIVO :(" << endl;
		return;
	}

	// Lee el siguiente
	Producto p;
	while (mercancia >> p) {
		cout << p.toString() << endl;
	}
	mercancia.close();
}
void Menu::guardar()
{
	
}
void Menu::recuperar(string llave)
{
	ifstream mercancia("mercancia.txt", ios::in);

	if (not mercancia.is_open()) {
		cout << "ERROR AL ABRIR EL ARCHIVO :(" << endl;
		return;
	}

	// Lee el siguiente
	Producto p;
	while (mercancia >> p) {
		if (p.getId() == llave) // Solo muestra el que tenga la llave correcta
			cout << "Producto encontrado: " << p.toString() << endl;
	}
}