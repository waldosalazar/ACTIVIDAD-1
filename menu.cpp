#include "menu.h"

Menu::Menu()
{

}

void Menu::menu()
{
    string op;
    while (true) {
        cout<<"1) Alta de producto"<<endl
           <<"2) Consulta"<<endl
          <<"3) Salir"<<endl
         <<">> "; getline(cin,op);
        if(op=="1"){
            altaProducto();
        }
        else if(op=="2"){
            consultaProducto();
        }
        else if(op=="3"){
            break;
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
    p.setId("hola");
    //generarID();
    cout<<endl<<endl<<p;
    guardar();
}
void Menu::generarID(){
    char id[15];
    p.getName().copy(id,2);
    strcat(id,"-");
    p.setId(id);
}
void Menu::consultaProducto()
{
    string llave;
    cout<<"\t[*CONSULTAR PRODUCTO*]"<<endl
       <<"ID: "; getline(cin,llave);
    recuperar(llave);
}
void Menu::guardar()
{
    char frase[30];
    ofstream mercancia("mercancia.txt",ios::app);
    if(!mercancia.is_open()){
        cout<<"\t[*ADVERTENCIA*]\nNo se pudo abrir el archivo correctamente"<<endl;
        exit(0);
    }
    mercancia<<strlen(strcpy(frase,p.getId().c_str()))<<p.getId()<<strlen(strcpy(frase,p.getName().c_str()))<<p.getName()<<strlen(strcpy(frase,p.getDescription().c_str()))<<p.getDescription()<<endl;
    mercancia.close();
}
void Menu::recuperar(string llave)
{
    string palabra;
    cout<<"Fuera de while"<<endl;
    ifstream mercancia("mercancia.txt",ios::in);
    while(!mercancia.eof()){
    cout<<"ENTRO"<<endl;
        getline(mercancia,palabra);
        cout<<palabra;
        p.setId(palabra);
        getline(mercancia,palabra);
        p.setName(palabra);
        getline(mercancia,palabra);
        p.setDescription(palabra);
        if(p.getId()==llave)
            cout<<p;
    }

}
