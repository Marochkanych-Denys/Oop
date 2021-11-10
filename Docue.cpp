#include "Doque.h"




Node::~Node()
{
	delete current;
}

Deque::Deque() : first(nullptr), last(nullptr) {}


Deque::~Deque()
{
	this->remove_all_elements();	//видалення всіх товарів для звільнення пам'яти
}


Node* Deque::get_first_element() const
{
	return first;
}


void Deque::add_element(Tovar* newElement)
{	
		
	Node* newel = new Node;
	newel->current = newElement;

	if (first == nullptr)
	{
		first = last = newel;
		newel->next = newel->prev = nullptr;
	}
	else
	{
		if (typeid(*newElement) == typeid(Milk))

		{
			newel->prev = nullptr;
			newel->next = first;
			first->prev = newel;
			first = newel;
		}
		else if (typeid(*newElement) == typeid(Sousages))

		{
			newel->next = nullptr;
			newel->prev = last;
			last->next = newel;
			last = newel;
		}
	}
	
}


void Deque::remove_first_element()
{
	if (first != nullptr)
	{
		if (first == last)
		{
			delete first;
			first = last = nullptr;
		}
		else					
		{
			first->next->prev = nullptr;
			first = first->next;
			delete first->prev;
		}
		
	}
	else {
		cout << "\nDeque is empty.\n";
	}
}


void Deque::remove_all_elements()
{
	if (first != nullptr)
	{
		while (first)
		{
			this->remove_first_element();
		}
		cout << "\nAll elements was deleted.\n";
	}
	else {
		cout << "\nDeque is empty.\n";
	}
	
}


int Deque::show_all() const
{
	Node* tempel = first;
	
	if (tempel != nullptr)
	{
		tempel->current->show(cout);
		tempel = tempel->next;
		return 1;
	}
	else { return 0; }
		
	
	
}


void Deque::sort()
{
	// перевірка для неявного виклику сортування з функції виконання запиту 
	if (first != nullptr)
	{
		//змінна, що відповідає за перестановку товарів у деку
		bool swapping;

		// Сортування бульбашкою
		do
		{
			swapping = false;
			for (Node* temp = first; temp->next; temp = temp->next)
			{
				// Жирність наступного продукту меша ніж у попереднього
				if (temp->next->current->getFat() < temp->current->getFat())
				{
					// Змінити покажчики на продукти
					Tovar* temp_element = temp->current;
					temp->current = temp->next->current;
					temp->next->current = temp_element;
					// Позначити виконання перестановки
					swapping = true;
				}
			}
			//Продовжити поки є перестановки
		} while (swapping);
	}
}

//--------------------------------------------------------------------------------------------
//метод, що зберігає всі товари у файл
void Deque::save_to_file()
{
	if (first == nullptr)
		cout << "\nDeque is empty.\n";
	else
	{
		ofstream out("DATA.dat",ofstream::app);

		if (!out.is_open()) //Перевірка можливості роботи з файлом
		{
			cout << "Error opening file!" << endl;
			return;
		}
		Node* tmp=  first;
		while (first != nullptr)
		{
			if (typeid(*(first->current)) == typeid(Milk))
			{
				out << "Milk product: ";
				out << (*((Milk*)(first->current)));
			}
			if (typeid(*(first->current)) == typeid(Sousages))
			{
				out << "Sousage product: ";
				out << (*((Sousages*)(first->current)));
			}
			first = first->next;
			out << "\n";
		}
		out.close();
		cout << "Data is in file!" << endl;
		first = tmp;
	}
	return;
}




//-------------------------------------------------------------------------------------------
//метод, що завантажує всі об'єкти з файлу
//й повертає кількість завантажених об'єктів
int Deque::load_from_file()
{
	ifstream in;
	int n = 0;

	in.open("DATA.dat");

	if (!in.is_open()) //Перевірка можливості роботи з файлом
	{
		cout << "Error opening file!" << endl;
		return n;
	}

	Milk* milk_goods;
	Sousages* Sousage_goods;

	string k,j;
	while (!in.eof())
	{
		in >> k;
		in >> j;
		if (k + " " + j == "Milk product:")
		{
			milk_goods = new Milk();
			in >> *milk_goods;
			if (milk_goods->getName() != "") {
				this->add_element(milk_goods);
				n += 1;
			}
		}
		else if (k + " " + j == "Sousage product:")
		{
			Sousage_goods = new Sousages();
			in >> *Sousage_goods;
			if (Sousage_goods->getName() != "") {
				this->add_element(Sousage_goods);
				n += 1;
			}
		}
		else 
			break;

	}
	in.close();
	
	
	return n;

}



//--------------------------------------------------------------------------------------------
//метод, що виконує запит 
int Deque::do_request(float control_fat)
{
	//Лічильник продуктів, що відповідають запиту
	int n = 0;

	//сортувати дек 
	this->sort();

	Node* current_element = first;								//поточний елемент = 1ий елемент
	while (current_element != nullptr &&				//поки поточний елемент не 
//нульовий
	current_element->current->getFat() <= control_fat)	//і його жирність менше 
// контрольної
	{
		current_element->current->show(cout);			//вывести на екран елемент
		n++;
		current_element = current_element->next;			//і перейти до наступного 
//елементу
	}

	return n;								//повернути кількість елементів, що задовольняють умову											

}
