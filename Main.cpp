#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
	int number_cols, row_number;
	char ch1, ch2;
	cout<< "Enter number of cols:"<<endl;
	cin>> number_cols;
	cout<< "Enter number of rows:"<<endl;
	cin>> row_number;
	cout<< "Enter char 1:"<<endl;
	cin>> ch1;
	cout<< "Enter char 2:"<<endl;
	cin>> ch2;
	try {
		cout << mat(number_cols, row_number, ch1, ch2) << endl; 
	} catch (exception& ex) {
	 	cout << "   catched Exception: " << ex.what() << endl;
	}





}