#pragma once
#ifndef _deque
#define _deque
/*Клас контейнеру  для зберігання всіх об'єктів серед товарів*/

#include "Milk.h"
#include "Sousages.h"



struct Node
{
	Tovar* current;
	Node* next, * prev;
	~Node();
};

class Deque
{
public:
	Deque();
	~Deque();

	Node* get_first_element() const;
	void add_element(Tovar*);
	void remove_first_element();
	void remove_all_elements();
	int show_all() const;
	void sort();
	void save_to_file();
	int load_from_file();
	int do_request(float control_fat);

private:
	Node* first, * last;
};

#endif //!_deque
