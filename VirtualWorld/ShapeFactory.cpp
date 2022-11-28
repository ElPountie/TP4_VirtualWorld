#include "ShapeFactory.h"

ShapeFactory::ShapeFactory(ShapeManager* sm) : shapeManager(sm)
{
}

void ShapeFactory::create(QString shape)
{
	if (shape == "Circle") {
		shapeManager->add(new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
	}
	else if (shape == "Rectangle") {
		shapeManager->add(new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100, std::rand() % 100));
	}
	else if (shape == "Square") {
		shapeManager->add(new Carre(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
	}
}
