//Nick Krisulevicz
//COSC 320
//Lab 09
//Make a graph and write to graphA.dat file
//04/12/2022
//lab_09.cpp

#include "d_graph.h"
#include "d_graph.h"
#include "d_heap.h"
#include <set>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	cout << "Begin program" << endl; //temporary cout statement to see if program works
	
	ifstream output("graphA.dat"); //open the file graphA.dat
	
	graph<string> g; //create a graph object
	cout << "setup graph" << endl;	
	string A = "A"; //create a char for each vertex
	string B = "B";
	string C = "C";
	string D = "D";
	string E = "E";
	string F = "F";
	int w = 1; //create an int for weight and set it to 1 since weight of all edges in this graph are 1

	output.is_open();
	int vertex;
	int edge;
	cout << "First for loop" << endl; //temporary print statement to see if first for loop works
	output >> vertex; //to write vertex from the output file
	for(int i = 0; i < vertex; i++){ //for each vertex, execute the loop
		string t;
		output >> t; //get t from the file
		g.insertVertex(t); //insert the vertex into the graph
	}
	cout << "Second for loop" << endl;
	output >> edge; //to write edge from output file
	for(int i = 0; i < edge; i++){ //for each edge, execute the loop
		string e1, e2; //t1 and t2 which are the vertices of the edge from the file
		int weight;
		output >> e1 >> e2 >> weight; //get the edge from the file
		g.insertEdge(e1, e2, weight); //insert the edge into the graph
	}

	g.insertEdge(F, D, w); //insert F to D weight 1 for task i
	
	g.eraseVertex(B); //delete vertex B for task ii
	
	g.eraseEdge(A, D); //delete edge A to D for task iii

	cout << "Enter a vertex to see its neighbors" << endl; //task iv prompt user to input an edge and display a set of its neighbors
	string userinput; //declare variable for user input
	cin >> userinput; //assign value from user input
	set<string> s = g.getNeighbors(userinput); //create a set of neighbors of the vertex the user input
	cout << "Neighbors:" << endl;
	set<string>::iterator iter; //create an iterator from the class and make a set of them
	for(iter = s.begin(); iter != s.end(); ++iter){ //while there are neighbors, get the neighbors
		string v = *iter; //use the iterator to iterate through the file
		cout << v << endl; //print each edge
	}

	string G = "G";
	g.insertVertex(G); // task v insert a new vertex G

	g.insertEdge(G, C, w); //task vi insert three new edges to vertex G
	g.insertEdge(G, F, w); //the new edges include C, F
	g.insertEdge(D, G, w); //and D

	cout << g << endl; //task vii output the graph using << operator

	output.close(); //close graphA.dat

	return 0;
}
