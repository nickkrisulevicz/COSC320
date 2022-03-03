//Nick Krisulevicz
//COSC 320 - HW 02 - Find whether a string is a palindrome using recursion
//pal.cpp
//02/25/2022

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isPalRec(char str[], int size, int n){
    	if (size == n)
    	return true;

    	if (str[size] != str[n])
    	return false;
 
    	if (size < n + 1)
    	return isPalRec(str, size + 1, n - 1);

    	return true;
}
 
bool isPalindrome(char str[])
{
   	int n = strlen(str);

    	if (n == 0)
        return true;
     
	return isPalRec(str, 0, n - 1);
}

int main()
{
	string st;
	cout << "Enter a word with no spaces" << endl;
   	getline(cin, st);
	
	int size = st.length();
	char str[size];
	
	for(int i = 0; i < size; i++){
		str[i] = st[i];
	}
	
	if (isPalindrome(str))
    	cout << "Yes it is a palindrome" << endl;
   	else
    	cout << "No it is not a palindrome" << endl;
 
    return 0;
}
