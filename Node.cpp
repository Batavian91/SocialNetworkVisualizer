#include "Node.h"
#include <graphics.h>

#ifdef _DEBUG
#include <iostream>
#endif

unsigned int Node::global_node_id = 0;
unsigned int Node::active_nodes = 0;

Node::Node()
	: uid(++global_node_id),
	m_x(0.0f), m_y(0.0f),
	m_width(0.0f), m_height(0.0f)
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

float Node::getX() const
{
	return m_x;
}

float Node::getY() const
{
	return m_y;
}

float Node::getWidth() const
{
	return m_width;
}

float Node::getHeight() const
{
	return m_height;
}

void Node::setX(float x)
{
	m_x = x;
}

void Node::setY(float y)
{
	m_y = y;
}

void Node::setWidth(float width)
{
	m_width = width;
}

void Node::setHeight(float height)
{
	m_height = height;
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

void Node::draw(float x, float y, float w, float h)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;

	graphics::Brush brush;

	brush.texture = "assets\\user.png";
	brush.outline_opacity = 0.0f;
	brush.fill_color[0] = 0.5f;
	brush.fill_color[1] = 0.0f;
	brush.fill_color[2] = 0.0f;

	graphics::drawRect(x, y, w, h, brush);
	graphics::drawText(x - w / 2, y + h, 30.0f,
		"Node " + std::to_string(uid), brush);
	graphics::resetPose();
}
