#pragma once
#include<iostream>
#include <string>
#include <sstream>
#include <cmath>

#define TABLE_SIZE 1000

using namespace std;
using std::cout;

template<typename T>
struct Node 
{
	Node<T>* next = nullptr;
	T data;
	Node(T data) : data(data) {}
};

template<typename T>
class Iterator 
{
private:
	Node<T>** table;
	int currentIndex;
	Node<T>* currentNode;

public:
	Iterator(Node<T>** table, int size) : table(table), currentIndex(0), currentNode(nullptr)
	{
		for (int i = 0; i < size; ++i)
		{
			if (table[i] != nullptr)
			{
				currentIndex = i;
				currentNode = table[i];
				break;
			}
		}
	}

	T operator*() const
	{
		return currentNode->data;
	}

	Iterator<T>& operator++()
	{
		currentNode = currentNode->next;
		if (currentNode == nullptr)
		{
			for (int i = currentIndex + 1; i < TABLE_SIZE; ++i)
			{
				if (table[i] != nullptr)
				{
					currentIndex = i;
					currentNode = table[i];
					break;
				}
			}
		}
		return *this;
	}

	bool operator!=(const Iterator<T>& other) const
	{
		return currentNode != other.currentNode;
	}
};

template<typename T>
class Set
{
	Node<T>* table[TABLE_SIZE];

	int hash(T value)
	{
		return abs(value) % TABLE_SIZE;
	}

public:
	Set(const Set& set)
	{
		Node<T>* current = nullptr;
		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			current = set.table[i];
			while (current != nullptr) {
				put(current->data);
				current = current->next;
			}
		}
	}

	Set& operator=(const Set& set)
	{
		Node<T>* current = nullptr;
		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			current = set.table[i];
			while (current != nullptr)
			{
				put(current->data);
				current = current->next;
			}
		}
	}

	Set()
	{
		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			table[i] = nullptr;
		}
	}

	void print(string name)
	{
		cout << name << ":" << endl;
		for (auto element : *this)
		{
			cout << element << " ";
		}
		cout << endl;
	}

	void put(T value)
	{
		int index = hash(value);
		if (table[index] == nullptr)
		{
			table[index] = new Node<T>(value);
			return;
		}

		Node<T>* current = table[index];

		if (current->data == value) return;
		while (current->next != nullptr)
		{
			if (current->data == value) return;
			current = current->next;
		}


		current->next = new Node<T>(value);
	}

	bool empty()
	{
		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != nullptr) return false;
		}

		return true;
	}

	void clear()
	{

		Node<T>* current = nullptr;
		Node<T>* temp = nullptr;

		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			current = table[i];
			while (current != nullptr)
			{
				temp = current;
				current = current->next;
				delete temp;
			}
			table[i] = nullptr;
		}
	}

	bool has(T value)
	{
		Node<T>* current = table[hash(value)];

		while (current != nullptr)
		{
			if (current->data == value) return true;
			current = current->next;
		}

		return false;
	}

	void remove(T data) {
		int index = hash(data);
		Node<T>* current = table[index];
		Node<T>* prev = nullptr;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				if (prev == nullptr)
				{
					table[index] = current->next;
				}
				else
				{
					prev->next = current->next;
				}
				delete current;
				current = nullptr;
				return;
			}
			prev = current;
			current = current->next;
		}
	}

	Set<T> intersection(Set& set)
	{
		Set<T> result;
		Node<T>* current = nullptr;
		for (size_t i = 0; i < TABLE_SIZE; i++)
		{
			current = table[i];
			while (current != nullptr)
			{
				if (set.has(current->data)) result.put(current->data);
				current = current->next;
			}
		}

		return result;
	}

	Iterator<T> begin() { return Iterator<T>(table, TABLE_SIZE); }
	Iterator<T> end() { return Iterator<T>(nullptr, 0); }

	template<typename U>
	friend ostream& operator<<(ostream& out, const Set<U>& set);
};

template<typename U>
ostream& operator<<(ostream& out, const Set<U>& set)
{
	Node<U>* current = nullptr;
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		current = set.table[i];
		while (current != nullptr)
		{
			out << current->data << " ";
			current = current->next;
		}
	}

	return out;
}

template<>
int Set<string>::hash(string value)
{
	int sum = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		sum += value[i];
	}

	return sum % TABLE_SIZE;
}

template<>
int Set<const char*>::hash(const char* value)
{
	int sum = 0;
	for (size_t i = 0; i < strlen(value); i++)
	{
		sum += value[i];
	}

	return sum % TABLE_SIZE;
}

template<>
int Set<double>::hash(double value)
{
	return abs((int)value) % TABLE_SIZE;
}