#include "shape.h"
#include <QGraphicsEllipseItem>

int Shape::current_id; // added

Circle::Circle()
{
	id = current_id++;
	pos = QPointF(-1, -1);
	radius = 0.;
}

Circle::Circle(QPointF p, double r) : radius(r)
{
	id = current_id++;
	pos = p;
}


QGraphicsItem* Circle::getGraphicsItem() const
{
	QBrush tmpBrush(Qt::SolidPattern);
	if (color == "Red") {
		tmpBrush.setColor(QColor(255, 0, 0));
	}
	else if (color == "Green") {
		tmpBrush.setColor(QColor(0, 255, 0));
	}
	else if (color == "Blue") {
		tmpBrush.setColor(QColor(0, 0, 255));
	}
	QPen tmpPen;
	tmpPen.setColor(Qt::black);
	tmpPen.setWidth(2);
	QGraphicsEllipseItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
	item->setData(0,id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}


QString Circle::type() const
{
	return "Circle";
}

void Circle::draw()
{
}

void Circle::move(QPointF pt)
{
	pos = pt;
}
