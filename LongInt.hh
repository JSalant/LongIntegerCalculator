/*****************************************************************
Jeremy Salant
cs435
Semester Project Part 1
3/31/2014

LongInt.hh
- creates the LongInt class using DLList
*****************************************************************/

#include "DLList.hh"
#include <iostream> //for cout statements during testing
#include <cstdlib> //for atoi function
#include <sstream> //for int to string conversion
#include <math.h>
using namespace std;

class LongInt{
	public:
		DLList L;
		bool sign; //is true if negative, false if positive
		int numDigits;

		//initializes empty LongInt
		LongInt();
		//Initialize LongInt to string s
		LongInt(string);
		//Project step 2 - added destructor
		~LongInt();
		//Initialize LongInt to string s
		void INITIALIZE(string);
		//Return the sign of the LongInt
		bool GETSIGN();
		//Set the sign of the LongInt
		void SETSIGN(char);
		//Return digit count of LongInt
		int GETDIGITCOUNT();
		//Print the LongInt
		void PRINT();
		//Check if LongInt is greater than given one
		bool GREATERTHAN(LongInt*);
		//Check if LongInt is less than given one
		bool LESSTHAN(LongInt*);
		//Check if LongInt is equal to given one
		bool EQUALTO(LongInt*);
		//As per specification, checks if int has more than 4 digits
		//if it does return those, otherwise return 0
		//T is modified to be only 4 digits long
		int OVER_FLOW(int&);
		//As per specification, returns the number of digits in an int
		int DIGIT(int);
		//set one long int equal to another, needed for binary math operations
		LongInt& operator=(LongInt&);
		//add two long int numbers and return the sum
		LongInt& operator+(LongInt&);
		//subtract two long int numbers and return the difference
		LongInt& operator-(LongInt&);
		//multiply two long int numbers and return product
		LongInt& operator*(LongInt&);
		//use argument power as exponent to raise the current long int to that power
		LongInt& operator^(int power);
		//divide two long ints and return the result
		LongInt& operator/(LongInt&);
		//grab first most significant digit from passed LongInt
		int RETURN1();
		//grab first 2 most significant digits from passed LongInt
		int RETURN2();
		//grab first 3 most significant digits from passed LongInt
		int RETURN3();
		//grab first 4 most significant digits from passed LongInt
		int RETURN4();
		//grab first 5 most significant digits from passed LongInt
		int RETURN5();
};

LongInt::LongInt(){
	this->L.head.next = &this->L.tail;
	this->L.head.prev = NULL;
	this->L.tail.next = NULL;
	this->L.tail.prev = &this->L.head;
	this->sign = 0;
	this->numDigits = 0;

}

LongInt::LongInt(string S)
{
	int size = 0;	//holds size of string without sign if there is one
	int i,j = 0;	//for the for loop
	int count = S.size() - 1;	//keeps track of current place in string
	string tempC;
	int numNodes = 0;
	int stop = 0;	//if negative stop at index 1, otherwise index 0
	string temp = "";

	//if number is negative set sign to true
	if (S[0] == '-'){
		sign = true;
		//since num is negative, first char isnt number
		size = S.size()-1;
		stop = 1;
		numDigits = size;
	}
	//if number is positive set sign to false
	else{
		sign = false;
		size = S.size();
		stop = 0;
		numDigits = size;
	}
	//determine number of nodes needed in LongInt DLL
	if(size%4 != 0){
		numNodes = size/4 + 1;
	}
	else
		numNodes = size/4;
	//for each node grab appropriate number of chars from string
	for(i = 0; i < numNodes; ++i){
		temp = "";

		for(j = 3; j >= 0; --j){
			if(count - j >= stop){
				tempC = S[count-j];
				
				temp.append(tempC);
			}
		}
		count -= 4;
		//insert 4 digit enforced node
		L.INSERT_LEFT(atoi(temp.c_str()));
	}
}

LongInt::~LongInt()
{
	//cout << "******* IN LONG INT DESTRUCTOR *******\n";
}

void LongInt::INITIALIZE(string S)
{
	int size = 0;	//holds size of string without sign if there is one
	int i,j = 0;	//for the for loop
	int count = S.size() - 1;	//keeps track of current place in string
	string tempC;
	int numNodes = 0;
	int stop = 0;	//if negative stop at index 1, otherwise index 0
	string temp = "";

	/*
	if(atoi(S.c_str()) == 0){
		L.INSERT_LEFT(0);
		return;
	}*/

	//if number is negative set sign to true
	if (S[0] == '-'){
		sign = true;
		//since num is negative, first char isnt number
		size = S.size()-1;
		stop = 1;
		numDigits = size;
	}
	//if number is positive set sign to false
	else{
		sign = false;
		size = S.size();
		stop = 0;
		numDigits = size;
	}
	//determine number of nodes needed in LongInt DLL
	if(size%4 != 0){
		numNodes = size/4 + 1;
	}
	else
		numNodes = size/4;
	//for each node grab appropriate number of chars from string
	for(i = 0; i < numNodes; ++i){
		temp = "";

		for(j = 3; j >= 0; --j){
			if(count - j >= stop){
				tempC = S[count-j];
				
				temp.append(tempC);
			}
		}
		count -= 4;
		//insert 4 digit enforced node
		L.INSERT_LEFT(atoi(temp.c_str()));
	}
}

void LongInt::PRINT()
{
	DLLNode temp = this->L.GET_FIRST();
	string tempS;
	ostringstream intToS;	//used in conversion of int to string
	string signS;	//holds sign of LongInt
	string lint = "";  //will hold outputted string
	int digs;

	if(this->GETSIGN()){
		signS = "-";
		lint.append(signS);
	}

	temp = this->L.GET_FIRST();

	//convert int val to string
	intToS << temp.value;
	//append to string that will be outputted
	lint.append(intToS.str());
	intToS.str("");

	while(!this->L.IS_LAST(temp)){
		temp = this->L.NEXT_RIGHT(temp);
		digs = this->DIGIT(temp.value);
		if(digs == 1){
			//pad three 0's
			lint.append("000");
			//convert int val to string
			intToS << temp.value;
			//append to string that will be outputted
			lint.append(intToS.str());
			intToS.str("");
		}
		else if(digs == 2){
			//pad two 0's
			lint.append("00");
			//convert int val to string
			intToS << temp.value;
			//append to string that will be outputted
			lint.append(intToS.str());
			intToS.str("");
		}
		else if(digs == 3){
			//pad one 0
			lint.append("0");
			//convert int val to string
			intToS << temp.value;
			//append to string that will be outputted
			lint.append(intToS.str());
			intToS.str("");
		}
		else if(digs == 4){
			intToS << temp.value;
			lint.append(intToS.str());
			intToS.str("");
		}
		else{
			lint.append("0000");
		}	
	}
	//finally print the string version of LongInt
	cout << lint << endl;
}

bool LongInt::GETSIGN()
{
	return sign;
}

void LongInt::SETSIGN(char S)
{
	if(S == '+')
		sign = false;
	//added during step 2
	else if(S == '-')
		sign = true;

	return;
}

int LongInt::GETDIGITCOUNT()
{
	return numDigits;
}

int LongInt::DIGIT(int T)
{
	int inc = 1;
	int count = 0;

	if(T != 0){
		while((T / inc) > 9){
			++count;
			inc *= 10;
		}

		++count;
	}
	return count;
}


int LongInt::OVER_FLOW(int &T)
{
	int r = 0;	//holds overflow digits
	if(this->DIGIT(T) > 4){
		r = T / 10000;
		T = T % 10000;
		return r;
	}
	else
		return 0;
}


bool LongInt::GREATERTHAN(LongInt *Q)
{
	DLLNode temp1;	//holds this's nodes for comparison
	DLLNode temp2;	//holds Q's nodes for comparison
	bool greaterThan = false;
	bool endFlag = false;

	//checks if one is negative and other is positive
	if(this->GETSIGN() == false and Q->GETSIGN() == true)
		return true;
	else if(this->GETSIGN() == true and Q->GETSIGN() == false)
		return false;
	//if both positive
	if(this->GETSIGN() == false){
		if(this->GETDIGITCOUNT() > Q->GETDIGITCOUNT())
			return true;
		else if(this->GETDIGITCOUNT() < Q->GETDIGITCOUNT())
			return false;
		else{
			temp1 = this->L.GET_FIRST();
			temp2 = Q->L.GET_FIRST();
			while( !endFlag && temp1.value == temp2.value){
				if(!this->L.IS_LAST(temp1)){
					temp1 = this->L.NEXT_RIGHT(temp1);
					temp2 = Q->L.NEXT_RIGHT(temp2);
				}
				else
					endFlag = true;
			}
			if(temp1.value > temp2.value)
				return true;
			else
				return false;
		}
	}
	//if both negative
	else{
		if(this->GETDIGITCOUNT() > Q->GETDIGITCOUNT())
			return false;
		else if(this->GETDIGITCOUNT() < Q->GETDIGITCOUNT())
			return true;
		else{
			temp1 = this->L.GET_FIRST();
			temp2 = Q->L.GET_FIRST();
			while( !endFlag && temp1.value == temp2.value){
				if(!this->L.IS_LAST(temp1)){
					temp1 = this->L.NEXT_RIGHT(temp1);
					temp2 = Q->L.NEXT_RIGHT(temp2);
				}
				else
					endFlag = true;
			}
			if(temp1.value < temp2.value)
				return true;
			else
				return false;
		}
	}
}

bool LongInt::LESSTHAN(LongInt *Q)
{
	DLLNode temp1;	//holds this's nodes for comparison
	DLLNode temp2;	//holds Q's nodes for comparison
	bool lessThan = false;
	bool endFlag = false;

	//checks if one is negative and other is positive
	if(this->GETSIGN() == false and Q->GETSIGN() == true)
		return false;
	else if(this->GETSIGN() == true and Q->GETSIGN() == false)
		return true;
	//if both positive
	if(this->GETSIGN() == false){
		if(this->GETDIGITCOUNT() > Q->GETDIGITCOUNT())
			return false;
		else if(this->GETDIGITCOUNT() < Q->GETDIGITCOUNT())
			return true;
		else{
			temp1 = this->L.GET_FIRST();
			temp2 = Q->L.GET_FIRST();
			while( !endFlag && temp1.value == temp2.value){
				if(!this->L.IS_LAST(temp1)){
					temp1 = this->L.NEXT_RIGHT(temp1);
					temp2 = Q->L.NEXT_RIGHT(temp2);
				}
				else
					endFlag = true;
			}
			if(temp1.value < temp2.value)
				return true;
			else
				return false;
		}
	}
	//if both negative
	else{
		if(this->GETDIGITCOUNT() > Q->GETDIGITCOUNT())
			return true;
		else if(this->GETDIGITCOUNT() < Q->GETDIGITCOUNT())
			return false;
		else{
			temp1 = this->L.GET_FIRST();
			temp2 = Q->L.GET_FIRST();
			while( !endFlag && temp1.value == temp2.value){
				if(!this->L.IS_LAST(temp1)){
					temp1 = this->L.NEXT_RIGHT(temp1);
					temp2 = Q->L.NEXT_RIGHT(temp2);
				}
				else
					endFlag = true;
			}
			if(temp1.value > temp2.value){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

bool LongInt::EQUALTO(LongInt *Q)
{
	DLLNode temp1;	//holds this's nodes for comparison
	DLLNode temp2;	//holds Q's nodes for comparison
	bool equalFlag = false;
	bool endFlag = false;

	//checks if one is negative and other is positive
	if(this->GETSIGN() != Q->GETSIGN() == true)
		return false;
	//checks if both have same number of digits
	if(this->GETDIGITCOUNT() != Q->GETDIGITCOUNT())
		return false;
	
	temp1 = this->L.GET_FIRST();
	temp2 = Q->L.GET_FIRST();
	while( !endFlag && temp1.value == temp2.value){
		if(!this->L.IS_LAST(temp1)){
			temp1 = this->L.NEXT_RIGHT(temp1);
			temp2 = Q->L.NEXT_RIGHT(temp2);
		}
		else
			endFlag = true;
	}

	if(temp1.value == temp2.value)
		return true;
	else
		return false;
}

LongInt& LongInt::operator=(LongInt &Q){

	if(this == &Q){
		return *this;
	}

	this->L.~DLList();

	DLLNode tempQ = Q.L.GET_FIRST();

	this->sign = Q.GETSIGN();
	this->numDigits = Q.GETDIGITCOUNT();

	while(!(Q.L.IS_LAST(tempQ))){
		this->L.INSERT_RIGHT(tempQ.value);
		tempQ = Q.L.NEXT_RIGHT(tempQ);
	}

	this->L.INSERT_RIGHT(tempQ.value);

	return *this;
}

LongInt& LongInt::operator+(LongInt &Q){
	LongInt *sum = new LongInt();
	DLLNode tempQ = Q.L.GET_LAST();
	DLLNode tempThis = this->L.GET_LAST();
	int tempVal = 0;
	int tempCarry = 0;

	//perform addition on two numbers of equal sign
	if(this->GETSIGN() == Q.GETSIGN()){
		if(this->GETSIGN()){
			sum->SETSIGN('-');
		}
		else{
			sum->SETSIGN('+');
		}
		if(this->GETDIGITCOUNT() == Q.GETDIGITCOUNT()){
			while(!Q.L.IS_FIRST(tempQ)){
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			tempVal = tempQ.value + tempThis.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			sum->L.INSERT_LEFT(tempVal);
			if(tempCarry != 0){
				sum->L.INSERT_LEFT(tempCarry);
			}
		}
		else if(this->GETDIGITCOUNT() < Q.GETDIGITCOUNT()){
			while(!this->L.IS_FIRST(tempThis)){
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			tempVal = tempQ.value + tempThis.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			sum->L.INSERT_LEFT(tempVal);
			tempVal = 0;
			while(!Q.L.IS_FIRST(tempQ)){
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempVal = tempQ.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
			}
		}
		else if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT()){
			while(!Q.L.IS_FIRST(tempQ)){
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			tempVal = tempQ.value + tempThis.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			sum->L.INSERT_LEFT(tempVal);
			tempVal = 0;
			while(!this->L.IS_FIRST(tempThis)){
				tempThis = this->L.NEXT_LEFT(tempThis);
				tempVal = tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
			}
		}
	}
	//perform addition on two numbers of different signs
	else{
		//if this has more digits
		if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT()){
			if(this->GETSIGN()){
				sum->SETSIGN('-');
			}
			else{
				sum->SETSIGN('+');
			}
			while(!Q.L.IS_FIRST(tempQ)){
				if(tempCarry){
					if(tempThis.value != 0)
						tempThis.value -= 1;
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempThis.value < tempQ.value){
					tempThis.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempThis.value - tempQ.value;
				sum->L.INSERT_LEFT(tempVal);
				tempThis = this->L.NEXT_LEFT(tempThis);
				tempQ = Q.L.NEXT_LEFT(tempQ);
			}
			if(tempCarry){
				if(tempThis.value != 0)
					tempThis.value -= 1;
				else{
					tempThis.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempThis.value < tempQ.value){
				tempThis.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempThis.value - tempQ.value;
			sum->L.INSERT_LEFT(tempVal);
			while(!this->L.IS_FIRST(tempThis)){
				tempThis = this->L.NEXT_LEFT(tempThis);
				if(tempCarry){
					if(tempThis.value != 0){
						tempThis.value -= 1;
						tempCarry = 0;
					}
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				sum->L.INSERT_LEFT(tempThis.value);
			}

		}
		//if Q has more digits
		else{
			if(Q.GETSIGN()){
				sum->SETSIGN('-');
			}
			else{
				sum->SETSIGN('+');
			}
			while(!this->L.IS_FIRST(tempThis)){
				if(tempCarry){
					if(tempQ.value != 0)
						tempQ.value -= 1;
					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempQ.value < tempThis.value){
					tempQ.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempQ.value - tempThis.value;
				sum->L.INSERT_LEFT(tempVal);
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			if(tempCarry){
				if(tempQ.value != 0)
					tempQ.value -= 1;
				else{
					tempQ.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempQ.value < tempThis.value){
				tempQ.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempQ.value - tempThis.value;
			sum->L.INSERT_LEFT(tempVal);
			while(!Q.L.IS_FIRST(tempQ)){
				tempQ = Q.L.NEXT_LEFT(tempQ);
				if(tempCarry){
					if(tempQ.value != 0){
						tempQ.value -= 1;
						tempCarry = 0;
					}

					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}

				}
				sum->L.INSERT_LEFT(tempQ.value);
			}
		}
	}


	//determine digit count of newly created LongInt
	DLLNode tempSum = sum->L.GET_LAST();
	int digitCount = 0;
	while(!sum->L.IS_FIRST(tempSum)){
		digitCount += 4;
		tempSum = sum->L.NEXT_LEFT(tempSum);
	}
	digitCount += DIGIT(tempSum.value);
	sum->numDigits = digitCount;

	return *sum;
}

LongInt& LongInt::operator-(LongInt &Q){
	LongInt *sum = new LongInt();
	DLLNode tempQ = Q.L.GET_LAST();
	DLLNode tempThis = this->L.GET_LAST();
	int tempVal = 0;
	int tempCarry = 0;

	//if this > Q
	if(this->GREATERTHAN(&Q)){
		//subtract two positive numbers
		if(this->GETSIGN() == false and Q.GETSIGN() == false){
			sum->SETSIGN('+');
			while(!Q.L.IS_FIRST(tempQ)){
				if(tempCarry){
					if(tempThis.value != 0)
						tempThis.value -= 1;
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempThis.value < tempQ.value){
					tempThis.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempThis.value - tempQ.value;
				sum->L.INSERT_LEFT(tempVal);
				tempThis = this->L.NEXT_LEFT(tempThis);
				tempQ = Q.L.NEXT_LEFT(tempQ);
			}
			if(tempCarry){
				if(tempThis.value != 0)
					tempThis.value -= 1;
				else{
					tempThis.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempThis.value < tempQ.value){
				tempThis.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempThis.value - tempQ.value;
			sum->L.INSERT_LEFT(tempVal);
			while(!this->L.IS_FIRST(tempThis)){
				tempThis = this->L.NEXT_LEFT(tempThis);
				if(tempCarry){
					if(tempThis.value != 0){
						tempThis.value -= 1;
						tempCarry = 0;
					}
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				sum->L.INSERT_LEFT(tempThis.value);
			}
		}
		//subtract negative Q from positive this
		else if(this->GETSIGN() == false and Q.GETSIGN() == true){
			if(this->GETDIGITCOUNT() == Q.GETDIGITCOUNT()){
				while(!Q.L.IS_FIRST(tempQ)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				if(tempCarry != 0){
					sum->L.INSERT_LEFT(tempCarry);
				}
			}
			else if(this->GETDIGITCOUNT() < Q.GETDIGITCOUNT()){
				while(!this->L.IS_FIRST(tempThis)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				while(!Q.L.IS_FIRST(tempQ)){
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempVal = tempQ.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
				}
			}
			else if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT()){
				while(!Q.L.IS_FIRST(tempQ)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				while(!this->L.IS_FIRST(tempThis)){
					tempThis = this->L.NEXT_LEFT(tempThis);
					tempVal = tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
				}
			}
		}
		//subtract two negative numbers
		else if(this->GETSIGN() == true and Q.GETSIGN() == true){
			sum->SETSIGN('+');
			while(!this->L.IS_FIRST(tempThis)){
				if(tempCarry){
					if(tempQ.value != 0)
						tempQ.value -= 1;
					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempQ.value < tempThis.value){
					tempQ.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempQ.value - tempThis.value;
				sum->L.INSERT_LEFT(tempVal);
				tempQ = Q.L.NEXT_LEFT(tempQ);
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			if(tempCarry){
				if(tempQ.value != 0)
					tempQ.value -= 1;
				else{
					tempQ.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempQ.value < tempThis.value){
				tempQ.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempQ.value - tempThis.value;
			if(tempVal != 0){
				sum->L.INSERT_LEFT(tempVal);
			}
			while(!Q.L.IS_FIRST(tempQ)){
				tempQ = Q.L.NEXT_LEFT(tempQ);
				if(tempCarry){
					if(tempQ.value != 0){
						tempQ.value -= 1;
						tempCarry = 0;
					}

					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}
				}
				sum->L.INSERT_LEFT(tempQ.value);
			}
		}
	}
	//if this < Q
	else if(this->LESSTHAN(&Q)){
		//subtract two negative numbers when Q > t
		if(this->GETSIGN() == true and Q.GETSIGN() == true){
			sum->SETSIGN('-');
			while(!Q.L.IS_FIRST(tempQ)){
				if(tempCarry){
					if(tempThis.value != 0)
						tempThis.value -= 1;
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempThis.value < tempQ.value){
					tempThis.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempThis.value - tempQ.value;
				sum->L.INSERT_LEFT(tempVal);
				tempThis = this->L.NEXT_LEFT(tempThis);
				tempQ = Q.L.NEXT_LEFT(tempQ);
			}
			if(tempCarry){
				if(tempThis.value != 0)
					tempThis.value -= 1;
				else{
					tempThis.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempThis.value < tempQ.value){
				tempThis.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempThis.value - tempQ.value;
			sum->L.INSERT_LEFT(tempVal);
			while(!this->L.IS_FIRST(tempThis)){
				tempThis = this->L.NEXT_LEFT(tempThis);
				if(tempCarry){
					if(tempThis.value != 0){
						tempThis.value -= 1;
						tempCarry = 0;
					}
					else{
						tempThis.value = 9999;
						tempCarry = 1;
					}
				}
				sum->L.INSERT_LEFT(tempThis.value);
			}
		}
		//subtract positive Q from negative this
		else if(this->GETSIGN() == true and Q.GETSIGN() == false){
			sum->SETSIGN('-');
			if(this->GETDIGITCOUNT() == Q.GETDIGITCOUNT()){
				while(!Q.L.IS_FIRST(tempQ)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				if(tempCarry != 0){
					sum->L.INSERT_LEFT(tempCarry);
				}
			}
			else if(this->GETDIGITCOUNT() < Q.GETDIGITCOUNT()){
				while(!this->L.IS_FIRST(tempThis)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				while(!Q.L.IS_FIRST(tempQ)){
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempVal = tempQ.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
				}
			}
			else if(this->GETDIGITCOUNT() > Q.GETDIGITCOUNT()){
				while(!Q.L.IS_FIRST(tempQ)){
					tempVal = tempQ.value + tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
					tempQ = Q.L.NEXT_LEFT(tempQ);
					tempThis = this->L.NEXT_LEFT(tempThis);
				}
				tempVal = tempQ.value + tempThis.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				sum->L.INSERT_LEFT(tempVal);
				tempVal = 0;
				while(!this->L.IS_FIRST(tempThis)){
					tempThis = this->L.NEXT_LEFT(tempThis);
					tempVal = tempThis.value + tempCarry;
					tempCarry = OVER_FLOW(tempVal);
					sum->L.INSERT_LEFT(tempVal);
					tempVal = 0;
				}
			}
		}
		//subtract two positive numbers when Q > this
		else if (this->GETSIGN() == false and Q.GETSIGN() == false){
			sum->SETSIGN('-');
			while(!this->L.IS_FIRST(tempThis)){
				if(tempCarry){
					if(tempQ.value != 0)
						tempQ.value -= 1;
					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}
				}
				if(tempQ.value < tempThis.value){
					tempQ.value += 10000;
					tempCarry = 1;
				}
				else{
					tempCarry = 0;
				}
				tempVal = tempQ.value - tempThis.value;
				sum->L.INSERT_LEFT(tempVal);
				tempThis = this->L.NEXT_LEFT(tempThis);
				tempQ = Q.L.NEXT_LEFT(tempQ);
			}
			if(tempCarry){
				if(tempQ.value != 0)
					tempQ.value -= 1;
				else{
					tempQ.value = 9999;
					tempCarry = 1;
				}
			}
			if(tempQ.value < tempThis.value){
				tempQ.value += 10000;
				tempCarry = 1;
			}
			else{
				tempCarry = 0;
			}
			tempVal = tempQ.value - tempThis.value;
			sum->L.INSERT_LEFT(tempVal);
			while(!Q.L.IS_FIRST(tempQ)){
				tempQ = Q.L.NEXT_LEFT(tempQ);
				if(tempCarry){
					if(tempQ.value != 0){
						tempQ.value -= 1;
						tempCarry = 0;
					}
					else{
						tempQ.value = 9999;
						tempCarry = 1;
					}
				}
				sum->L.INSERT_LEFT(tempQ.value);
			}
		}
	}
	//if this = Q
	else if (this->EQUALTO(&Q)){
		sum->SETSIGN('+');
		sum->L.INSERT_LEFT(0);

		return *sum;
	}

	//trim zeros from sum (which is the difference)
	LongInt *sum_trimmed = new LongInt();
	DLLNode sum_trimmed_temp;

	sum_trimmed_temp = sum->L.GET_FIRST();
	while(sum_trimmed_temp.value == 0){
		sum_trimmed_temp = sum->L.NEXT_RIGHT(sum_trimmed_temp);
	}

	while(!sum->L.IS_LAST(sum_trimmed_temp)){
		sum_trimmed->L.INSERT_RIGHT(sum_trimmed_temp.value);
		sum_trimmed_temp = sum->L.NEXT_RIGHT(sum_trimmed_temp);
	}
	sum_trimmed->L.INSERT_RIGHT(sum_trimmed_temp.value);


	//determine digit count of newly created LongInt
	DLLNode tempSum = sum_trimmed->L.GET_LAST();
	int digitCount = 0;
	while(!sum_trimmed->L.IS_FIRST(tempSum)){
		digitCount += 4;
		tempSum = sum_trimmed->L.NEXT_LEFT(tempSum);
	}
	digitCount += DIGIT(tempSum.value);
	sum_trimmed->numDigits = digitCount;
	sum_trimmed->sign = sum->sign;

	return *sum_trimmed;
}

LongInt& LongInt::operator*(LongInt &Q){
	LongInt *product = new LongInt("0");
	
	DLLNode tempQ = Q.L.GET_LAST();
	DLLNode tempThis = this->L.GET_LAST();

	int tempVal = 0;
	int tempCarry = 0;
	int nodeCount = 0; //keeps track of how many 0 nodes need to go into
					   //tempProduct
	bool tempSign;

	if(this->GETSIGN() == Q.GETSIGN()){
		tempSign = 0;
	}
	else if(this->GETSIGN() or Q.GETSIGN()){
		tempSign = 1;
	}

	//if this has greater than or same number of digits as Q
	if(this->numDigits >= Q.numDigits){

		//multiplies all but the first node in Q
		while(!Q.L.IS_FIRST(tempQ)){

			LongInt *tempProduct = new LongInt();

			for(int i = 0; i < nodeCount; i++){
				tempProduct->L.INSERT_RIGHT(0);
				tempProduct->numDigits += 4;
			}

			while(!this->L.IS_FIRST(tempThis)){

				tempVal = tempThis.value * tempQ.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempThis = this->L.NEXT_LEFT(tempThis);
			}
			tempVal = tempThis.value * tempQ.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			if(tempCarry){
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempProduct->L.INSERT_LEFT(tempCarry);
				tempProduct->numDigits += DIGIT(tempCarry);
				tempCarry = 0;
			}
			else{
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += DIGIT(tempVal);
			}

			nodeCount++;
			//move tempQ one node over
			tempQ = Q.L.NEXT_LEFT(tempQ);
			//reset tempThis to Last node from this
			tempThis = this->L.GET_LAST();

			*product = *product + *tempProduct;
		}

		//multiplies the first node from Q
		LongInt *tempProduct = new LongInt();

		for(int i = 0; i < nodeCount; i++){
			tempProduct->L.INSERT_RIGHT(0);
			tempProduct->numDigits += 4;
		}

		while(!this->L.IS_FIRST(tempThis)){

			tempVal = tempThis.value * tempQ.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			tempProduct->L.INSERT_LEFT(tempVal);
			tempThis = this->L.NEXT_LEFT(tempThis);
			tempProduct->numDigits += 4;
		}
		tempVal = tempThis.value * tempQ.value + tempCarry;
		tempCarry = OVER_FLOW(tempVal);
		if(tempCarry){
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempProduct->L.INSERT_LEFT(tempCarry);
				tempProduct->numDigits += DIGIT(tempCarry);
				tempCarry = 0;
		}
		else{
			tempProduct->L.INSERT_LEFT(tempVal);
			tempProduct->numDigits += DIGIT(tempVal);
		}

		*product = *tempProduct + *product;
	}


	//if this has less digits than Q
	else{

		//multiplies all but the first node in Q
		while(!this->L.IS_FIRST(tempThis)){

			LongInt *tempProduct = new LongInt();

			for(int i = 0; i < nodeCount; i++){
				tempProduct->L.INSERT_RIGHT(0);
				tempProduct->numDigits += 4;
			}

			while(!Q.L.IS_FIRST(tempQ)){

				tempVal = tempThis.value * tempQ.value + tempCarry;
				tempCarry = OVER_FLOW(tempVal);
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempQ = Q.L.NEXT_LEFT(tempQ);
			}
			tempVal = tempThis.value * tempQ.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);

			if(tempCarry){
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempProduct->L.INSERT_LEFT(tempCarry);
				tempProduct->numDigits += DIGIT(tempCarry);
				tempCarry = 0;
			}
			else{
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += DIGIT(tempVal);
			}

			nodeCount++;
			//move tempQ one node over
			tempThis = this->L.NEXT_LEFT(tempThis);
			//reset tempThis to Last node from this
			tempQ = Q.L.GET_LAST();

			*product = *product + *tempProduct;
		}

		//multiplies the first node from Q
		LongInt *tempProduct = new LongInt();

		for(int i = 0; i < nodeCount; i++){
			tempProduct->L.INSERT_RIGHT(0);
			tempProduct->numDigits += 4;
		}

		while(!Q.L.IS_FIRST(tempQ)){

			tempVal = tempThis.value * tempQ.value + tempCarry;
			tempCarry = OVER_FLOW(tempVal);
			tempProduct->L.INSERT_LEFT(tempVal);
			tempQ = Q.L.NEXT_LEFT(tempQ);
			tempProduct->numDigits += 4;
		}
		tempVal = tempThis.value * tempQ.value + tempCarry;
		tempCarry = OVER_FLOW(tempVal);
		if(tempCarry){
				tempProduct->L.INSERT_LEFT(tempVal);
				tempProduct->numDigits += 4;
				tempProduct->L.INSERT_LEFT(tempCarry);
				tempProduct->numDigits += DIGIT(tempCarry);
				tempCarry = 0;
		}
		else{
			tempProduct->L.INSERT_LEFT(tempVal);
			tempProduct->numDigits += DIGIT(tempVal);
		}

		*product = *tempProduct + *product;
		
	}

	product->sign = tempSign;
	return *product;
}

LongInt& LongInt::operator^(int power)
{
	LongInt *result = new LongInt("1");
	result->SETSIGN('+');
	result->numDigits = 1;
	LongInt *currentPower = new LongInt("1");
	*currentPower = *this;
	int arraySize = log2(power) + 1;
	int binaryInt[arraySize];
	int powerResult = power;
	int indexCount = 0;
	int temp = 0;

	if (power == 0){
		return *result;
	}
	if (power == 1){
		return *this;
	}

	//use array to store binary equivalent of value of power
	while( (powerResult / 2) > 0){
		temp = (powerResult % 2);
		powerResult /= 2;
		binaryInt[indexCount++] = temp;
	}
	temp = powerResult%2;
	binaryInt[indexCount] = temp;

	for(int i = 0; i < arraySize; i++){
		if(binaryInt[i] == 1){
			*result = (*currentPower) * (*result);
		}
		*currentPower = (*currentPower) * (*currentPower);
	}

	return *result;
}

int LongInt::RETURN1()
{
	DLLNode tempNode;
	int one;

	tempNode = this->L.GET_FIRST();
	one = tempNode.value;

	if(one < 10){
		return one;
	}
	else if(one < 100){
		return (one / 10);
	}
	else if(one < 1000){
		return (one / 100);
	}
	else{
		return (one / 1000);
	}
}

int LongInt::RETURN2()
{
	DLLNode tempNode;
	int two, temp;

	tempNode = this->L.GET_FIRST();
	two = tempNode.value;

	if(two < 10){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		two *= 10;
		two = two + tempNode.value / 1000;
		return two;
	}
	else if(two < 100){
		return two;
	}
	else if(two < 1000){
		return two/10;
	}
	else{
		return two/100;
	}
}

int LongInt::RETURN3()
{
	DLLNode tempNode;
	int three, temp;

	tempNode = this->L.GET_FIRST();
	three = tempNode.value;

	if(three < 10){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		three *= 100;
		three = three + tempNode.value / 100;

		return three;
	}
	else if(three < 100){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		three *= 10;
		three = three + tempNode.value / 1000;

		return three;
	}
	else if(three < 1000){
		return three;
	}
	else{
		return three/10;
	}
}



int LongInt::RETURN4()
{
	DLLNode tempNode;
	int four, temp1;

	
	tempNode = this->L.GET_FIRST();
	four = tempNode.value;

	if(four < 10){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 10;
		four = four * 1000;
		four += temp1;
	}
	else if(four < 100){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 100;
		four = four * 100;
		four += temp1;
	}
	else if(four < 1000){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 1000;
		four = four * 10;
		four += temp1;
	}

	return four;
}

int LongInt::RETURN5()
{
	DLLNode tempNode;
	int five, temp1;
	
	tempNode = this->L.GET_FIRST();
	five = tempNode.value;

	if(five < 10){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value;
		five = five * 10000;
		five += temp1;
	}
	else if(five < 100){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 10;
		five = five * 1000;
		five += temp1;
	}
	else if(five < 1000){
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 100;
		five = five * 100;
		five += temp1;
	}
	else{
		tempNode = this->L.NEXT_RIGHT(tempNode);
		temp1 = tempNode.value / 1000;
		five = five * 10;
		five += temp1;
	}

	return five;
}


LongInt& LongInt::operator/(LongInt& Q)
{
	LongInt ten;
	ten.INITIALIZE("10");
	LongInt empty;
	LongInt* tempLong = new LongInt("1");
	LongInt* result = new LongInt("");
	LongInt* rem = new LongInt("");
	LongInt tempSub;
	int tempInt1, tempInt2, denom, numer, guess;
	LongInt numerLong;
	numerLong = *this;
	*rem = *this;
	int intResult;
	//keeps result of divides betweens denom and numer, when tempResult holds
	//4 digits worth, tempResult will be inserted into LongInt result
	int counter = 0;
	//starting out equal to false, if at the end moreThan4 is still false, meaning
	//result will be only one node, tempResult will be inserted into LongInt
	bool moreThan4 = false;
	bool firstShift = true;
	int expectedShift = 0;
	//array to hold results of each denom / numer quotient, which can possibly have as
	//many entries as this has digits
	int tempResult[this->numDigits];

	DLLNode tempNode1, tempNode2;

	if(this->sign != Q.sign){
		result->SETSIGN('-');
		rem->SETSIGN('+');
		Q.SETSIGN('+');
	}
	else{
		result->SETSIGN('+');
		rem->SETSIGN('+');
		Q.SETSIGN('+');
	}

	//if LongInts are equal return 1
	if(this->EQUALTO(&Q)){
		return *tempLong;
	}
	//if denominator is 1, return numerator
	else if(Q.EQUALTO(tempLong)){
		*result = *this;
		return *result;
	}
	//if result would be fraction return 0
	else if(rem->LESSTHAN(&Q)){
		result->L.INSERT_RIGHT(0);
		result->numDigits = 1;
		return *result;
	}
	//if both LongInts have 4 or less digits
	else if(this->numDigits <= 4 && Q.numDigits <= 4){
		tempNode1 = this->L.GET_FIRST();
		tempNode2 = Q.L.GET_FIRST();
		tempInt1 = tempNode1.value / tempNode2.value;
		result->L.INSERT_RIGHT(tempInt1);
		result->numDigits = result->DIGIT(tempInt1);

		return *result;
	}
	//if denominator is only 1 digit
	else if(this->numDigits > 4 && Q.numDigits == 1){
		denom = Q.RETURN1();
		while(rem->GREATERTHAN(&Q) || rem->EQUALTO(&Q)){
			LongInt tempSub;
			numer = rem->RETURN1();
			if(denom > numer){
				numer = rem->RETURN2();
			}
			//guess holds a single digit of LongInt result 
			guess = numer / denom;
			intResult = guess * denom;
			tempSub.L.INSERT_RIGHT(intResult);
			tempSub.numDigits = tempSub.DIGIT(intResult);
			int shiftCount = 0;
			while(rem->GREATERTHAN(&(tempSub * ten)) || rem->EQUALTO(&(tempSub * ten)) ){
				tempSub = tempSub * ten;
				++tempSub.numDigits;
				++shiftCount;
				if(firstShift){
					++expectedShift;
				}
			}
			--tempSub.numDigits;
			firstShift = false;
			
		/*******add zeros****************/
			int digitCount1 = rem->numDigits;
			*rem = *rem - tempSub;
			int digitCount2 = rem->numDigits;
			int addZeros = expectedShift - shiftCount;
			if( addZeros > 0){
				for(int i = 0; i < addZeros; i++){
					tempResult[counter++] = 0;
				}
				expectedShift = shiftCount - 1;
			}
			tempResult[counter++] = guess;
			shiftCount = 0;
			--expectedShift;
		}

		int countBackwards = counter - 1;
		int multiplier = 1;
		int result4 = 0;
		int count4 = 0;

		for(int i = countBackwards; i >= 0; i--){
			//create the new LongInt which is result of division from the array
			//holding the values as single digits
			result4 += (tempResult[i] * multiplier);
			multiplier *= 10;
			++count4;
			if(count4 == 4){
				multiplier = 1;
				result->L.INSERT_LEFT(result4);
				result->numDigits += 4;
				result4 = 0;
				count4 = 0;
			}
		}
		if(result4 > 0){
			result->L.INSERT_LEFT(result4);
			result->numDigits += result->DIGIT(result4);
		}

		return *result;

	}
	//if denominator has 2 digits
	else if(this->numDigits > 4 && Q.numDigits == 2){
		denom = Q.RETURN2();
		while(rem->GREATERTHAN(&Q) || rem->EQUALTO(&Q)){
			LongInt tempSub;
			numer = rem->RETURN2();
			if(denom > numer){
				numer = rem->RETURN3();
			}
			//guess holds a single digit of LongInt result 
			guess = numer / denom;
			intResult = guess * denom;
			tempSub.L.INSERT_RIGHT(intResult);
			tempSub.numDigits = tempSub.DIGIT(intResult);
			int shiftCount = 0;
			while(rem->GREATERTHAN(&(tempSub * ten)) || rem->EQUALTO(&(tempSub * ten)) ){
				tempSub = tempSub * ten;
				++tempSub.numDigits;
				++shiftCount;
				if(firstShift){
					++expectedShift;
				}
			}
			--tempSub.numDigits;
			firstShift = false;
			
		/*******add zeros****************/
			int digitCount1 = rem->numDigits;
			*rem = *rem - tempSub;
			int digitCount2 = rem->numDigits;
			int addZeros = expectedShift - shiftCount;
			if( addZeros > 0){
				for(int i = 0; i < addZeros; i++){
					tempResult[counter++] = 0;
				}
				expectedShift = shiftCount - 1;
			}
			tempResult[counter++] = guess;
			shiftCount = 0;
			--expectedShift;
		}

		int countBackwards = counter - 1;
		int multiplier = 1;
		int result4 = 0;
		int count4 = 0;

		for(int i = countBackwards; i >= 0; i--){
			//create the new LongInt which is result of division from the array
			//holding the values as single digits
			result4 += (tempResult[i] * multiplier);
			multiplier *= 10;
			++count4;
			if(count4 == 4){
				multiplier = 1;
				result->L.INSERT_LEFT(result4);
				result->numDigits += 4;
				result4 = 0;
				count4 = 0;
			}
		}
		if(result4 > 0){
			result->L.INSERT_LEFT(result4);
			result->numDigits += result->DIGIT(result4);
		}

		return *result;
	}
	//if denominator has 3 digits
	else if(this->numDigits > 4 && Q.numDigits == 3){
		denom = Q.RETURN3();
		while(rem->GREATERTHAN(&Q) || rem->EQUALTO(&Q)){
			LongInt tempSub;
			numer = rem->RETURN3();
			if(denom > numer){
				numer = rem->RETURN4();
			}
			//guess holds a single digit of LongInt result 
			guess = numer / denom;
			intResult = guess * denom;
			tempSub.L.INSERT_RIGHT(intResult);
			tempSub.numDigits = tempSub.DIGIT(intResult);
			int shiftCount = 0;
			while(rem->GREATERTHAN(&(tempSub * ten)) || rem->EQUALTO(&(tempSub * ten)) ){
				tempSub = tempSub * ten;
				++tempSub.numDigits;
				++shiftCount;
				if(firstShift){
					++expectedShift;
				}
			}
			--tempSub.numDigits;
			firstShift = false;
			
		/*******add zeros****************/
			int digitCount1 = rem->numDigits;
			*rem = *rem - tempSub;
			int digitCount2 = rem->numDigits;
			int addZeros = expectedShift - shiftCount;
			if( addZeros > 0){
				for(int i = 0; i < addZeros; i++){
					tempResult[counter++] = 0;
				}
				expectedShift = shiftCount - 1;
			}
			tempResult[counter++] = guess;
			shiftCount = 0;
			--expectedShift;
		}

		int countBackwards = counter - 1;
		int multiplier = 1;
		int result4 = 0;
		int count4 = 0;

		for(int i = countBackwards; i >= 0; i--){
			//create the new LongInt which is result of division from the array
			//holding the values as single digits
			result4 += (tempResult[i] * multiplier);
			multiplier *= 10;
			++count4;
			if(count4 == 4){
				multiplier = 1;
				result->L.INSERT_LEFT(result4);
				result->numDigits += 4;
				result4 = 0;
				count4 = 0;
			}
		}
		if(result4 > 0){
			result->L.INSERT_LEFT(result4);
			result->numDigits += result->DIGIT(result4);
		}

		return *result;
	}
	//if denominator has 4 or more digits
	else if(this->numDigits > 4 && Q.numDigits >= 4){
		denom = Q.RETURN4();
		while(rem->GREATERTHAN(&Q) || rem->EQUALTO(&Q)){
			LongInt tempSub;
			numer = rem->RETURN4();
			if(denom > numer){
				numer = rem->RETURN5();
			}
			//guess holds a single digit of LongInt result 
			guess = numer / denom;
			intResult = guess * denom;
			tempSub.L.INSERT_RIGHT(intResult);
			tempSub.numDigits = tempSub.DIGIT(intResult);
			int shiftCount = 0;
			while(rem->GREATERTHAN(&(tempSub * ten)) || rem->EQUALTO(&(tempSub * ten)) ){
				tempSub = tempSub * ten;
				++tempSub.numDigits;
				++shiftCount;
				if(firstShift){
					++expectedShift;
				}
			}
			--tempSub.numDigits;
			firstShift = false;
			
			*rem = *rem - tempSub;
			int addZeros = expectedShift - shiftCount;
			if( addZeros > 0){
				for(int i = 0; i < addZeros; i++){
					tempResult[counter++] = 0;
				}
				expectedShift = shiftCount - 1;
			}
			tempResult[counter++] = guess;
			shiftCount = 0;
			--expectedShift;
		}

		int countBackwards = counter - 1;
		int multiplier = 1;
		int result4 = 0;
		int count4 = 0;

		for(int i = countBackwards; i >= 0; i--){
			//create the new LongInt which is result of division from the array
			//holding the values as single digits
			result4 += (tempResult[i] * multiplier);
			multiplier *= 10;
			++count4;
			if(count4 == 4){
				multiplier = 1;
				result->L.INSERT_LEFT(result4);
				result->numDigits += 4;
				result4 = 0;
				count4 = 0;
			}
		}
		if(result4 > 0){
			result->L.INSERT_LEFT(result4);
			result->numDigits += result->DIGIT(result4);
		}

		return *result;
	}

	return *this;
}