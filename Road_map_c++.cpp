#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <algorithm>


class Phone_List {

public:

	std::string name = " ";
	std::string number = "";

	std::list<std::string> list;

	void add()
	{
		std::cout << "Введите имя: ";
		std::cin >> this->name;
		std::transform(name.begin(), name.end(), name.begin(), tolower);
		list.push_back(this->name);
		std::cout << "Введите номер телефона: ";
		std::cin >> this->number;
		list.push_back(this->number);		
	}

	void search()
	{

		int choice = 0;

		std::string searching_name = "";
		std::string searching_number = "";

		std::cout << "Выберите действие:\n";
		std::cout << "1) Поиск по имени\n";
		std::cout << "2) Поиск по номеру\n";
		
		std::cin >> choice;
		

		switch (choice)
		{
			case 1:
				std::cout << "Введите имя которое ищите: ";
				std::cin >> searching_name;
				std::transform(searching_name.begin(), searching_name.end(), searching_name.begin(), tolower);

				for (auto iter = list.begin(); iter != list.end(); iter++)
				{
					if (searching_name == *iter)
					{
						std::cout << *iter;
						std::cout << " ";
						std::cout << *++iter;
						break;
					}
					else {
						std::cout << "Не найдено имя!";
						break;
					}
				}
				std::cout << std::endl;
				system("pause");
				break;

			case 2:				
				std::cout << "Введите номер который ищите: ";
				std::cin >> searching_number;

				for (auto iter = list.begin(); iter != list.end(); iter++)
				{
					if (searching_number == *iter)
					{
						std::cout << *iter;
						std::cout << " ";
						std::cout << *--iter;
						break;
					}
					else {
						std::cout << "Не найден номер!";
						break;
					}
				}
				std::cout << std::endl;
				system("pause");
				break;

			default:
				std::cout << "Ошибка!";
				search();
				break;
		}
			
	}

	void remove()
	{
		int choice = 0;

		std::string removing_name = "";
		std::string removing_number = "";

		std::cout << "Выберите действие:\n";
		std::cout << "1) Удалить по имени\n";
		std::cout << "2) Удалить по номеру\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "Введите имя которое хотите удалить: ";
			std::cin >> removing_name;
			std::transform(removing_name.begin(), removing_name.end(), removing_name.begin(), tolower);

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				if (removing_name == *iter)
				{
					list.erase(iter);

					break;
				}
				else {
					std::cout << "Не найдено имя!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		case 2:
			std::cout << "Введите номер который хотите удалить: ";
			std::cin >> removing_number;

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				if (removing_number == *iter)
				{
					list.erase(iter, --iter);
					break;
				}
				else {
					std::cout << "Не найден номер!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		default:
			std::cout << "Ошибка!";
			remove();
			break;
		}

	}

	void show()
	{
		if (list.empty())
		{
			std::cout << "Список пуст!";
		}
		else {
			for (auto iter = list.begin(); iter != list.end(); iter++)
			{				
				std::cout << *iter << "\t";
				std::cout << "\n";
			}
		}
		system("pause");
	}

	void menue()
	{
		setlocale(LC_ALL, "russian");
		bool close = true;		
		
		system("cls");

		do
		{
			int choice = 0;
			std::cout << "Выберите действие:\n";
			std::cout << "1) Добавить контакт\n";
			std::cout << "2) Найти контакт\n";
			std::cout << "3) Удалить контакт\n";
			std::cout << "4) Отобразить контакты\n";
			std::cout << "0) Выйти\n";
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				add();
				menue();
				break;
			case 2:
				search();
				menue();
				break;
			case 3:
				remove();
				menue();
				break;
			case 4:
				show();
				menue();
				break;
			case 0:
				choice = false;
				break;


			default:
				std::cout << "Ошибка!\n";
				menue();
				break;
			}

		} while (!close);
	}

};


int main()
{
	Phone_List phone;
	phone.menue();
	return 0;
}