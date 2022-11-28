#pragma once
#include "shapemanager.h"
#include "controller.h"
class ShapeFactory
{
private:
	ShapeManager* shapeManager;
public:
	ShapeFactory(ShapeManager* sm);
	void create(QString shape);
};

