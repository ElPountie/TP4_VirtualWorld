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
	QGraphicsItem* item = new QGraphicsRectItem(pos.x(), pos.y(), longeur, hauteur);
	item->setData(0, id);
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
