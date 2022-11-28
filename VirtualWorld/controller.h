#pragma once
#include "shapemanager.h"
#include <QPointF>

class ControllerAdd
{
	ShapeManager* shapeManager;
public:
	ControllerAdd(ShapeManager* = nullptr);
	void control(QString forme);
};

class ControllerMoveShape
{
	ShapeManager* shapeManager;
public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};
