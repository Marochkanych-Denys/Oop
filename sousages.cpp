#include "Sousages.h"

Sousages::Sousages()
{
}

Sousages::Sousages( string name, string vurobnyk,float price, float fat, string Animals_) :Tovar(name, vurobnyk, price, fat),Animals(Animals_)
{
}
Sousages::~Sousages()
{
}
;

void Sousages::setAnimals(string NewAnimals)
{
	this->Animals = NewAnimals;
};


string Sousages::getAnimals()const 
{
	return this->Animals;
};

void Sousages::show(ostream& obj)const
{
	cout << "Type: ";
	obj << type;
	cout << endl;
	cout << "Name: ";
	obj << name;
	cout << endl;
	cout << "Generator: ";
	obj << vurobnyk;
	cout << endl;	
	cout << "Price: ";
	obj << price;
	cout << endl;
	cout << "Fat: ";
	obj << fat;
	cout << endl;
	cout << "Type of meat: ";
	obj << Animals;
	cout << endl;
	cout << endl;
};

ostream& operator<<(ostream& out, Sousages& obj)
{
	obj.show_all(out);
	return out;
}

istream& operator>>(istream& in, Sousages& obj)
{
	in >> (Tovar&)obj;
	cout << "Expiration date: ";
	in >> obj.Animals;
	return in;
}

ofstream& operator<<(ofstream& file, Sousages& obj)
{
	file << (Tovar&)obj; // Виведення полів базового класу у файл
	file << obj.getAnimals() << "\n";
	return file;
}

ifstream& operator>>(ifstream& file, Sousages& obj)
{
	file >> (Tovar&)obj; // Ввід полів базового класу

	file >> obj.Animals;
	return file;
	
}
