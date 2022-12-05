#include "shape.h"

Rectangle::Rectangle() {
	id = current_id++;
	pos = QPointF(-1, -1);
	hauteur = 0.;
	longeur = 0.;
}

Rectangle::Rectangle(QPointF p, double haut, double lon) : hauteur(haut), longeur(lon) {
	id = current_id++;
	pos= p;
}

QGraphicsItem* Rectangle::getGraphicsItem() const
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
	QGraphicsRectItem* item = new QGraphicsRectItem(pos.x(), pos.y(), longeur, hauteur);
	item->setData(0, id);
	item->setBrush(tmpBrush);
	item->setPen(tmpPen);
	return item;
}

QString Rectangle::type() const
{
	return "Rectangle";
}

void Rectangle::draw()
{
}

void Rectangle::move(QPointF pt)
{
	pos = pt;
}
