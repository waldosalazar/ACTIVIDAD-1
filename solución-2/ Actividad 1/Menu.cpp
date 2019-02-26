using namespace std;

Menu::Menu()
{
#include "menu.h"

using namespace std;

Menu::Menu()
{

}

void Menu::menu()
{
    string op;
    system("CLS");
    cout << endl << endl;

    cout << "\t\t **SEA BIENVENIDO Al PORTAL LOS TRES CHIFLADOS**  " << endl<< endl;
    cout << "Aqui podra hacer sus altas de productos y consultar "
            "productos que hayan sido guardados" << endl<< endl;
    system("PAUSE");

    cout << endl;
    while (true) {
        system("CLS");
        fflush(stdin);
        cout << endl << endl;
        cout << "\t\t ***LOS TRES CHIFLADOS***" << endl;
        cout << endl << endl;
        cout <<
                "1) Alta de producto" << endl
             << "2) Consulta" << endl
             << "3) Mostrar todo" << endl
             << "0) Salir" << endl
             << "Elija su opcion -->> "; getline(cin, op);
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
            cout <<  "HASTA PRONTO" <<endl;
            break;
        }
        system("PAUSE");
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
    cout << endl << endl << p.toString() << endl << endl;

    // GUARDA
    ofstream mercancia("mercancia.txt", ios::app);

    if (not mercancia.is_open()) {
        cout << "\t[*ADVERTENCIA*]\nNo se pudo abrir el archivo correctamente" << endl;
        return;
    }
    // Mete el producto con << en mercancía
    mercancia << p;

    mercancia.close();
}

string Menu::generarID(Producto &p)
{

    // Convierte en mayúsculas los 3 primeros del nobmre
    string str = p.getName().substr( 0, 3);
    for (auto & c : str) c = toupper(c);

    return  str + '-' +							// Los primeros 3 caracteres del nombre + '-' +
            to_string(lastIdInt() + 1);	// El número final del ID + 1 como string
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

    mercancia.close();
}

int Menu::lastIdInt()
{
    Producto p;

    ifstream mercancia("mercancia.txt", ios::in);
    if (not mercancia.is_open()) {
        return -1;
    }
    // Cuando termina este ciclo, p_temp tiene el último producto
    while (mercancia.peek() != -1 && mercancia >> p) {}

    mercancia.close();
    return p.getIdInt();
}
