//Nick Krisulevicz
//COSC 320
//Lab 11
//05/12/2022
//lab_11.cpp

#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include "d_graph.h"
#include "d_util.h"
using namespace std;

int main(){
    graph<string> graph;
    ifstream inputfile;
    inputfile.open("graphB.dat", ios::in);

    if(inputfile.is_open()){
        int vertices, edges, weight;
        string v1, v2;

        inputfile >> vertices;

        while(vertices != 0){
            inputfile >> v1;
            graph.insertVertex(v1);
            vertices--;
        }

        inputfile >> edges;

        while(edges != 0){
            inputfile >> v1 >> v2 >> weight;
            graph.insertEdge(v1, v2, weight);
            edges--;
        }
    }

    inputfile.close();

    string vertex;
    cout << "Enter a vertex: ";
    cin >> vertex;

    list<string> path;
    int minimum = 0;
    string v3;
    string mvert;
    int numverts;

    inputfile.open("graphB.dat", ios::in);
    inputfile >> numverts;

    while(numverts != 0){
        inputfile >> v3;

        if(minimumPath(graph, v3, vertex, path) > minimum){
            minimum = minimumPath(graph, v3, vertex, path);
            mvert = v3;
        }
        numverts--;
    }

    minimumPath(graph, mvert, vertex, path);

    cout << "Vertex with largest minimum path value: " << mvert << endl;
    cout << "Minimum path value: " << minimum << endl;
    cout << "Minimum path: ";
    writeContainer(path.begin(), path.end(), " ");
    cout << endl;
    inputfile.close();

    return 0;
}
