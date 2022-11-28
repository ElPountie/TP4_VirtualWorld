#pragma once

#include "shape.h"
#include "observer.h"
#include <QVector>
#include <QPointF>

class ShapeManager : public Observable
{
private:
	QVector<Shape*> shapes;
	Shape* selected;

public:
	ShapeManager();
	void add(Shape*);
	void moveShape(QPointF);

	bool selectShape(int);

    const QVector<Shape*>& getShapes() const {return shapes;}
};

