#pragma once

#include <iomanip>
#include <iostream>
#include <string>

class Producto
{
public:
	Producto();

	std::string getName() const;
	void setName(const std::string &value);

	std::string getDescription() const;
	void setDescription(const std::string &value);

	std::string getId() const;
	void setId(const std::string &value);

	int getIdInt() const;

	friend std::istream &operator>>(std::istream &in, Producto &p);
	friend std::ostream &operator<<(std::ostream& os, Producto& p);

	std::string toString() const;

private:
	std::string name;
	std::string description;
	std::string id;
};

