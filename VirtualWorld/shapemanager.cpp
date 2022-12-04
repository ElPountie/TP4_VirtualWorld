#include "shapemanager.h"


ShapeManager::ShapeManager() : Observable(), selected(nullptr)
{}

void ShapeManager::add(Shape* shape)
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

void ShapeManager::removeShape(int id)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes.at(i)->id == id) {
			shapes.remove(i);
		}
	}
}

bool ShapeManager::selectShape(int id)
{
	selected = nullptr;
	for (auto shape : shapes)
	{
		if (shape->id == id)
		{
			selected = shape;
			return true;
		}
	}

	return false;
}
