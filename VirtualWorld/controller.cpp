#include "controller.h"
#include "shapemanager.h"
#include "ShapeFactory.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(QString forme)
{
	if (shapeManager == nullptr) return;
	ShapeFactory* sf = new ShapeFactory(shapeManager);

	// Add Shape
	shapeManager->add(sf->create(forme));
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
	if (shapeManager == nullptr) return;

	// Move Shape
	for (QGraphicsItem* item : items)
	{
		QVariant variant = item->data(0);
		int id = variant.toInt();

		bool selected = shapeManager->selectShape(id);
		if (selected)
		{
			QRectF rect = item->boundingRect();
			shapeManager->moveShape(item->scenePos() + rect.center());
		}
	}

	shapeManager->notifyObserver();
}

ControllerRemove::ControllerRemove(ShapeManager* sm) : shapeManager(sm)
{
}

void ControllerRemove::control(QVector<QTreeWidgetItem*> list)
{	
	int i = 0;
	for (auto index : list) {
		shapeManager->removeShape(index->data(i, 0).toInt());
		i++;
	}

	shapeManager->notifyObserver();
}
