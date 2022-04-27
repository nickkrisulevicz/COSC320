//Nick Krisulevicz
//COSC 320
//Lab 07
//03/29/2022
//lab_07.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "d_hashf.h"
#include "d_hash.h"
#include "d_except.h"
using namespace std;

void getWord(ifstream& fin, string& w);

int main(){
    int thekey = 1373;
    myhash<string, hFstring>htable(thekey);

    ifstream sptst ("dict.dat");
    if(sptst.is_open()){
        string theword;
        for(int i = 0; i < 25025; i++){
            sptst >> theword;
            htable.insert(theword);
        }
    }else{
        cout << "File DNE" << endl;
    }

    sptst.close();
    string thedoc;
    cout << "Enter the document name: " << endl;
    cin >> thedoc;

    ifstream usrFile (thedoc + ".txt");

    string theword;
    if(usrFile.is_open()){
        while(!usrFile.eof()){
			getWord(usrFile, theword);
            if(htable.end() == htable.find(theword)){
                cout << theword << endl;
            }
        }
        usrFile.close();
    }else{
        cout << "File not found" << endl;
    }


}

void getWord(ifstream& fin, string& w)
{
	char c;
	w = "";	
	while (fin.get(c) && !isalpha(c))
		;	
	if (fin.eof())
		return;
	w += tolower(c);
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);
}
