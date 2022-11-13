#include <iostream>
#include <fstream>
#include <string>
#include "hw4.h"
using namespace std;

const int MAX = 20;

int main(){

	ifstream gfile;
	gfile.open("graph.txt");

	string str;
	int numVertices;
	int numEdges; 
	char *alphaList = new char[MAX];
	char *vList = new char[MAX];
	char *uList = new char[MAX];
	char *wList = new char[MAX];

	if (gfile.is_open()){
		gfile >> str; 
		numVertices = stoi(str);

		for(int i=0; i<numVertices; i++){
			gfile >> str; 
			alphaList[i] = str[0];
		}

		int i = 0;
		while (gfile){
			gfile >> str;
				vList[i] = str[0];
			gfile >> str;
				uList[i] = str[0];
			gfile >> str;
				wList[i] = str[0];
			
			numEdges = i;
			i++;
			 
		}
	}
	
	/*INITIALIZING GRAPH WITH NUMBER OF VERTICES AND VERTICES*/	
	Graph g(0);	

	for(int i=0;i<numVertices; i++){
		cout << "sending alphaList[i]: " << alphaList[i] << " \n";
		g.addVertex(alphaList[i]);
	}

	/*CREATING GRAPH BY ADDING EDGES*/
	for(int i=0; i<numEdges; i++){
		cout << "v: " << vList[i] << "  u: " << uList[i] << "  w: " << wList[i] << "\n"; 
		
		g.addEdge(vList[i], uList[i], wList[i]);
	}

	/*PRINT IF GRAPH IS COMPLETE*/
	if (g.isComplete() == true)
		cout << "Graph is complete\n";
	else
		cout << "Graph is not complete\n";

	/*DISPLAY NUMBER OF EDGES*/
	cout << "number of edges: " << g.nEdges() << "\n";

	/*PRINT IF THERE IS AN EDGE FROM A TO F*/
	if (g.edgeExists('a','f'))
		cout << "There is a vertex from a to f\n";
	else 
		cout << "There is not vertex from a to f\n";

	/*GET WEIGHT FROM B to H */
	cout << "Weight from B to H: " << g.getWeight('b', 'h') << "\n";

	/*DISLAY DEGREE OF C*/
	cout << "Degree of c: " << g.degree('c') << "\n";

	/*DISPLAY NUMBER of VERTICES IN GRAPH*/
	cout << "Number of vertices: " << g.getNumVertices() << "\n";

	/*ADDING VERTICES AND EDGES*/
	g.addVertex('k');
	g.addEdge('k','a', '5');
	g.addEdge('g','k','2');
	g.setWeight('a','c','7');

	/*DISPLAYING GRAPH*/
	g.print();

}

