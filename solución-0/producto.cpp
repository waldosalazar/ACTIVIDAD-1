#include "producto.h"

Producto::Producto()
{
}

string Producto::getName() const
{
    return name;
}

void Producto::setName(const string &value)
{
    strcpy(name, value.c_str());
}

string Producto::getDescription() const
{
    return description;
}

void Producto::setDescription(const string &value)
{
    strcpy(description,value.c_str());
}

string Producto::getId() const
{
    return id;
}

void Producto::setId(const string &value)
{
    strcpy(id,value.c_str());
}

string Producto::getOption() const
{
    return option;
}

void Producto::setOption(const string &value)
{
    strcpy(option,value.c_str());
}

ostream& operator<<(ostream& os,Producto& p)
{
    os<<"ID: "<<p.getId()<<endl
     <<"Nombre: "<<p.getName()<<endl
    <<"Descripcion: "<<p.getDescription()<<endl;

    return os;
}
