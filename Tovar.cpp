#include "Tovar.h"


Tovar::Tovar(string _name, string _vurobnyk,float _price, float _fat):
	name(_name),vurobnyk(_vurobnyk),price(_price),fat(_fat) 
{
}

Tovar::~Tovar()
{
}
void Tovar::setName(string NewName) {
	this->name = NewName;
};

string Tovar::getName()const {
	return this->name;
};

void Tovar::setVurobnyk(string NewVurobnyk) {
	this->vurobnyk = NewVurobnyk;
};

string Tovar::getVurobnyk()const {
	return this->vurobnyk;
};
void Tovar::setPrice(float NewPrice)
{
	this->price = NewPrice;
};

float Tovar::getPrice()const 
{
	return this->price;
};

void Tovar::setFat(float NewFat) 
{
	this->fat = NewFat;
};
float Tovar::getFat()const 
{
	return this->fat;
}
void Tovar::show_all(ostream& obj) const
{
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
};

ostream& operator <<(ostream& out, Tovar& obj)
{
	obj.show_all(out);
	return out;
}

istream& operator >>(istream& in, Tovar& obj)
{
	in.ignore(32767, '\n');
	cout << "Enter the name of the product:" << endl;
	cout << "Name: ";
	getline(in, obj.name);
	cout << "Generator: ";
	getline(in, obj.vurobnyk);
	cout << "Price: ";
	in >> obj.price;
	cout << "Fat: ";
	in >> obj.fat;
	return in;

}


ofstream& operator <<(ofstream& file, Tovar& obj)
{
	file << obj.getName() << "\n" << obj.getVurobnyk() << "\n" << obj.getPrice()
		 << "\n" << obj.getFat() << "\n";
	return file;
}

ifstream& operator>>(ifstream& file, Tovar& obj)
{
	getline(file, obj.name);
	getline(file, obj.vurobnyk);
	file >> obj.price;
	file >> obj.fat;
	
	return file;
}
