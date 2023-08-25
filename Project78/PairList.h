
#pragma once
#include "Pair.h"
#include <iostream>
#include<vector>

using namespace std;


template<class T>
class PairList : public vector<Pair<T>> {
public:
	//################################################# 
// @par Name 
//    addPair
// @purpose 
//  Adds the Pair to the list. 
// @param [in] : 
//     first, second
// @return 
//     none
// @par References 
//      None 
// @par Notes 
//      None 
//###############################################
	void addPair(T first, T second) {
		this->push_back(Pair<T>(first, second));
	}

	//################################################# 
// @par Name 
//    getFirst
// @purpose 
//   searches on second and returns first
// @param [in] : 
//     seocnd
// @return 
//      retursn first
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	T getFirst(T second) {
		for (int i = 0; i < this->size(); i++) {
			if (this->at(i).getSecond() == second) {
				return this->at(i).getFirst();
			}
		}
	}
	//################################################# 
// @par Name 
//    getSecond
// @purpose 
//   searches on first and returns second
// @param [in] : 
//     first
// @return
//     retruns second
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	
	T getSecond(T first) {
		for (int i = 0; i < this->size(); i++) {
			if (this->at(i).getFirst() == first) {
				return this->at(i).getSecond();
			}
		}
	}
	//################################################# 
// @par Name 
//    deletePair
// @purpose 
//    Deletes the Pair that contains first and second
// @param [in] : 
//     first, second
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	
	void deletePair(T first, T second) {
		int i;
		for (i = 0; i < this->size(); i++) {
			Pair<T> p = this->at(i);
			if (p.getFirst() == first && p.getSecond() == second) {
				break;
			}
		}
		if (i < this->size()) {
			this->erase(this->begin() + i);
		}
	}

	//################################################# 
// @par Name 
//    printList
// @purpose
//   Prints the entire list of Pairs
// @param [in] : 
//     None 
// @return 
//      none 
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void printList() {
		for (int i = 0; i < this->size(); i++) {
			Pair<T> p = this->at(i);
			cout << p.getFirst() << ", " << p.getSecond() << endl;
		}
	}
};
