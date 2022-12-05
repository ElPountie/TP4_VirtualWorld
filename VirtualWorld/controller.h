#pragma once
#include "shapemanager.h"
#include <QPointF>
#include <qtreewidget.h>

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

class ControllerRemove {
private:
	ShapeManager* shapeManager;
public:
	ControllerRemove(ShapeManager* = nullptr);
	void control(QVector<QVariant> list);
	void control(QVector<QTreeWidgetItem*> list);
};
