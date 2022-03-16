//Nick Krisulevicz
//COSC 320
//Lab 5 - Binary Search Trees
//03/08/2022
//lab_05.cpp

#include <iostream>
#include <utility>
#include <stdlib.h>
#include <ctime>
#include "int.h"
#include "d_stree.h"
#include "d_random.h"

using namespace std;

int main(){
	srand(time(0));
	int arr;
	stree<integer> integerTree;
	integer Clyde(0);
	for (int i = 0; i < 10000; i++){
		arr = rand() % 7;
		integer Jimmy(arr);
		if (integerTree.find(Jimmy) == integerTree.end()){
			cout << arr << " is in the tree" << endl;
			integerTree.insert(arr);
		}
		Clyde.incCount();
	}
	cout << "Count is: " << Clyde.getCount() << endl;

	return 0;
}
