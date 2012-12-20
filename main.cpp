#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <assert.h>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <iterator>
#include <sstream>
#include <fstream>
#include <istream>
using namespace std;
string GetLine() {
	string result;
	getline(cin, result);
	
	return result;
}// ignore this it is pretty much the same as cin

int GetInteger() {
	
	while(true) {
		stringstream converter;
		converter << GetLine();
		
		int result;
		converter >> result;
		
		if(converter.fail()){
			cout << "Please enter an integer." << endl;
			return GetInteger();
		}
		else {
			char remaining;
			converter >> remaining;
			
			if(converter.fail())
				return result;
			else
				cout << "Unexpected character: " << remaining << endl;
			return GetInteger();
		}
		
		cout << "Retry";
	}
	
}




vector <int> FindFactors (int multi){
	vector <int> factors;
	if (multi<0) {
		multi *= -1;
	}
	factors.push_back(1);
	factors.push_back(multi);
	for (int i = -fabs(multi)/2; i < fabs(multi)/2; i++) {
		for (int j = -fabs(multi)/2; j <= fabs(multi)/2; j++) {
			if(i*j == multi){
				factors.push_back(i);
				factors.push_back(j);
			}
		}
	}
	return factors;
}


int main (int argc, char * const argv[]) {

    cout << "enter the number you would like the two to multiply to get:";
	int multi = GetInteger();
	cout << "is it negative?";
	if(GetLine()[0]=='y')
		multi *= -1;
	cout << "enter the other number (adding) ";
	int add = GetInteger();
	cout << "is it negative?";
	if(GetLine()[0]=='y')
		add *= -1;
	
	vector <int> possibles = FindFactors(multi);
			
	cout << "\n";
	
	for (int j = 0; j < possibles.size(); j += 2) {
			cout << "the numbers are ";
			cout << possibles[j];
			cout << " and ";
			cout << possibles[j+1];
			cout << "\n";
		}
    return 0;
}