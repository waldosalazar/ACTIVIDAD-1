#include "menu.h"

Menu::Menu()
{
    cont = 10;
}

void Menu::menu()
{
    string op;
    fstream mercancia("mercancia.txt",ios::in|ios::app);
    if(!mercancia.is_open()){
        cerr<<"No se pudo abrir el archivo con exito"<<endl;
        exit(1);
    }
    while (true) {
        mercancia.clear();
        mercancia.seekg(0);
        cout<<"1) Alta de producto"<<endl
           <<"2) Consulta"<<endl
          <<"3) Consulta General"<<endl
         <<"4) Salir"<<endl
        <<">> "; getline(cin,op);
        if(op=="1"){
            altaProducto();
        }
        else if(op=="2"){
            consultaProducto(mercancia);
        }
        else if(op=="3"){
            consultaGeneral(mercancia);
        }
        else if(op=="4"){
            break;
        }
        else{
            cout<<"Opcion Incorrecta"<<endl;
        }
    }
}

void Menu::altaProducto()
{
    string palabra;
    cout<<setw(40)<<"[*ALTA DE PRODUCTO*]"<<endl;
    cout<<"Nombre: "; getline(cin,palabra);
    p.setName(palabra);
    cout<<"Descripcion del producto: "; getline(cin,palabra);
    p.setDescription(palabra);
    generarID();
    cout<<endl<<endl<<p;
    guardar();
}
void Menu::generarID(){
    string id;
    string complemento;
    stringstream ss;
    ss<<cont;
    id = p.getName().substr(0,2) + "-" + ss.str();
    cout<<id<<endl;
    p.setId(id);
    cont++;
}
void Menu::consultaProducto(fstream& mercancia)
{
    string llave;
    cout<<"\t[*CONSULTAR PRODUCTO*]"<<endl
       <<"ID: "; getline(cin,llave);
    recuperar(llave);
}

void Menu::consultaGeneral(fstream& mercancia)
{
}

void Menu::guardar()
{
    ofstream mercancia("mercancia.txt",ios::app);
    if(!mercancia.is_open()){
        cout<<"\t[*ADVERTENCIA*]\nNo se pudo abrir el archivo correctamente"<<endl;
        exit(0);
    }
    mercancia<<p.getId().length()<<p.getId()<<p.getName().length()<<p.getName()<<p.getDescription().length()<<p.getDescription()<<endl;
    mercancia.close();
}

void Menu::recuperar(string llave)
{
}
