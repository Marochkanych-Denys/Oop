#include "Menu.h"



Menu::Menu()
{
}

Menu::~Menu()
{
	delete conteiner;
}

Menu& Menu::create()
{
	static Menu _menu;
	return _menu;

}

void Menu::run()
{
	int i = 0;
	int menu_choise = 0;
	int choise_to_cont = 1;
	
	
	while (choise_to_cont==1) {
		cout << "--------------- Menu ---------------" << endl
			<< "<1> Create Milk's object                " << endl
			<< "<2> Create Sausage's object             " << endl
			<< "<3> Show the list of goods              " << endl
			<< "<4> Delete first element                " << endl
			<< "<5> Delete all elsements                " << endl
			<< "<6> Save to the file                    " << endl
			<< "<7> Load from the file                  " << endl
			<< "<8> Sort elements                       " << endl
			<< "<9> Request                             " << endl
			<< "<10> Exit                                " << endl;
		cin >> menu_choise;
		switch (menu_choise)
		{
		case 1: {
			create_milk();
			break;
		}

		case 2: {
			create_sousages();
			break;
		}

		case 3: {
			show();
			break;
		}

		case 4: {
			delete_first_elements();
			break;
		}

		case 5: {
			delete_all_elements();
			break;
		}

		case 6: {
			conteiner->save_to_file();
			break;
		}

		case 7: {
			int count = conteiner->load_from_file();
			if (count != 0) {
				cout << "Loaded " << count << " goods.\n";
			}
			else
				cout << "File  is empty.\n";
			break;
		}

		case 8: {
			sort();
			break;
		}

		case 9: {
			request();
			break;
		}
		case 10: {
			exit(1);
			break;
		}

		default:
			cout << "Incorect choise. Try again\n";
			break;
		}
		cout << "Continue?(1/0)";
		cin >> choise_to_cont;
		while (choise_to_cont != 1 && choise_to_cont != 0) {
			cout << "Incorect choise. Try agein <1>/<0>:";
			cin >> choise_to_cont;
		}
		

	}
}

void Menu::create_milk()
{
	cout << "\n<------ Creating Milk Product ------>\n\n";

	
	Milk *new_milk = new Milk();
	
	cin >> *new_milk;
	if (cin.fail()) {
		cin.clear();			
		cin.ignore(20, '\n');
		cout << "\n\n#####Error while inputting.######\n";

		delete new_milk;
		
		create_milk();
		return;

	}

	

	conteiner->add_element(new_milk);	//додати у дек, якщо не сталось помилки
	cout << "\nMilk goods created\n";

}

void Menu::create_sousages()
{
	cout << "\n<------ Creating Sausage Product ------>\n\n";

	//створити загальний ковбасний продукт 
	Sousages* new_sausage = new Sousages("", "", 0, 0, "");

	//ввести з консолі
	cin >> *new_sausage;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(20, '\n');
		cout << "\n\n#####Error while inputting.######\n";

		delete new_sausage;

		create_sousages();
		return;

	}
	if (cin.fail())					//помилка вводу
	{
		cin.clear();			
		cin.ignore(20, '\n');	
		system("cls");
		delete new_sausage;	     
		return;
	}

	conteiner->add_element(new_sausage);//додати у дек, якщо не сталось помилки
	cout << "\nSausage product created\n";

}

void Menu::show()
{
	Node* front_element = conteiner->get_first_element();
	if (front_element)					  
		conteiner->show_all();
 
	else
		cout << "Deque is empty.\n";

}

void Menu::delete_first_elements()
{
	int s = 0;
	cout << "Are you sure? <1>/<0> ";				
	cin >> s;					
								
	if (cin.fail())										
	{
		cin.clear();
		cin.ignore(256, '\n');
		s = 0;
	}
	else if (s==1)					
	{
		conteiner->remove_first_element();
		cout << "\nFirst element was deleted.\n";
	}
	else 					//відміна операції
	{
		cout << "Canceled.\n";
	}
	
}

void Menu::delete_all_elements()
{
	int s = 0;
	cout << "Are you sure? <1>/<0> ";
	cin >> s;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		s = 0;
	}
	else if (s==1)
	{
		conteiner->remove_all_elements();
	}
	else 					//відміна операції
	{
		cout << "Canceled.\n";
	}
	

}



void Menu::sort()
{
	Node* first_element = conteiner->get_first_element();
	if (first_element == nullptr)				
		cout << "\nDeque is empty.\n";
	else if (first_element->next != nullptr) {	
		conteiner->sort();
		cout << "\nDeque has been sorted.\n";
	}
	

}

void Menu::request()
{
	float control_fat;
	cout << "\nEnter fat to see all products with a lower indicator (in %).\n";
	cin >> control_fat;				//вводиться контральна жирність у %
	if (cin.fail() || control_fat > 100 || control_fat < 0)	//помилка вводу або жирність більша 100
	{
		cin.clear();			//виправити помилку 
		cin.ignore(20, '\n');	//ігнорувати всі символи в кінці рядка
		cout << "\n#####Error while inputting.######\n";
	}
	else
	{
		int ctr = conteiner->do_request(control_fat);	//пошук товарів що 
													//задовольняють умову
		
		cout << endl << ctr << " goods have been found.\n";
	}

}
