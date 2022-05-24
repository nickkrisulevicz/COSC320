//Nick Krisulevicz
//COSC 320
//Lab 10
//lab_10.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "d_graph.h"
#include "d_util.h"
using namespace std;

int main(){
    //create the stream to the input file
    ifstream inputfile("graphB.dat");
    //initialize your variables
    graph<string> chungus;
    int vert;
    int edge;

    //put the vertex into the graph from the input file
    inputfile >> vert;
    for (int i = 0; i < vert; i++)
    {
        string tempstring;
        inputfile >> tempstring;

        chungus.insertVertex(tempstring);
    }

    //put the edges into the graph from the input file
    inputfile >> edge;
    for (int i = 0; i < edge; i++)
    {
        string one;
        string two;
        int w;
        inputfile >> one >> two >> w;

        chungus.insertEdge(one, two, w);
    }

    //prompt the user to give a vertex to start from for the graph traversal
    string userVert;
    cout << "Input a vertex: ";
    cin >> userVert;

    //create a set for the visited vertices
    set<string> visitedVertices = bfs(chungus, userVert);

    //begin the BFS traversal
    set<string>::iterator first = visitedVertices.begin();
    set<string>::iterator last = visitedVertices.end();
    writeContainer(first, last, " ");

    list<string> reverseVert = {"F", "E", "D", "C", "B", "A"};
    dfs(chungus, reverseVert);

    //begin the DFS traversal
    list<string>::iterator first2 = reverseVert.begin();
    list<string>::iterator last2 = reverseVert.end();
    cout << endl;
    writeContainer(first2, last2, " ");
    cout << endl;

    return 0;
}
