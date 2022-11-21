#pragma once

#include "shape.h"
#include "observer.h"
#include <QVector>
#include <QPointF>

class ShapeManager : public Observable
{
private:
	QVector<Circle*> shapes;
	Circle* selected;

public:
	ShapeManager();
	void add(Circle*);
	void moveShape(QPointF);

	bool selectShape(int);

    const QVector<Circle*>& getShapes() const {return shapes;}
};

