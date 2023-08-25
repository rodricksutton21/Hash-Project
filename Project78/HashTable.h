

#pragma once
#include "PairList.h"
#include <sstream>

class HashTable {
private:
	vector<PairList<string>> table;
	//################################################# 
// @par Name 
//    hash
// @purpose 
//    to set hash length
// @param [in] : 
//     str
// @return 
//      returns hash
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	unsigned long hash(string str) {
		unsigned long hash = 5381;
		

		for (int i = 0; i < str.length(); i++)
			hash = ((hash << 5) + hash) + str[i];

		return hash;
	}

public:
	//################################################# 
// @par Name 
//    HashTbale
// @purpose 
//    Default contructor
// @param [in] : 
//     None 
// @return 
//     none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	HashTable() {
		for (int i = 0; i < 53; i++)
			table.push_back(PairList<string>());
	}
	//################################################# 
// @par Name 
//    add
// @purpose 
//    Adds the name and number to the hash table
// @param [in] : 
//     name, number
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void add(string name, string number) {
		int h = hash(name) % 53;
		for (int i = 0; i < table[h].size(); i++) {
			if (table[h][i].getFirst() == name)
				return;
		}
		table[h].addPair(name, number);
	}
	//################################################# 
// @par Name 
//    printtable
// @purpose 
//   prints out the entire table and should show the hashed location of each Pair in the table.  
// @param [in] : 
//     None 
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void printTable() {
		for (int i = 0; i < table.size(); i++) {
			for (int j = 0; j < table[i].size(); j++) {
				string name = table[i][j].getFirst(), phone = table[i][j].getSecond();
				cout << name << " (" << hash(name) % 53 << " - " << j << ") " << phone << endl;
			}
		}
	}
	//################################################# 
// @par Name 
//   lookup
// @purpose 
//    returns a formatted string that contains the data to be output
// @param [in] : 
//     name
// @return 
//      returns data
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	string lookup(string name) {
		int h = hash(name) % 53;
		for (int i = 0; i < table[h].size(); i++) {
			string mgam = table[h][i].getFirst(), phone = table[h][i].getSecond();
			if (mgam == name) {
				stringstream ss;
				ss << mgam << " (" << hash(mgam) % 53 << " - " << i << ") " << phone;
				return ss.str();
			}
		}
		return "";
	}
};