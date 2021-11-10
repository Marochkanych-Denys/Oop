#pragma once
#include "Tovar.h"

class Sousages :
	public Tovar 
{
private:
	string Animals;
	const string type = "Sousage product";
public:
	Sousages();
	Sousages(string name, string vurobnyk, float price, float fat, string Animals_);
	~Sousages();
	void setAnimals(string NewAnimals);
	string getAnimals()const;
	void show(ostream& obj)const;
	
	friend ostream& operator << (ostream& out, Sousages& obj);
	friend istream& operator >> (istream& in, Sousages& obj);
	friend ofstream& operator << (ofstream& file, Sousages& obj);
	friend ifstream& operator >> (ifstream& file, Sousages& obj);

};