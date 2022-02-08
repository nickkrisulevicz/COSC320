//Nick Krisulevicz
//COSC 320 - Lab 01
//02/08/2022
//lab01.cpp

#include "deSelsort.h"
#include <iostream>
using namespace std;

void deSelsort(int arr[], int size){
	int s = 0; //s and t are counter variables
	int t = size;
	int temp;
	while(s < size && t > 0){
		int min = s;
		int max = size;

		for(int i = s + 1; i < size; i++){ //for loop to sort from minimum end
			if(arr[i] < arr[min]){
				min = i;
			}
		}
		temp = arr[s];
		arr[s] = arr[min];
		arr[min] = temp;
		
		for(int j = t - 1; j > 0; j--){ //for loop to sort from maximum end
			if(arr[j] > arr[max]){
				max = j;
			}
		}
		temp = arr[t];
		arr[t] = arr[max];
		arr[max] = temp;


		s++; //increment the counter variables
		t--;
	}
	
}

int main(){
	int cap = 8;
	int array[cap] = {13, 5, 2, 25, 47, 17, 8, 21};
	
	cout << "The initial array is: ";
	for(int i = 0; i < cap; i++){
		cout << array[i] << " ";
	}
	cout << endl;

	deSelsort(array, cap);
	
	cout << "The sorted array is: ";
	for(int j = 0; j < cap; j++){
		cout << array[j] << " ";
	}
	cout << endl;

	return 0;
}
