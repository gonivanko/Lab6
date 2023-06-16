#pragma once
#include "Set.h"

template<typename T>
void menu(Set<T>& set1, Set<T>& set2)
{
	bool running = true;
	int choice;
	string set_name, str;
	T element;
	while (running)
	{
		cout << "Menu:" << endl;
		cout << "1 [set_name]: Check if set is empty" << endl;
		cout << "2 [set_name]: Check if set has element" << endl;
		cout << "3 [set_name]: Add element" << endl;
		cout << "4 [set_name]: Remove element" << endl;
		cout << "5 [set_name]: Print set" << endl;
		cout << "6: Intersect sets" << endl;
		cout << "7: Exit" << endl;

		getline(cin, str);
		stringstream str_stream(str);
		str_stream >> choice >> set_name;

		switch (choice)
		{
		case 1:
			if (set_name == "set1" || set_name == "Set1")
			{
				cout << set_name << " is empty: " << boolalpha << set1.empty() << endl;
			}
			else if (set_name == "set2" || set_name == "Set2")
			{
				cout << set_name << " is empty: " << boolalpha << set2.empty() << endl;
			}
			else
			{
				cout << "Set1 is empty: " << boolalpha << set1.empty() << endl;
				cout << "Set2 is empty: " << boolalpha << set2.empty() << endl;
			}
			break;

		case 2:
			cout << "Enter element: "; cin >> element; cin.ignore();

			if (set_name == "set1" || set_name == "Set1")
			{
				cout << set_name << " has element " << element << ": " << boolalpha << set1.has(element) << endl;
			}
			else if (set_name == "set2" || set_name == "Set2")
			{
				cout << set_name << " has element " << element << ": " << boolalpha << set2.has(element) << endl;
			}
			else
			{
				cout << "Set1 has element " << element << ": " << boolalpha << set1.has(element) << endl;
				cout << "Set2 has element " << element << ": " << boolalpha << set2.has(element) << endl;
			}
			break;

		case 3:
			cout << "Enter element: "; cin >> element; cin.ignore();

			if (set_name == "set1" || set_name == "Set1")
			{
				set1.put(element);
				cout << element << " has been added successfully to set1" << endl;
			}
			else if (set_name == "set2" || set_name == "Set2")
			{
				set2.put(element);
				cout << element << " has been added successfully to set2" << endl;
			}
			else cout << "No set has been chosen from set1 or set2";

			break;

		case 4:
			cout << "Enter element: "; cin >> element; cin.ignore();

			if (set_name == "set1" || set_name == "Set1")
			{
				if (set1.has(element))
				{
					set1.remove(element);
					cout << element << " has been removed succesfully from set1" << endl;
				}
				else cout << "No such element in set1" << endl;
			}
			else if (set_name == "set2" || set_name == "Set2")
			{
				if (set2.has(element))
				{
					set2.remove(element);
					cout << element << " has been removed succesfully from set2" << endl;
				}

				else cout << "No such element in set2" << endl;
			}
			else cout << "No set has been chosen from set1 or set2";

			break;

		case 5:
			if (set_name == "set1" || set_name == "Set1") set1.print("set1");

			else if (set_name == "set2" || set_name == "Set2") set2.print("set2");

			else
			{
				set1.print("set1");
				set2.print("set2");
			}
			break;
		case 6:
			cout << "Intersection: " << set1.intersection(set2) << endl;
			break;

		case 7:
			running = false;
			break;
		}

	}
}
