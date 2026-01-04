#pragma once
#include "Edge.h"
#include "Node.h"
#include <unordered_map>

class Graph
{
private:
	// A data structure, so that the Graph is aware
	// of its Nodes.
	std::unordered_map<unsigned int, Node*> map_of_nodes;

	// A data structure, so that the Graph is aware
	// of its Edges.
	std::unordered_map<unsigned int, Edge*> map_of_edges;

public:
	//Graph constructor
	Graph();

	// Graph destructor
	~Graph();

	// This method creates a new Node by allocating
	// heap memory. Returns the unique id of the
	// new Node.
	unsigned int addNode();

	// Removes a node from the graph. Before the node's
	// removal, all the edges connected to the node are
	// also removed.
	void removeNode(unsigned int);

	// This method creates a new Edge by allocating
	// heap memory. It is responsible for creating
	// the connection between the Edge with the two
	// Nodes the Edge connects.
	// Returns the unique id of the new Edge.
	unsigned int addEdge(Node*, Node*);

	// Removes an edge. The edge's destructor is
	// responsible to remove the connection between
	// the edges and any nodes it connects.
	void removeEdge(unsigned int);

	Node* getNode(unsigned int);

	void draw();
};