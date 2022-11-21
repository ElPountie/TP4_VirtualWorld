#pragma once
#include <QPointF>
#include <QGraphicsItem>


class Circle
{
private:
	double radius;
public: 
	QPointF pos;
	int id;
	static int current_id; // added

	Circle();
	Circle(QPointF, double);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;
};
