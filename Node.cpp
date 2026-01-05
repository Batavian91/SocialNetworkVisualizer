#include "Node.h"

#ifdef _DEBUG
#include <iostream>
#endif

unsigned int Node::global_node_id = 0;
unsigned int Node::active_nodes = 0;

Node::Node()
	: uid(++global_node_id)
{
#ifdef _DEBUG
	std::cout << "Node constructor: " << uid << std::endl;
#endif

	++active_nodes;
}

Node::~Node()
{
#ifdef _DEBUG
	std::cout << "Node destructor: " << uid << std::endl;
#endif

	--active_nodes;
}

unsigned int Node::getActiveNodes()
{
	return active_nodes;
}

unsigned int Node::getUID() const
{
	return uid;
}

void Node::addEdgeConnection(Edge* edge)
{
	connected_edges.insert({ edge->getUID(), edge });
}

void Node::removeEdgeConnection(unsigned int edgeId)
{
	size_t result = connected_edges.erase(edgeId);

#ifdef _DEBUG
	if (result)
		std::cout << "Edge " << edgeId << " was successfully"
		<< " removed from Node " << uid << std::endl;
	else
		std::cout << "Edge " << edgeId << " was not found"
		<< std::endl;
#endif
}

std::vector<unsigned int> Node::getConnectedEdges() const
{
	std::vector<unsigned int> edges;
	std::unordered_map<unsigned int, Edge*>::const_iterator iter;
	for (iter = connected_edges.begin();
		iter != connected_edges.end();
		++iter)
		edges.push_back(iter->first);

	return edges;
}