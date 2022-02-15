//Nick Krisulevicz
//COSC 320 - Lab 2
//binSearch.h
//02/15/2022

#ifndef BINSEARCH
#define BINSEARCH
#include <iostream>
using namespace std;

int * binSearch(int arr[],int y,int z,int x){
	int temp[2]={0};
	while(y <= z){
		int mid = y + (z - y) / 2;
		if (arr[mid] == x){	
			temp[0]++;
			temp[1] = mid;
			return temp;
		}
		if (arr[mid] < x){
			temp[0]++;
			y = mid+1;
		}
		else{
			temp[0]++;
			z = mid-1;
		}
	}
	temp[1] = -1;
	return temp;
}
#endif
