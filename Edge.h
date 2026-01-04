#pragma once
#include "Node.h"

/*
 * Class Edge represents an edge that
 * connects two nodes in a graph.
 * Edge and Node have circular dependency
 * (same as the example that was
 * demonstrated in Lectures about classes
 * (see CPP_10_Classes.pdf -> p. 28-29)
 */

 // forward declaration to avoid circular dependency
class Node;

class Edge
{
private:
	// a generator of unique ids
	static unsigned int global_edge_id;

	// a counter that holds the number 
	// of active edges
	static unsigned int active_edges;

	// a unique id for each edge
	const unsigned int uid;

	// An edge can connect only two nodes,
	// therefore it needs two Node pointers,
	// start and end.
	// The sequence of the nodes is irrelevant,
	// since our graph is undirected.
	Node* start, * end;

public:
	// Edge constructor
	Edge();

	// Edge destructor
	~Edge();

	// active edges getter
	static unsigned int getActiveEdges();

	// unique id getter
	unsigned int getUID() const;

	// connects the Edge to the first Node
	void setStartingNode(Node*);

	// connects the Edge to the second Node
	void setEndingNode(Node*);

	// first connected Node getter
	Node* getStart() const;

	// second connected Node getter
	Node* getEnd() const;
};