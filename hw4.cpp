#include <iostream>
#include <fstream>
#include <string>
#include "hw4.h"
using namespace std; 


Graph::Graph(){
	this->nVertices = 0; 
}

Graph::Graph(int n){
	this->nVertices = n;
	for(int i=0; i<this->maxVertices; i++){
		for(int j=0; j<this->maxVertices; j++){
			this->graph[i][j] = '0';
		}
	}
}

Graph::Graph(int n, bool digraph){
	this->nVertices = n;
	this->digraph = digraph;

	for(int i=0; i<this->maxVertices; i++){
		for(int j=0; j<this->maxVertices; j++){
			this->graph[i][j] = '0';
		}
	}
}

int Graph::getNumVertices(){
	return this->nVertices;
}

/*given a 2d array representation, a graph is undirected if the */
/*array and its transpose are the same */
bool Graph::isDirect(){
	
	for(int i=0; i<this->nVertices; i++){
		for(int j=0; i<this->nVertices; i++){
			if (this->graph[i][j] != this->graph[j][i])
				return true;
		}
	}
	return false;
}

bool Graph::adjacent(char v, char u){
	int indexV, indexU;
	for(int i=0; i<this->nVertices; i++){
		if (alpha_vertices[i] == v)
			indexV = i;
		if (alpha_vertices[i] == u)
			indexU = i; 
	}
	if (this->graph[indexV][indexU] != '0')
		return true; 
	
	return false;
}

char *Graph::neighbors(char v){
	char *neighborList = new char[MAX_SIZE];
	int indexV; 

	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = i;
	}
	
	for(int i=0; i<this->nVertices; i++){
		int j=0;
		if (this->graph[indexV][i] != '0'){
			neighborList[j] = this->alpha_vertices[i];
			j++;
		}
	}
	return neighborList;
}

void Graph::addVertex(char v){
	this->alpha_vertices[nVertices] = v;
	this-nVertices++;

	cout << "******adding vertex****** " << " alpha_vertices[nVertices]: " << v << " added \n";
}

void Graph::removeVertex(char v){
	int indexV;
	
	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = i;
	}
	
	for(int i=indexV; i<this->nVertices; i++){
		int temp_v = alpha_vertices[i];
		alpha_vertices[i] = alpha_vertices[i+1];
	}
	this->alpha_vertices[nVertices] ='\0';
}

void Graph::addEdge(char v, char u){
	int indexV, indexU; 
	
	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = v;
		if (this->alpha_vertices[i] == u)
			indexU = u;
	}

	this->graph[indexV][indexU] = '1';
}


void Graph::addEdge(char v, char u, char w){
	int indexV, indexU;

	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = i;
		if (this->alpha_vertices[i] == u)
			indexU = i;
	}
  this->graph[indexV][indexU] = w;

	cout << "********adding edge*******: " << v << " " << u << " " <<  this->graph[indexV][indexU] << "\n";
}

void Graph::removeEdge(char v, char u){
	int indexV, indexU;

	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = v;
		if (this->alpha_vertices[i] == u)
			indexU = u;
	}
	
	this->graph[indexV][indexU] = '0';
}

char Graph::getWeight(char v, char u){
	int indexV, indexU;

	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] ==v)
			indexV = i;
		if (this->alpha_vertices[i] == u)
			indexU = i;
	}
	return this->graph[indexV][indexU];
}

void Graph::setWeight(char v, char u, char w){
	int indexV, indexU;
		 
	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			indexV = i;
	  if (this->alpha_vertices[i] == u)
	    indexU = i;
	}
	this->graph[indexV][indexU] = w;
}

bool Graph::isEmpty(){
	for(int i=0; i<this->nVertices; i++){
		for(int j=0; j<this->nVertices; j++){
			if (this->graph[i][j] != '0')
				return false;
		}
	}
	return true; 
}

bool Graph::isComplete(){
	
	for(int i=0; i<this->nVertices; i++){
		for(int j=0; j<this->nVertices; j++){
			if (i==j){
				if (this->graph[i][j] != '0')
					return false;
			}
			if (i!=j){
				if (this->graph[i][j] != this->graph[j][i])
					return false;
			}
		}
	}
	return true; 
}

char* Graph::vertices(){
	return this->alpha_vertices;
}


int Graph::degree(char v){
	int indexV;
	int deg = 0;
	

	for (int i=0; i<this->nVertices; i++){
		if (alpha_vertices[i] == v)
			indexV = i;
	}


	for(int i=0; i<this->nVertices; i++){
		if (this->graph[indexV][i] != '0'){
			deg++;
		}
		if (this->graph[i][indexV] != '0'){
			deg++;
		}
	}
	return deg;
}

int Graph::size(){
	return this->nVertices;
}

int Graph::nEdges(){
	int nEdg = 0;

	for(int i=0; i<this->nVertices; i++){
		for(int j=0; j<this->nVertices;j++){
			if (this->graph[i][j] != '0')
				nEdg++;
		}
	}
	return nEdg;
}

void Graph::clear(){
	for(int i=0; i<this->nVertices; i++){
		for(int j=0; j<this->nVertices; j++){
			this->graph[i][j] = '0';
		}
	}
	this->nVertices = 0;
}

bool Graph::vertexExists(char v){
	
	for(int i=0; i<this->nVertices; i++){
		if (this->alpha_vertices[i] == v)
			return true;
	}
	return false; 
}

bool Graph::edgeExists(char v, char u){
	
	int indexV, indexU; 

	for(int i=0; i<this->nVertices; i++){
		if(alpha_vertices[i] == v)
			indexV = i;
		if(alpha_vertices[i] == u)
			indexU = i;
	}

	return(this->graph[indexV][indexU] != '0');
}

void Graph::print(){

	cout << "******printing graph****** \n";
	
	cout << "numVertices: " << this->nVertices << "\n"; 

	for(int i=0; i<this->nVertices; i++)
		cout << alpha_vertices[i] << " "; 
	cout << "\n";

	for(int i=0; i<this->nVertices; i++){
		for(int j=0; j<this->nVertices; j++){
			if (this->graph[i][j] != '0')
				cout << this->alpha_vertices[i] << " " << this->alpha_vertices[j] << " " << this->graph[i][j] << "\n";
		}
	}
}
