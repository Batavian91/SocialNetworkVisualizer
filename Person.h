#pragma once
#include "Node.h"
#include "Rectangle.h"

class Person : public Node,
	public Rectangle
{
private:
	// a person's name
	const std::string name;

public:
	// Person constructor
	Person(float, float, float, float, 
		const std::string&, const std::string&);

	// Person destructor
	~Person();

	const std::string& getName() const;

	void draw() override;
};