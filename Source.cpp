#include<iostream>
#include <string>
#include <sstream>
#include<cmath>
#include "Set.h"
#include "menu.h"

using namespace std;

void manage_sets(const string& type);
void create_int_sets();
void create_double_sets();
void create_string_sets();


int main() 
{

	string type;

	cout << "Enter type (int, double or string): ";
	cin >> type;
	manage_sets(type);

	return 0;
}

void manage_sets(const string& type)
{
	if (type == "int")
	{
		create_int_sets();
	}
	else if (type == "string")
	{
		create_string_sets();
	}
	else if (type == "double")
	{
		create_double_sets();
	}
	else
	{
		cout << "Oops. Other types aren't included in this test program yet :)" << endl;
	}

}

void create_int_sets()
{
	char flag;
	string str;
	cout << "Let's create 2 sets:" << endl;
	Set<int> set1;
	Set<int> set2;
	int number;
	cout << "Do you wanna add some elements to the set (y/n)? "; cin >> flag; cin.ignore();
	if (flag == 'y' || flag == 'Y')
	{
		cout << "Enter first set elements: "; getline(cin, str);
		stringstream ss(str);
		while (ss >> number)
		{
			set1.put(number);
		}
		set1.print("set1");

		cout << "Enter second set elements: "; getline(cin, str);
		ss = stringstream(str);

		while (ss >> number)
		{
			set2.put(number);
		}
		set2.print("set2");
	}
	else
	{
		set1.put(4);
		set1.put(2);
		set1.put(3);
		set1.put(666);
		set1.put(3);
		set2.put(2);
		set2.put(3);
		set2.put(228);
		set2.put(1337);
		set2.put(666);

		set1.print("set1");
		set2.print("set2");
	}
	menu(set1, set2);
}

void create_double_sets()
{
	char flag;
	string str;
	cout << "Let's create 2 sets:" << endl;
	double number;
	Set<double> set1;
	Set<double> set2;

	cout << "Do you wanna add some elements to the set (y/n)? "; cin >> flag; cin.ignore();
	if (flag == 'y' || flag == 'Y')
	{
		cout << "Enter first set elements: "; getline(cin, str);
		stringstream ss(str);
		while (ss >> number)
		{
			set1.put(number);
		}
		set1.print("set1");

		cout << "Enter second set elements: "; getline(cin, str);
		ss = stringstream(str);

		while (ss >> number)
		{
			set2.put(number);
		}
		set2.print("set2");
	}
	else
	{
		set1.put(55.2);
		set1.put(71.9);
		set1.put(3.3);
		set1.put(3.3);
		set2.put(55.2);
		set2.put(71.9);
		set2.put(100);
		set2.put(228.6);

		set1.print("set1");
		set2.print("set2");
	}

	menu(set1, set2);
}

void create_string_sets()
{
	char flag;
	string str;
	cout << "Let's create 2 sets:" << endl;
	Set<string> set1;
	Set<string> set2;

	cout << "Do you wanna add some elements to the set (y/n)? "; cin >> flag; cin.ignore();
	if (flag == 'y' || flag == 'Y')
	{
		cout << "Enter first set elements (enter \"stop\" to stop entering):" << endl;
		getline(cin, str);
		for (int i = 0; str != "stop"; i++)
		{
			set1.put(str);
			cout << i + 1 << ". "; getline(cin, str);
		}
		set1.print("set1");

		cout << "Enter second set elements (enter \"stop\" to stop entering):" << endl;
		getline(cin, str);
		for (int i = 0; str != "stop"; i++)
		{
			set2.put(str);
			cout << i + 1 << ". "; getline(cin, str);
		}
		set2.print("set2");
	}
	else
	{
		set1.put("kshkf");
		set1.put("gslkfjglk");
		set1.put("853925798");
		set1.put("abcdefg");
		set2.put("853925798");
		set2.put("test123");
		set2.put("abcdefg");

		set1.print("set1");
		set2.print("set2");
	}
	menu(set1, set2);
}
