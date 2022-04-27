//Nick Krisulevicz
//COSC 320
//Lab 6
//03/18/2022
//lab06_set.cpp

#include <set>
#include "d_state.h"
#include <iostream>
#include <string>

using namespace std;

int main (){
    set<stateCity> location;
	
    location.insert(stateCity("Pennsylvania", "Philadelphia"));
    location.insert(stateCity("Ohio", "Doylestown"));
    location.insert(stateCity("Maryland", "Hagerstown"));
    location.insert(stateCity("Maine", "Caribou"));
    location.insert(stateCity("Delaware", "Laurel"));
    
	string usersearch;
    cout << "Please enter a state that you would like to search for:" << endl;
    cin >> usersearch;
    
    bool locator = true;
    set<stateCity>::iterator iter;

    for (iter = location.begin(); iter != location.end(); iter++){
        if (iter -> stateName == usersearch){
            cout << "City found in state! : " << *iter << endl;
            locator = true;
            break;
        }
		else {
			locator = false;
        }

    }
	
    if ( locator == false){
		cout << "The state you entered has no cities in this database!" << endl;
    }
	
	return 0;
}