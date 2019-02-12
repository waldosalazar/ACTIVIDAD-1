#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Producto
{
public:
    Producto();

    string getName() const;
    void setName(const string &value);

    string getDescription() const;
    void setDescription(const string &value);

    string getId() const;
    void setId(const string &value);

    string getOption() const;
    void setOption(const string &value);

    friend ostream& operator <<(ostream& os,Producto& p);

private:
    char name[100];
    char description[100];
    char id[100];
    char option[100];

};

#endif // PRODUCTO_H
