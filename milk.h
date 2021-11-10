#pragma once
#include "Tovar.h"

class Milk :
	public Tovar
{
private: string Termin_zberiganna;
	   const string type = "Milk product";
public:
	Milk();
	Milk(string name, string vurobnyk, float price, float fat, string Termin_zberiganna_);
	~Milk();

	void setTermin(string NewTermin);
	string getTermin()const;
	
	void show(ostream& obj)const;
	friend ostream& operator << (ostream& out, Milk& obj);
	friend istream& operator >> (istream& in, Milk& obj);
	friend ofstream& operator << (ofstream& file, Milk& obj);
	friend ifstream& operator >> (ifstream& file, Milk& obj);

};