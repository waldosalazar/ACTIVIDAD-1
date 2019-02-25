#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Producto.h"


class Menu
{
public:
	Menu();
	void menu();
	void altaProducto();
	void consultaProducto();
	void mostrarProductos();
	std::string generarID(Producto &p);
	void guardar();
	void recuperar(std::string llave);
	int lastIdInt();

private:
	//Producto p;
};
