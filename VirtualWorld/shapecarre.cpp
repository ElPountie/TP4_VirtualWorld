#include "shape.h"


Carre::Carre() {
	id = current_id++;
	pos = QPointF(-1, -1);
	cote = 0.;
}

Carre::Carre(QPointF p, double cot) : cote(cot){
	id = current_id++;
	pos = p;
}

QGraphicsItem* Carre::getGraphicsItem() const
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
	QGraphicsRectItem* item = new QGraphicsRectItem(pos.x(), pos.y(), cote, cote);
	item->setData(0, id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}

QString Carre::type() const
{
	return "Square";
}

void Carre::draw()
{
}

void Carre::move(QPointF pt)
{
	pos = pt;
}
