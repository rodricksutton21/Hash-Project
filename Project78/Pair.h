
#pragma once

template<class T>
class Pair {
private:
	
	T F;
	T S;

public:
	//################################################# 
// @par Name 
//    Pair
// @purpose 
//    Constructor that takes in two parameters 
// @param [in] : 
//     T F, T S
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	Pair(T F, T S) {
		this->F = F;
		this->S = S;
	}

	//################################################# 
// @par Name 
//    getFirst
// @purpose 
//     This is an accessor method that will return the first of the pair values.
// @param [in] : 
//     None 
// @return 
//      returns first
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	T getFirst() {
		return F;
	}

	//################################################# 
// @par Name 
//    getSecond
// @purpose 
//     This is an accessor method that will return the second of the pair values.
// @param [in] : 
//     None 
// @return 
//      retruns second
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	T getSecond() {
		return S;
	}
	//################################################# 
// @par Name 
//    setFirst
// @purpose 
//   This is a mutator method that will set the first pair value
// @param [in] : 
//     T F
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	
	void setFirst(T F) {
		this->F = F;
	}
	//################################################# 
// @par Name 
//   setSecond
// @purpose 
//    This is a mutator method that will set the second pair value
// @param [in] : 
//     T S
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	
	void setSecond(T S) {
		this->S = S;
	}
};
