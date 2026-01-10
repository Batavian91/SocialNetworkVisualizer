#pragma once
#include "Connection.h"
#include "Person.h"

class Graph
{
private:
	// A data structure, so that the Graph is aware
	// of its Nodes (Persons).
	std::unordered_map<unsigned int, Person*> map_of_nodes;

	// A data structure, so that the Graph is aware
	// of its Edges (Connections).
	std::unordered_map<unsigned int, Connection*> map_of_edges;

public:
	//Graph constructor
	Graph();

	// Graph destructor
	~Graph();

	// This method creates a new Node by allocating
	// heap memory. Returns the unique id of the
	// new Node.
	unsigned int addNode(float, float, float, float,
		const std::string&, const std::string&);

	// Removes a node from the graph. Before the node's
	// removal, all the edges connected to the node are
	// also removed.
	void removeNode(unsigned int);

	// This method creates a new Edge by allocating
	// heap memory. It is responsible for creating
	// the connection between the Edge with the two
	// Nodes the Edge connects.
	// Returns the unique id of the new Edge.
	unsigned int addEdge(unsigned int, unsigned int);

	// Removes an edge. The edge's destructor is
	// responsible to remove the connection between
	// the edges and any nodes it connects.
	void removeEdge(unsigned int);

	// Draws a graph with nodes and edges.
	void draw();

	// Updates the current graph.
	void update();
};