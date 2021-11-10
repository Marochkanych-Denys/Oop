#include "milk.h"


Milk::Milk()
{
}

Milk::Milk(string name, string vurobnyk, float price, float fat, string Termin_zberiganna_):Tovar( name, vurobnyk, price, fat),Termin_zberiganna(Termin_zberiganna_)
{
}

Milk::~Milk()
{
}

void Milk::setTermin(string NewTermin)
{
	this->Termin_zberiganna = NewTermin;
}

string Milk::getTermin()const
{
	return this->Termin_zberiganna;
};

void Milk::show(ostream& obj)const
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
	cout << "Expiration date: ";
	obj << Termin_zberiganna;
	cout << endl;
	cout << endl;
	
};

ostream& operator<<(ostream& out, Milk& obj)
{
	obj.show(out);
	return out;
}

istream& operator>>(istream& in, Milk& obj)
{
	in >> (Tovar&)obj;
	cout << "Expiration date: ";
	in >> obj.Termin_zberiganna;
	return in;
	
}

ofstream& operator<<(ofstream& file, Milk& obj)
{
	file << (Tovar&)obj; // Виведення полів базового класу у файл
	file << obj.getTermin() << "\n" ;
	return file;
	// TODO: insert return statement here
}

ifstream& operator>>(ifstream& file, Milk& obj)
{
	
	file >> (Tovar&)obj; // Ввід полів базового класу
	file >> obj.Termin_zberiganna;
	string s;
	getline(file, s);
	return file;
	
}


