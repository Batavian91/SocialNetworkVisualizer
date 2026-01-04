#include "Edge.h"
#include <graphics.h>

unsigned int Edge::global_edge_id = 0;
unsigned int Edge::active_edges = 0;

Edge::Edge()
	: uid(++global_edge_id),
	start(nullptr), end(nullptr)
{
	++active_edges;
}

Edge::~Edge()
{
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

Node* Edge::getStart() const
{
	return start;
}

Node* Edge::getEnd() const
{
	return end;
}

void Edge::draw()
{
	graphics::Brush br; 

	
	br.outline_opacity = 0.5f;
	br.outline_width = 100;
	br.outline_color[0] = 1.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;
 
	graphics::drawLine(start->draw_rect->x, start->draw_rect->y, end->draw_rect->x, end->draw_rect->y,br);
}
