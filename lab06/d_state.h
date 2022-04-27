//Nick Krisulevicz
//COSC 320
//Lab 6
//03/18/2022
//d_state.h

#ifndef STATECITY_CLASS
#define STATECITY_CLASS

#include <iostream>
#include <string>

using namespace std;

class stateCity
{
	public:
		
		string stateName, cityName;
		
		stateCity (const string& name = "", const string& city = ""){
            stateName = name;
            cityName = city;
        }

		string getstatename(){
			return stateName;
		}
		
		string getcityname(){
			return cityName;
		}

		friend ostream& operator<< (ostream& ostr, const stateCity& state){
            ostr << state.cityName << ", " << state.stateName <<endl;

        }
		
		friend bool operator< (const stateCity& a, const stateCity& b){
           return a.stateName < b.stateName;
        }
		
		friend bool operator== (const stateCity& a, const stateCity& b){
            return a.stateName == b.stateName;
        }

};

#endif