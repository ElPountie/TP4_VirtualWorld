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
	QGraphicsItem* item = new QGraphicsRectItem(pos.x(), pos.y(), cote, cote);
	item->setData(0, id);
	return item;
}

QString Carre::type() const
{
	return "Square";
}

void Carre::draw()
{
}