#include "Graph.h"
#include "Button.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	std::unordered_map<unsigned int, Connection*>::iterator e_iter;

	for (e_iter = map_of_edges.begin(); e_iter != map_of_edges.end(); ++e_iter)
		delete e_iter->second;

	std::unordered_map<unsigned int, Person*>::iterator n_iter;

	for (n_iter = map_of_nodes.begin(); n_iter != map_of_nodes.end(); ++n_iter)
		delete n_iter->second;
}

unsigned int Graph::addNode(float x, float y, float w, float h,
	const std::string& name, const std::string& path)
{
	Person* node = new Person(x, y, w, h, name, path);
	map_of_nodes.insert({ node->getUID(), node });

	return node->getUID();
}

void Graph::removeNode(unsigned int nodeId)
{
	std::unordered_map<unsigned int, Person*>::iterator iter =
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

unsigned int Graph::addEdge(unsigned int n1, unsigned int n2)
{
	Person* start = nullptr;
	Person* end = nullptr;
	std::unordered_map<unsigned int, Person*>::iterator iter;
	
	iter =	map_of_nodes.find(n1);
	if (iter != map_of_nodes.end())
		start = iter->second;

	iter =	map_of_nodes.find(n2);
	if (iter != map_of_nodes.end())
		end = iter->second;

	if (start && end)
	{
		Connection* edge = new Connection;
		map_of_edges.insert({ edge->getUID(), edge });

		// add edge to the first node
		start->addEdgeConnection(edge);
		// add first node to the edge
		edge->setStartingNode(start);

		// add edge to the second node
		end->addEdgeConnection(edge);
		// add second node to the edge
		edge->setEndingNode(end);

		return edge->getUID();
	}

	return 0;
}

void Graph::removeEdge(unsigned int edgeId)
{
	std::unordered_map<unsigned int, Connection*>::iterator iter =
		map_of_edges.find(edgeId);

	if (iter != map_of_edges.end())
	{
		// delete edge
		delete iter->second;

		// remove edge from map
		map_of_edges.erase(iter);
	}
}

void Graph::draw() 
{
	float x = 0.0f;
	float y = 200.0f;

	for (std::pair<unsigned int, Connection*> edge : map_of_edges)
	{
		edge.second->draw();
	}

	for (std::pair<unsigned int, Person*> node: map_of_nodes) 
	{
		x += 100.0f;
		y = y == 200.0f ? 300.0f : 200.0f;
		//node.second->draw(x, y, 60.0f, 60.0f);
	}

}

void Graph::update()
{
}