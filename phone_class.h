#pragma once
#include "Header.h"

namespace pho {

class Phone_List {

public:

	std::string name = " ";
	std::string number = "";

	std::list<std::string> list;

	void add()
	{
		std::cout << "������� ���: ";
		std::cin >> this->name;
		std::transform(name.begin(), name.end(), name.begin(), tolower);
		list.push_back(this->name);
		std::cout << "������� ����� ��������: ";
		std::cin >> this->number;
		list.push_back(this->number);
	}

	void search()
	{

		int choice = 0;

		std::string searching_name = "";
		std::string searching_number = "";

		std::cout << "�������� ��������:\n";
		std::cout << "1) ����� �� �����\n";
		std::cout << "2) ����� �� ������\n";

		std::cin >> choice;


		switch (choice)
		{
		case 1:
			std::cout << "������� ��� ������� �����: ";
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
					std::cout << "�� ������� ���!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		case 2:
			std::cout << "������� ����� ������� �����: ";
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
					std::cout << "�� ������ �����!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		default:
			std::cout << "������!";
			search();
			break;
		}

	}

	void remove()
	{
		int choice = 0;

		std::string removing_name = "";
		std::string removing_number = "";

		std::cout << "�������� ��������:\n";
		std::cout << "1) ������� �� �����\n";
		std::cout << "2) ������� �� ������\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "������� ��� ������� ������ �������: ";
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
					std::cout << "�� ������� ���!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		case 2:
			std::cout << "������� ����� ������� ������ �������: ";
			std::cin >> removing_number;

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				if (removing_number == *iter)
				{
					list.erase(iter, --iter);
					break;
				}
				else {
					std::cout << "�� ������ �����!";
					break;
				}
			}
			std::cout << std::endl;
			system("pause");
			break;

		default:
			std::cout << "������!";
			remove();
			break;
		}

	}

	void show()
	{
		static int count = 0;
		if (list.empty())
		{
			std::cout << "������ ����!";
		}
		else {
			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				std::cout << ++count << "\n";
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
			std::cout << "�������� ��������:\n";
			std::cout << "1) �������� �������\n";
			std::cout << "2) ����� �������\n";
			std::cout << "3) ������� �������\n";
			std::cout << "4) ���������� ��������\n";
			std::cout << "0) �����\n";
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
				std::cout << "������!\n";
				menue();
				break;
			}

		} while (!close);
	}

};
}

