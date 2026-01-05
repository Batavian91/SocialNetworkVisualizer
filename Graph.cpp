#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	std::unordered_map<unsigned int, Edge*>::iterator e_iter;

	for (e_iter = map_of_edges.begin(); e_iter != map_of_edges.end(); ++e_iter)
		delete e_iter->second;

	std::unordered_map<unsigned int, Node*>::iterator n_iter;

	for (n_iter = map_of_nodes.begin(); n_iter != map_of_nodes.end(); ++n_iter)
		delete n_iter->second;
}

unsigned int Graph::addNode()
{
	Node* node = new Node;
	map_of_nodes.insert({ node->getUID(), node });

	return node->getUID();
}

void Graph::removeNode(unsigned int nodeId)
{
	std::unordered_map<unsigned int, Node*>::iterator iter =
		map_of_nodes.find(nodeId);

	if (iter != map_of_nodes.end())
	{
		// first remove all connected edges
		for (unsigned int uid : iter->second->getConnectedEdges())
			removeEdge(uid);

		// delete node
		delete iter->second;

		// remove node from map
		map_of_nodes.erase(iter);
	}
}

unsigned int Graph::addEdge(Node* n1, Node* n2)
{
	Edge* edge = new Edge;
	map_of_edges.insert({ edge->getUID(), edge });

	// add edge to the first node
	n1->addEdgeConnection(edge);
	// add first node to the edge
	edge->setStartingNode(n1);

	// add edge to the second node
	n2->addEdgeConnection(edge);
	// add second node to the edge
	edge->setEndingNode(n2);

	return edge->getUID();
}

void Graph::removeEdge(unsigned int edgeId)
{
	std::unordered_map<unsigned int, Edge*>::iterator iter =
		map_of_edges.find(edgeId);

	if (iter != map_of_edges.end())
	{
		// delete edge
		delete iter->second;

		// remove edge from map
		map_of_edges.erase(iter);
	}
}
Node* Graph::getNode(unsigned int nodeId)
{
	return map_of_nodes[nodeId];
}

void Graph::draw() 
{
	float x = 0;
	float y = 200;
	for (std::pair<unsigned int, Node*> node: map_of_nodes) 
	{
		x += 100;
		y = y == 200 ? 300 : 200;
		node.second->draw(x, y, 60.0f, 60.0f);
	}
	for (std::pair<unsigned int, Edge*> edge: map_of_edges) 
	{
		edge.second->draw();
	} 
}