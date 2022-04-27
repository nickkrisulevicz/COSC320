//Nick Krisulevicz
//COSC 320
//Lab 6
//03/18/2022
//lab06_map.cpp

#include <map>
#include "d_state.h"
#include <iostream>
#include <string>

using namespace std;

int main (){
	map<string, string>location;
	map<string,string>::iterator iter;
	
	location["Pennsylvania"] = "Philadelphia";
	location["Ohio"] = "Doylestown";
	location["Maryland"] = "Hagerstown";
	location["Maine"] = "Caribou";
	location["Delaware"] = "Laurel";

    string usersearch;
    cout << "Please enter a state that you would like to search for:" << endl;
    cin >> usersearch;

    iter= location.find(usersearch);
    if (iter != location.end()){
        cout << iter -> first << ", " << iter -> second << endl;
    }
    else {
        cout << "The state you entered has no cities in this database!" << endl;
    }
 
	return 0;
}
