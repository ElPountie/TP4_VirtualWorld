#include "shapemanager.h"


ShapeManager::ShapeManager() : Observable(), selected(nullptr)
{}

void ShapeManager::add(Circle* shape)
{
	if (shape == nullptr) return;

	shapes.append(shape);
	notifyObserver();
}


void ShapeManager::moveShape(QPointF pos)
{
	if (selected == nullptr) return;

	selected->pos = pos;
}

bool ShapeManager::selectShape(int id)
{
	selected = nullptr;
	for (Circle* shape : shapes)
	{
		if (shape->id == id)
		{
			selected = shape;
			return true;
		}
	}

	return false;
}
