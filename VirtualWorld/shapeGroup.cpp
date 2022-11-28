#include "shape.h"

Groupe::Groupe()
{
	id = current_id++;
	pos = QPointF(-1, -1);
}

void Groupe::add(Shape* sh) {
	listOfShape.append(sh);
}

void Groupe::remove(Shape* sh)
{
	listOfShape.remove(listOfShape.indexOf(sh));
}

QVector<Shape*> Groupe::getListofShape()
{
	return listOfShape;
}

QGraphicsItem* Groupe::getGraphicsItem() const
{
	return nullptr;
}

QString Groupe::type() const
{
	return "Groupe";
}

void Groupe::draw()
{
}