

#include "HashTable.h"
#include <fstream>
#include <string>

int main() {
	HashTable hashTable;
	ifstream ifs("text.txt");
	string mname, phone, tmp;
	int choice;
	while (!ifs.eof()) {
		getline(ifs, mname, ';');
		getline(ifs, tmp, ' ');
		getline(ifs, phone, ';');
		getline(ifs, tmp);
		hashTable.add(mname, phone);
	}
	ifs.close();

	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Print the hash table" << endl;
		cout << "2. Look up a name" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1: hashTable.printTable();
			break;
		case 2: cout << "Enter name: ";
			cin >> mname;
			phone = hashTable.lookup(mname);
			if (phone.empty())
				cout << "No Name Found" << endl;
			else
				cout << phone << endl;
			break;
		case 3:	return 0;
		default: cout << "Invalid choice. Please try again." << endl;
		}
	}
	return 0;
}