#include "view.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

PaintView::PaintView( ShapeManager* sm) : QGraphicsScene(), Observer(), shapeManager(sm)
{
}

void PaintView::drawForeground(QPainter* painter, const QRectF& rect)
{
	if (toolbox.isEmpty()) return;

	QGraphicsView* gv = (QGraphicsView*)this->parent();
	
	QPointF p1 = gv->mapToScene(QPoint(10, 10));
	
	painter->save();
	
	painter->setBrush(QBrush(QColor(229,255,204)));
	painter->setPen(Qt::black);
	
	painter->drawRect(p1.x() + 10, p1.y() + 10, toolbox.size() * 7, 20);
	painter->drawText(int(p1.x() + 14), int(p1.y() + 12), toolbox.size() * 10, 20, Qt::AlignLeft, toolbox);

	QColor blue = Qt::blue;
	blue.setAlphaF(0.05);

	if (selectionStarted) {
		painter->setBrush(blue);
		painter->setPen(Qt::blue);
		painter->drawRect(mousePos.x(), mousePos.y(), mouseD.x(), mouseD.y());
	}
	if (selected.size() > 0) {
		painter->setBrush(blue);
		painter->setPen(Qt::blue);
		for (auto item : selected) {
			painter->drawRect(item->boundingRect());
			selected.clear();
		}
	}

	painter->restore();

}

void PaintView::updateModel()
{
	// Clear
	clear();

	// Get models
	QVector<Shape*> shapes = shapeManager->getShapes();

	for (Shape* shape : shapes)
	{
		QGraphicsItem* item = shape->getGraphicsItem();
		item->setAcceptDrops(true);

		addItem(item);
	}

	update();
}

QVector<QGraphicsItem*> PaintView::getSelected()
{
	return selected;
}

void PaintView::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton)
	{
		selected.clear();
		mousePos = mouseEvent->scenePos();
		toolbox = "mousePressEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y());

		selected = this->items(mousePos);
	}
	else if (mouseEvent->button() == Qt::RightButton) {
		mousePos = mouseEvent->scenePos();
		mouseD = QPoint(0, 0);
		toolbox = "mouseMoveEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y());
		bool containItem = false;
		for (auto item : selected) {
			if (item->boundingRect().contains(mousePos)) {
				containItem = true;
				break;
			}
		}

		if (!containItem) {
			selectionStarted = true;
			
		}

	}

	update();
}

void PaintView::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if ( selected.size() > 0 && (mouseEvent->buttons() & Qt::LeftButton))
	{
		QPointF mousePosNew = mouseEvent->scenePos();
		toolbox = "mousePressEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y());
		QPointF mouseD = mousePosNew - mousePos;
		for (QGraphicsItem* item : selected)
		{
			item->moveBy(mouseD.x(), mouseD.y());
			int id = item->data(0).toInt();
			for (auto index : shapeManager->getShapes()) {
				if (index->id == id) {
					index->move(mouseD);
				}
			}
		}
		mousePos = mousePosNew;
	}
	else if ((mouseEvent->buttons() & Qt::RightButton)) {
		QPointF mousePosNew = mouseEvent->scenePos();

		toolbox = "mouseRMoveEvent (" + QString::number(mousePosNew.x()) + "," + QString::number(mousePosNew.y());
		
		mouseD = mousePosNew - mousePos;
	}

	update();
}

void PaintView::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	toolbox = "mouseReleaseEvent";
	if (selected.size() > 0) {

	}
	else if (selectionStarted) {
		selectionStarted = false;
		QRectF rect = QRectF(mousePos.x(), mousePos.y(), mouseD.x(), mouseD.y());
		for (auto item : items()) {
			if (rect.contains(item->boundingRect().center()) && item->parentItem() == nullptr) {
				selected.append(item);
			}
		}
	}

	// Call Controller to modify the model
	/*(new ControllerMoveShape(shapeManager))->control(selected);

	selected.clear();*/

	update();
}

void PaintView::groupShape() {
	Groupe* grp = new Groupe();
	for (QGraphicsItem* item : selected)
	{
		QVariant variant = item->data(0);
		int id = variant.toInt();

		bool selected = shapeManager->selectShape(id);
		if (selected)
		{
			grp->add(shapeManager->getShapes().at(id));
		}
		
	}
	//shapeManager->add(grp); //Dont work
	delete grp;
}

void PaintView::saveSelect() {
	
	save.clear();
	for (QGraphicsItem* item : selected) {
		save.append(item->data(0));
	}
}

void PaintView::setSelect() {

	selected.clear();
	for (QVariant var : save) {
		for (QGraphicsItem* item : items()) {
			if (var == item->data(0)) {
				selected.append(item);
				break;
			}
		}
	}
}