#pragma once
#include "Edge.h"
#include <vector>
#include <unordered_map>

/*
 * Class Node represents a node in a graph.
 * A node is connected with other nodes with
 * the help of edges.
 * Edge and Node have circular dependency
 * (same as the example that was
 * demonstrated in Lectures about classes
 * (see CPP_10_Classes.pdf -> p. 28-29)
 */

 // forward declaration to avoid circular dependency
class Edge;

class Node
{
private:
	// a generator of unique ids
	static unsigned int global_node_id;

	// a counter that holds the number 
	// of active nodes
	static unsigned int active_nodes;

	// a unique id for each node
	const unsigned int uid;

	// each node has a map of pointers to 
	// the edges thar are connected to it
	std::unordered_map<unsigned int, Edge*> connected_edges;

public:
	// Node constructor
	Node();

	// Node destructor -> virtual
	// Node can be used as a base class
	virtual ~Node();

	// active nodes getter
	static unsigned int getActiveNodes();

	// unique id getter
	unsigned int getUID() const;

	// This method is called by a Graph instance.
	// When an edge is connected to a node, the node 
	// stores a pointer to that edge by inserting it 
	// to a map (declared in private section).
	void addEdgeConnection(Edge*);

	// This method is called by an Edge instance.
	// The edge passes its unique id, so that the 
	// node removes its connection with the specific edge.
	void removeEdgeConnection(unsigned int);

	// To remove a Node from the Graph, first we need
	// to remove all its connected Edges. This is a 
	// getter for the Node's connected edges.
	std::vector<unsigned int> getConnectedEdges() const;

	// pure virtual - returns x-axis coordinate
	virtual float getX() const = 0;

	// pure virtual - returns y-axis coordinate
	virtual float getY() const = 0;

	// pure virtual - draws a Node 
	virtual void draw(float, float, float, float) = 0;
};