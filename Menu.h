#pragma once
#include "Doque.h"

class Menu
{
public:
	static Menu& create();
	~Menu();

	void run();

	void create_milk();
	void create_sousages();
	void show();
	void delete_first_elements();
	void delete_all_elements();
	void sort();
	void request();

protected:
	Menu();
	Deque* conteiner = new Deque;
};
