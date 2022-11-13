#ifndef HW4_H
#define HW4_H
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class Graph {



	private:
		int nVertices;
		int maxVertices = MAX_SIZE;
		char alpha_vertices[MAX_SIZE];
		char graph[MAX_SIZE][MAX_SIZE];
		bool digraph;

	public:	

		Graph();
		Graph(int n);
		Graph(int n,bool digraph);

		int getNumVertices();
		bool isDirect(); 
		bool adjacent(char v, char u); 
		char* neighbors(char v); 
		void addVertex(char v);
		void removeVertex(char v); 
		void addEdge(char v, char u);
		void addEdge(char v, char u, char w);
		void removeEdge(char v, char u);
		char getWeight(char v, char u);
		void setWeight(char v, char u, char w); 
		bool isEmpty();
		bool isComplete(); 
	  char* vertices();
		char* edges();
		int degree(char v);
		int size();
		int nEdges();
		void clear();
		bool vertexExists(char v);
		bool edgeExists(char v, char u);
		void print(); 

};

#endif
