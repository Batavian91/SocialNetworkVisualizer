#include "Edge.h"

#ifdef _DEBUG
#include <iostream>
#endif

unsigned int Edge::global_edge_id = 0;
unsigned int Edge::active_edges = 0;

Edge::Edge()
	: uid(++global_edge_id),
	start(nullptr), end(nullptr),
	VisualAsset(0.0f, 0.0f)
{
#ifdef _DEBUG
	std::cout << "Edge constructor: " << uid << std::endl;
#endif

	++active_edges;
}

Edge::~Edge()
{
#ifdef _DEBUG
	std::cout << "Edge destructor: " << uid << std::endl;
#endif

	if (start != nullptr)
	{
		// remove this edge from the Node's vector
		start->removeEdgeConnection(uid);

		// set pointer to null
		start = nullptr;
	}

	if (end != nullptr)
	{
		// remove this edge from the Node's vector
		end->removeEdgeConnection(uid);

		// set pointer to null
		end = nullptr;
	}

	--active_edges;
}

unsigned int Edge::getActiveEdges()
{
	return active_edges;
}

unsigned int Edge::getUID() const
{
	return uid;
}

void Edge::setStartingNode(Node* newStart)
{
	// avoid cycles in Nodes
	if (end == newStart)
		return;

	// the edge's starting Node points to newStart
	start = newStart;
}

void Edge::setEndingNode(Node* newEnd)
{
	// avoid cycles in Nodes
	if (start == newEnd)
		return;

	// the edge's ending Node points to newEnd
	end = newEnd;
}

Node* Edge::getStartingNode() const
{
	return start;
}

Node* Edge::getEndingNode() const
{
	return end;
}