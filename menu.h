#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <iomanip>
#include "producto.h"

using namespace std;

class Menu
{
public:
    Menu();
    void menu();
    void altaProducto();
    void consultaProducto();
    void generarID();
    void guardar();
    void recuperar(string llave);

private:
    Producto p;
};

#endif // MENU_H
