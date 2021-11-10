#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Tovar {
protected:
	string name, vurobnyk;
	float price=0.0, fat=0.0;
public:
	Tovar() {};
	Tovar(string name, string vurobnyk,	float price, float fat);
	virtual ~Tovar();

	void setName(string NewName);
	string getName()const;

	void setVurobnyk(string NewVurobnyk);
	string getVurobnyk()const;

	void setPrice(float NewPrice);
	float getPrice()const;

	void setFat(float NewFat);
	float getFat()const;

	void show_all(ostream& obj)const;
	virtual void show(ostream& obj)const=0;
	friend ostream& operator << (ostream& out, Tovar& obj);
	friend istream& operator >> (istream& in, Tovar& obj);
	friend ofstream& operator << (ofstream& file, Tovar& obj);
	friend ifstream& operator >> (ifstream& file, Tovar& obj);


};