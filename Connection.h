#pragma once
#include "Edge.h"

class Connection : public Edge
{
public:
	// Connection constructor
	Connection();

	// Connection destructor
	~Connection();

	// implements base's class function 
	// draw() - connects two Persons
	void draw() override;
};