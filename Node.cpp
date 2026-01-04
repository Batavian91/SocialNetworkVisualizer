#include "Node.h"

#ifdef _DEBUG
#include <iostream>
#endif
#include <graphics.h>

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
	delete draw_rect;
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

void Node::draw(float x,float y)
{ 
	graphics::Brush br; 

	br.texture = "assets\\user.png";
	
	br.outline_opacity = 0.0f;

	float width = 60;
	float height = width;
 
	graphics::drawRect(x, y, width, height, br);
	draw_rect = new Rectangle;
	draw_rect->x = x;
	draw_rect->y = y;
	draw_rect->width = width;
	draw_rect->height= height;

	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::resetPose();
	drawText(x-width/2, y + height, 30, "Node " + std::to_string(uid), br);
}
