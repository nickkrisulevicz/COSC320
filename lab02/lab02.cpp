//Nick Krisulevicz
//COSC 320 - Lab 2
//lab02.cpp
//02/15/2022

#include <iostream>
#include "binSearch.h"
using namespace std;

void deSelsort(int arr[], int size);

int main(){
	int size = 10000;
	int arr[size];
	
	for(int i = 0; i < size; i++)
		arr[i] = rand()%100000;
	
	deSelsort(arr, size);

	int sumFailCom = 0;
	int successTotal = 0;
	
	for(int i = 0; i < size; i++){
		int x = rand()%100000;
		int * found = binSearch(arr, 0, 9999, x);
		if(found[1] == -1)
			sumFailCom += found[0];
		else
			successTotal++;
	}
	
	float worstcom = (float) sumFailCom / (size - (float) successTotal);
	
	cout << "Total comparisons made in unsuccessful searches: " << sumFailCom << endl;
	cout << "Total successful searches are: " << successTotal << endl;
	cout << "Worst case comparison for an unsuccessful binary search: " << worstcom << endl;
	
	return 0;
}

void deSelsort(int arr[], int size){
	int s = 0;
	int t = size;
	int temp;
	while(s < size && t > 0){
		int min = s;
		int max = size;
		for(int i = s + 1; i < size; i++){
			if (arr[i] < arr[min]){
				min = i;
			}
		}
		temp = arr[s];
		arr[s] = arr[min];
		arr[min] = arr[temp];

		for(int j = t - 1; j > 0; j--){
			if (arr[j] > arr[max]){
				max = j;
			}
		}
		temp = arr[t];
		arr[t] = arr[max];
		arr[max] = temp;

		s++;
		t--;
	}
}
