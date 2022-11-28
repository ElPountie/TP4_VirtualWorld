#include "ShapeFactory.h"

ShapeFactory::ShapeFactory(ShapeManager* sm) : shapeManager(sm)
{
}

Shape* ShapeFactory::create(QString shape)
{
	if (shape == "Circle") {
		return new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100);
	}
	else if (shape == "Rectangle") {
		return new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100, std::rand() % 100);
	}
	else if (shape == "Square") {
		return new Carre(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100);
	}
	else {
		return nullptr;
	}
}
