#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>


class Phone_List {

	public:

		std::string name = " ";
		std::string number = "";
		
		std::list<std::string> add(std::list<std::string> &list)
		{
			std::cout << "Введите имя: ";
			std::cin >> this->name;
			list.push_back(this->name);
			std::cout << "Введите номер телефона: ";
			std::cin >> this->number;
			list.push_back(this->number);
			return list;
		}

		void search() 
		{

		}

		void remove() 
		{

		}

		void show(std::list<std::string> &list)
		{			
			if (list.empty())
			{
				std::cout << "Лист пуст!";
			}
			else {
				for (auto iter = list.begin(); iter != list.end(); iter++)
				{
					std::cout << *iter << "\t";
				}
			}
		}

		void menue()
		{
			setlocale(LC_ALL, "russian");
			bool close = true;
			Phone_List phone;
			std::list<std::string> list;

			//system("cls");

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
					list = phone.add(list);
					menue();
					break;
				case 2:
					phone.search();
					menue();
					break;
				case 3:
					phone.remove();
					menue();
					break;
				case 4:
					phone.show(list);
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